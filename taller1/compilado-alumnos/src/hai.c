#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

/*
Ejercicio 2:

- Se lanzan 2 procesos (padre e hijo), luego de un segundo se ve que el padre imprime "sup!" y le manda 
	una señal al hijo y luego este imprime "ya va!". Esto lo hace 5 veces y luego ejecuta el programa que 
	se le pasó como parámetro.

- Si, usan señales.

- Lo dicho en el punto 1.
*/

int calls = 0;

void sigurg_handler_child(){
	printf("ya va!\n");
	calls++;
}

void child(int argc, char* argv[]){
	signal(SIGURG, sigurg_handler_child);
	while(calls < 5){};
	kill(getppid(), SIGINT);

	execvp(argv[1], &argv[1]);
}

int main(int argc, char* argv[]) {
  
	signal(SIGCHLD, SIG_DFL);

	int pid = fork();

	if(pid == 0){
		child(argc, argv);
	} else {
		for(int i = 0; i < 5; i++){
			sleep(1);
			printf("sup!\n");
			kill(pid, SIGURG);
		}
		wait(NULL);
	}

	exit(0);
}
