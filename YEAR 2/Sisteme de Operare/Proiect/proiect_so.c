#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

#define SHM_SIZE 2048
#define NO_OF_PROCESSES 3
#define NO_OF_THREADS 5

float s_de_plata[4][6] = {{17.5, 63.2, 50.0, 104.89, 57.8},
					 {83.2, 64.7, 99.9, 45.4, 5.0},
					 {37.4, 47.5, 67.1, 78.2, 89.2}};
float s_platita[4][6] = {{20.0, 65.0, 50.0, 100.0, 65.0},
					{87.0, 70.0, 100.0, 40.0, 10.0},
					{40.0, 50.0, 100.0, 200.0, 85.0}};

struct casa_de_marcat
{
    float suma;
    
    // MUTEX
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;
    
    // VARIABILE CONDITIONALE
    pthread_cond_t plata;
    pthread_condattr_t condattr;
};


void initializare_casa_de_marcat (struct casa_de_marcat *casa)
{
    casa -> suma = 5000.0;
     
    // MUTEX
    pthread_mutexattr_init(&casa -> mutexattr);
    pthread_mutexattr_setpshared(&casa -> mutexattr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&casa -> mutex, &casa -> mutexattr);
     
    // VARIABILE CONDITIONALE
    pthread_condattr_init(&casa -> condattr);
    pthread_condattr_setpshared(&casa -> condattr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&casa -> plata, &casa -> condattr);
}


void desfiintare_casa_de_marcat (struct casa_de_marcat *casa)
{
    casa -> suma = 0;
     
    // MUTEX
    pthread_mutex_destroy(&casa -> mutex);
     
    // VARIABILE CONDITIONALE
    pthread_cond_destroy(&casa -> plata);
}


void plata (struct casa_de_marcat *casa, float suma_de_plata, float suma_platita)
{
    pthread_mutex_lock(&casa -> mutex);
    
    printf("Suma din casa de marcat: %.2f\n", casa -> suma);
    printf("Suma de platit: %.2f\n", suma_de_plata);
    printf("Suma platita de client: %.2f\n", suma_platita);
     
    if (suma_platita < suma_de_plata)
    {
        printf("EROARE: suma_de_plata insuficienta!\n\n");
    }
    else
    {
        casa -> suma += suma_platita;
        printf("Suma din casa de marcat dupa plata: %.2f\n", casa -> suma);
         
        float rest_datorat;
        rest_datorat = suma_platita - suma_de_plata;
      
	    printf("Rest datorat: %.2f\n", rest_datorat);
	    casa -> suma -= rest_datorat;
	    printf("Suma din casa de marcat dupa rest: %.2f\n\n", casa -> suma);
         
    }
     
    pthread_cond_broadcast(&casa -> plata);
    pthread_mutex_unlock(&casa -> mutex);
}   

struct casa_de_marcat *casa = NULL;
pthread_mutex_t* pmutex = NULL;
pthread_mutexattr_t attrmutex;


void* thread_plata (void* pereche)
{
    float *p = (float*) pereche;
    
    float* suma_de_plata = &p[0];
    float* suma_platita = &p[1];
    plata(casa, *suma_de_plata, *suma_platita);

    return NULL;
}


int main()
{
    // INITALIZARE ATRIBUTE MUTEX
    pthread_mutexattr_init(&attrmutex);
    // DAU PERMISIUNE MUTEXTULUI SA FIE OPERAT DE ORICE PROCES CARE ARE ACCES LA MEMORIA ALOCATA MUTEXULUI
        pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);
    	
    // INITIALIZARE MUTEX
    pmutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(pmutex, &attrmutex);
	
    // INITIALIZARE MEMORIE PARTAJATA
    const char* shm_name = "Monitor";
    int shm_fd = shm_open(shm_name,O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    if (shm_fd < 0)
    {
        perror("EROARE - shm_open!");
        return errno;
    }
     
    // SE DEFINESTE DIMENSIUNEA MEMORIEI PARTAJATE
    if (ftruncate(shm_fd,SHM_SIZE) == -1)
    	{
        	perror("EROARE - ftruncate!");
        	shm_unlink(shm_name);
        	return errno;
    	}
    	
    // SE INCARCA IN SPATIUL PROCESULUI MEMORIA PARTAJATA
    char* shm_ptr = mmap(0, SHM_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) 
    	{
        	perror("EROARE - mmap!");
        	shm_unlink(shm_name);
        	return errno;
    	}
    	
    // INITIALIZARE CASA DE MARCAT
    casa = (struct casa_de_marcat*)malloc(sizeof(struct casa_de_marcat)); 
    initializare_casa_de_marcat(casa);
    
    pid_t pid;
    for (int i = 0; i < NO_OF_PROCESSES; i++)
    {
     	printf("CASA %d:\n\n", i+1);
     	
     	pid = fork();
     	if (pid < 0) 
        	{
            	perror("EROARE: fork!");
            	return errno;
        	}
        else if (pid == 0)
        {
        	pthread_t threads[NO_OF_THREADS];
        	for (int j = 0; j < NO_OF_THREADS; j++)
            {
		        float pereche[2] = {s_de_plata[i][j], s_platita[i][j]};
		         	
		        int plata = pthread_create(&threads[j], NULL, thread_plata, &pereche);
		        if (plata != 0)
		        {
		            perror("EROARE: pthread_create la plata!");
		            return errno;
		        }
		          
		        int join = pthread_join(threads[j], NULL);
		        if (join != 0)
		        {
		            perror("EROARE: pthread_join!");
		            return errno;
		        }
            }
            break;	
        }
        else if (pid > 0) wait(NULL);
    }
     
    // DESFIINTARE CASA DE MARCAT
    desfiintare_casa_de_marcat(casa);
    free(casa);
    
    pthread_mutex_destroy(pmutex);
    munmap(shm_ptr, SHM_SIZE);
    shm_unlink(shm_name);
    	
    return 0;
}