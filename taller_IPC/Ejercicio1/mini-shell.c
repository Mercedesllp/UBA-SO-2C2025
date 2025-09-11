#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "constants.h"
#include "mini-shell-parser.c"

enum {READ, WRITE};

static int run(char ***progs, size_t count)
{	
	int r, status;
	int pipes[count - 1][2];

	//Reservo memoria para el arreglo de pids
	//TODO: Guardar el PID de cada proceso hijo creado en children[i]
	pid_t *children = malloc(sizeof(*children) * count);

	//TODO: Pensar cuantos procesos necesito.
	// Hacer una cantidad count de procesos

	//TODO: Pensar cuantos pipes necesito.
	// Una cantidad (count - 1) de pipes

	//TODO: Para cada proceso hijo:
			//1. Redireccionar los file descriptors adecuados al proceso
			//2. Ejecutar el programa correspondiente

	for(int i = 0; i < count; i++){
		pid_t pid = fork();
		if(!pid){
			
			if(pipe(pipes[i]) == -1){
				printf("Error creando el pipe");
				exit(1);
			} 
			
			// Si soy el ultimo hijo me conecto solo al ulimo pipe a escuchar
			if(i == (count -1)){
				dup2(pipes[i - 1][READ], STDOUT_FILENO);
			}

			// Si soy el primer hijo me conecto solo al primer pipe a escribir
			if(i == 0){
				dup2(pipes[i], STDIN_FILENO);
			}

			// Si estoy en el medio escucho al anterior y escribo al proximo
			if((i != 0) && (i != (count-1))){

			}


		} else {
			children[i] = pid;
		}
	}
	

	//Espero a los hijos y verifico el estado que terminaron
	for (int i = 0; i < count; i++) {
		waitpid(children[i], &status, 0);

		if (!WIFEXITED(status)) {
			fprintf(stderr, "proceso %d no terminó correctamente [%d]: ",
			    (int)children[i], WIFSIGNALED(status));
			perror("");
			return -1;
		}
	}
	r = 0;
	free(children);

	return r;
}


int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("El programa recibe como parametro de entrada un string con la linea de comandos a ejecutar. \n"); 
		printf("Por ejemplo ./mini-shell 'ls -a | grep anillo'\n");
		return 0;
	}
	int programs_count;
	char*** programs_with_parameters = parse_input(argv, &programs_count);

	printf("status: %d\n", run(programs_with_parameters, programs_count));

	fflush(stdout);
	fflush(stderr);

	return 0;
}
