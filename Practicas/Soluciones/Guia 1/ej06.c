/*
Ejercicio 6:

El sistema operativo del punto anterior es extendido con la llamada al sistema
void exec(const char *arg). Esta llamada al sistema reemplaza el programa actual por el código
localizado en el string (char *arg). Implementar una llamada al sistema que tenga el mismo compor-
tamiento que la llamada void system(const char *arg), usando las llamadas al sistema ofrecidas
por el sistema operativo. Nota: Revisar man system, como ayuda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
  char command[100];
  scanf("%[^\n]s", command);

  execl("/bin/sh", "sh", "-c", command, (char *) NULL);

  exit(EXIT_SUCCESS);
}