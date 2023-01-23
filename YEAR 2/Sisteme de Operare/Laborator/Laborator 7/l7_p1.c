#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

#define MAXRESOURCES 5
#define MAXTHREADS 6
int available_resources = MAXRESOURCES;

pthread_mutex_t mutex;

int size = MAXTHREADS;
int number_threads[MAXTHREADS] = {2, -3, 2, -2, 1, -1};

int decrease_count(int count){
	pthread_mutex_lock(&mutex);
	
	if(count <= MAXRESOURCES){
		available_resources -= count;
		printf("Got %d resources, %d remaining\n", count, available_resources);
	}
	
	pthread_mutex_unlock(&mutex);
	
	return 0;
}

int increase_count(int count){
	pthread_mutex_lock(&mutex);
	
	if(available_resources + count <= MAXRESOURCES){
		available_resources += count;
		printf("Released %d resources, %d remaining\n", count, available_resources);
	}
	
	pthread_mutex_unlock(&mutex);
	
	return 0;
}

void* thread(void *x){
	int count = *((int*) x);
	
	if(count < 0) 
		decrease_count(-count);
	else 
		increase_count(count);
	
	return NULL;
}

int main(){

	// INITIALIZAM MUTEX
	if(pthread_mutex_init(&mutex, NULL)){
		perror(NULL);
		return errno;
	}
	
	printf("MAXRESOURCES=%d\n", MAXRESOURCES);
	
	// ALOCAM SPATIU PENTRU THREAD-URI
	pthread_t* thr = malloc(size * sizeof(pthread_t));
	
	// CREAM THREAD-URILE
	for(int i = 0; i < size; i++)
        pthread_create(&thr[i], NULL, thread, &number_threads[i]);
	
	// MEMORARE REZULTATE DIN THREAD-URI
	for(int i = 0; i < size; i++)
        pthread_join(thr[i], NULL);
      
     // ELIBERAM RESURSELE OCUPATE  
     pthread_mutex_destroy(&mutex);
     
	return 0;
}