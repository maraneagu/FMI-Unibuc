#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int matrix_1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int matrix_2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
int matrix_result[3][3];

void* compute(void* position){
	int i = ((int*) position)[0];
	int j = ((int*) position)[1];
	
	matrix_result[i][j] = 0;
	
	for(int k = 0; k < 3; k++)
		matrix_result[i][j] += matrix_1[i][k]*matrix_2[k][j];
}

int main(){
	pthread_t thread[9];
	int thread_id = 0;
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){
			char *result;
			
			int *index = malloc(2*sizeof(int));
			index[0] = i;
			index[1] = j;
			
			// SE INCARCA IN thread[thread_id] CU UN NOU FIR DE EXECUTIE LANSAT PRIN APELAREA FUNCTIEI compute CU ARGUMENTELE index
			if(pthread_create(&thread[thread_id++], NULL, compute, index)){
				perror(NULL);
				return errno;
			}
	
			// ASTEAPTA FINALIZAREA EXECUTIEI UNUI thread; PUNE LA ADRESA INDICATA result, REZULTATUL FUNCTIEI compute cu ARGUMENTELE index
			if(pthread_join(thread[thread_id], (void**)&result)){
				perror(NULL);
				return errno;
			}
		}
			
	return 0;
}