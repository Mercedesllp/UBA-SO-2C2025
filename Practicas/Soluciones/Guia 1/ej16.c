/*
Ejercicio 16:
Implementar el inciso b del ejercicio 11 usando pipes en C. Determinar si el comportamiento del
intercambio de mensajes obtenido es igual al especificado por las funciones bsend y breceive.

RTA:

Necesito las siguientes conexiones:

Padre escribe a Hijo1
Hijo1 escribe a Hijo2
Hijo2 escribe a Padre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

enum{READ,WRITE};
int nro;
pid_t pid_hijo1, pid_hijo2;

void hijo1(){
  pid_t pid_padre = getppid();
  while(nro < 50){
    brecive(pid_padre);
    bsend(pid_hijo2, nro );
    nro += 3;
  }
}

void hijo2(){
  nro = 2;
    pid_t pid_padre = getppid();
    
    while(nro < 50){
      brecive(pid_hijo1);
      bsend(pid_padre, nro);
      nro += 3;
    }
}

void main(){
  nro = 0;
  int pipes[3][2];

  for(int i = 0; i < 3; i++){
    pipe(pipes[i]);
  }

  dup2(pipes[0][WRITE],STD);
  pid_hijo1 = fork();
  

  exit(EXIT_SUCCESS);
}