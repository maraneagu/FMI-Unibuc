#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	// APELEAZA CREAREA UNUI NOU PROCES
	int p = fork();
	
	// DACA PROCESUL RESPECTIV ARE PID = 0 => PROCES COPIL
	if(p == 0){
		char *argv[] = {"ls", NULL};
		execve("/bin/ls", argv, NULL);
	}
	else{
		// DACA PROCESUL RESPECTIV NU ARE PID = 0 => PROCES PARINTE
		// SE APELEAZA WAIT(NULL), I SE AMANA ACTIVITATEA PANA CAND I SE TERMINA EXECUTIA PROCESULUI COPIL		
		int q = wait(NULL);
		
		printf("%d %d\n", getpid(), p);
		printf("%d finished", q);
	}
	return 0;
}