/*
Ejercicio 10:
Leer el strace y estimar que hace.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

  if(fork() == 0){
    printf("Soy Julieta\n");
    sleep(1);
    if(fork() == 0){
      printf("Soy Jennifer\n");
      sleep(1);
    }

  } else{
    printf("Soy Juan\n");
    sleep(1);
    wait(NULL);
    if(fork() == 0){
      printf("Soy Jorge\n");
      sleep(1);
    }
  }

  exit(EXIT_SUCCESS);
}