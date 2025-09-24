/*
Ejercicio 15:


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