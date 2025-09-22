/*
Ejercicio 5:

a) Abraham -> Homero -> Bart
                     -> Lisa
                     -> Maggie

b) Modificar el programa anterior para que cumpla con las siguientes condiciones: 
    1) Homero termine sólo después que terminen Bart, Lisa y Maggie, y 
    2) Abraham termine sólo después que termine Homero.                     
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main(){
  int i, pid;
  pid = fork();
  
  if(pid == -1){
    printf("Hubo un error\n");
    exit(EXIT_FAILURE);
  }

  if(pid != 0){ // Abraham
    printf("Soy Abraham\n");
    wait(NULL); // Espero a que termine Homero
  }

  if(pid == 0){ // Homero
    i = 0;
    
    printf("Soy Homero\n");

    // Creo los hijos y sale del ciclo si estoy en un hijo
    while(i == 0 || ((pid != 0) && (i < 3))){
      pid = fork();
      if(pid == -1){
        printf("Hubo un error\n");
        exit(EXIT_FAILURE);
      }
      i++;
    }

    // Si estoy en algún hijo de Homero le imprimo su nombre
    if((pid == 0) && (i == 1)){
      printf("Soy Bart\n");
    }
    
    if((pid == 0) && (i == 2)){
      printf("Soy Lisa\n");
    }
    
    if((pid == 0) && (i == 3)){
      printf("Soy Maggie\n");
    } 

    // Sigo siendo Homero
    if(pid != 0){
      // Espero a que terminen todos los hijos
      for(int j = 0 ; j < 3; j ++){
        wait(NULL);
      }
    }
  }
  exit(EXIT_SUCCESS);
}
