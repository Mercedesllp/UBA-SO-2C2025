/*
Ejercicio 15:
Escribir el código de un programa que se comporte de la misma manera que la ejecución del
comando “ls -al | wc -l” en una shell. No está permitido utilizar la función system, y cada uno
de los programas involucrados en la ejecución del comando deberá ejecutarse como un subproceso.

RTA:
No creo que lo que hice era la idea de lo que habia que hacer

*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
  char * command = "ls -al | wc -l";
  pid_t pid = fork();
  
  if(pid == 0){
    execl("/bin/sh", "sh", "-c", command, (char*) NULL);
  } else {
    wait(NULL);
  }

  exit(EXIT_SUCCESS);
}