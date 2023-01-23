#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int n = atoi(argv[1]);
	
	// SE CREEAZA UN NOU PROCES, PROCES COPIL, COPIE FIDELA A PROCESULUI APELANT
	pid_t p = fork();
	
	// DACA PROCESUL ARE PID = 0 => PROCES COPIL
	if(p == 0){
		printf("%d:", n);
		
		while(n != 1){
			printf("%d ", n);
			if(n % 2 == 0) n = n/2;
			else n = 3*n + 1;
		}
		
		printf("%d ", n);	
	}
	else{
		// DACA PROCESUL NU ARE PID = 0 => PROCES PARINTE
		// SE APELEAZA WAIT(NULL), I SE AMANA EXECUTIA PANA CAND SE TERMINA EXECUTIA PROCESULUI COPIL
		int q = wait(NULL);
		
		printf("Child %d finished", q);
	}
	
	return 0;
}