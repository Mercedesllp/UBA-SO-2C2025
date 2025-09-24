/*
Ejercicio 16:
Implementar el inciso b del ejercicio 11 usando pipes en C. Determinar si el comportamiento del
intercambio de mensajes obtenido es igual al especificado por las funciones bsend y breceive.
*/

#include <stdlib.h>
#include <sys/types.h>

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
  pid_hijo1 = fork();
  
  // Soy el hijo 1
  if(pid_hijo1 == 0){
    hijo1();
  } else{ // Soy el padre
    pid_hijo2 = fork();

    if(pid_hijo2 == 0){
      hijo2();
    } else{
      while(nro < 50){
        bsend(pid_hijo1, nro);
        brecive(pid_hijo2);
        nro += 3;
      }

      // Espero a que se mueran los hijos
      wait(NULL);
      wait(NULL);
    }
  }

  exit(EXIT_SUCCESS);
}