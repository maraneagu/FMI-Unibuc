#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void* reverse(void *v){
	char *word = (char*) v;
	
	int length_word = strlen(word);
	
	char *word_reverse = malloc(sizeof(char) * length_word);
	
	for(int i = 0; i < length_word; i++)
		word_reverse[i] = word[length_word-i-1];
		
	return word_reverse;
}

int main(int argc, char **argv){
	pthread_t thread;
	
	char *result;
	
	// INCARCA POINTERUL thread CU NOUL FIR DE EXECUTIE LANSAT PRIN APELUL FUNCTIEI reverse AVAND ARGUMENTELE argv[1]
	if(pthread_create(&thread, NULL, reverse, argv[1])){
		perror(NULL);
		return errno;
	}
	
	// ASTEAPTA FINALIZAREA EXECUTIEI UNUI thread; PUNE LA ADRESA INDICATA REZULTATUL FUNCTIEI reverse
	if(pthread_join(thread, (void**)&result)){
		perror(NULL);
		return errno;
	}
	
	printf("%s\n", result);
	return 0;
}