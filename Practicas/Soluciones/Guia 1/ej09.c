/*
Ejercicio 9:
Dado un programa de dos procesos, padre e hijo, se quiere tener el siguiente comportamiento:
Uno de los dos procesos debe escribir en pantalla ping y su número de PID. Automáticamente el otro
proceso debe escribir pong con su número de PID. Se quiere repetir este comportamiento 3 veces.
Luego de esto, se desea preguntar al usuario si quiere finalizar la ejecución o no. En caso que conteste
que si, el padre debe terminar con la ejecución de su hijo y finalizar. En caso que se conteste que no,
se vuelve a repetir el proceso antes dicho.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>

int vecesRespondidas = 0;
int pid;

// Recibe la señal y le manda al padre que le responda
void sigusr1_handler(){
  printf("ping! soy el pid [%d]\n", getpid());
  kill(getppid(), SIGUSR2);
}

void sigusr2_handler(){
  char yesOrNo[10];
  vecesRespondidas ++;
  
  printf("pong! soy el pid [%d]\n", getpid());
  
  if(vecesRespondidas == 3){
    printf("Querés continuar la ejecución?[y/n]\n");
    scanf("%s", yesOrNo);
    if(strcmp(yesOrNo, "y")){
      kill(pid, SIGKILL);
      waitpid(pid, NULL, 0);
      exit(EXIT_SUCCESS);
    }
    vecesRespondidas = 0;
  }
  kill(pid, SIGUSR1);
}

void main(){
  // Cambio el handler de SIGUSR1 y SIGUSR2
  signal(SIGUSR1, sigusr1_handler);
  signal(SIGUSR2, sigusr2_handler);
  
  pid = fork();
  
  if(pid == 0){
    // Restauro el handler de SIGUSR2 del hijo
    signal(SIGUSR2, SIG_DFL);
    while(true);
  } 
  
  // Restauro el handler de SIGUSR1 en el padre
  signal(SIGUSR1, SIG_DFL);
  sleep(3);
  kill(pid, SIGUSR1);

  while(true);
}
