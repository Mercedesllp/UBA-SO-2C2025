#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "constants.h"
#include <signal.h>

enum{READ, WRITE};

int generate_random_number(){
	return (rand() % 50);
}

int main(int argc, char **argv)
{	
	//Funcion para cargar nueva semilla para el numero aleatorio
	srand(0);

	int status, pid, n, start, buffer, randNum;
	n = atoi(argv[1]);
	buffer = atoi(argv[2]);
	start = atoi(argv[3]);
	randNum = generate_random_number();

	int pids[n];
	int pipes[n][2];
	int medio_pipe[2];

	if (argc != 4){ printf("Uso: anillo <n> <c> <s> \n"); exit(0);}
    
    printf("Se crearán %i procesos, se enviará el caracter %i desde proceso %i \n", n, buffer, start);
    
		if((start > n) || (n < 3)){
			printf("Error en los parámetros");
		}

		for(int i = 0; i < n; i++){
			pipe(pipes[i]);
		}

		pipe(medio_pipe);

		for(int i = 0; i < n; i++){
			pid = fork();

			if(!pid){
				// Cierro los pipes que no corresponden
				for(int j = 0; j < n; j++){
					if(j == i){

					} else if(j == (i % n)){

					} else {
						
					}
				}
				while((i != start) && (buffer < randNum)){
					write(pipes[i % n][WRITE], buffer+1, sizeof(buffer));
					read(pipes[(i-1) % n][READ], buffer, sizeof(buffer));
				}

				write(medio_pipe[WRITE], buffer, sizeof(buffer));
			} else{
				pids[i] = pid;
			}
		}		    

		read(medio_pipe[READ], buffer, sizeof(buffer));

		for(int i = 0; i < n; i++){
			kill(pids[i], SIGKILL);
			close(pids[i]);
		}
}
