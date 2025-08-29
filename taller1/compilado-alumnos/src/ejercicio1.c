#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

int n;
int numero_maldito;
int children_pids[10] = {0};
bool alive_children[10] = {true};

int generate_random_number(){
  //Funcion para cargar nueva semilla para el numero aleatorio
  srand(time(NULL) ^ getpid());
  return (rand() % n);
}

int get_child_id(int pid){
  int id = 0;
  while((children_pids[id] != pid) && (id < n)){
    id++;
  }
  return id;
}

void sigchld_handler_father(){
  int child_pid = wait(NULL);
  int id = get_child_id(child_pid);

  // Lo marco como muerto al hijo que murió
  alive_children[id] = false;
  printf("Me mori soy %d y tenia el pid %d\n", id, child_pid);
}

void sigterm_handler_child(){
  int bala = generate_random_number();
  if (bala == numero_maldito){

    // Se manda automatico SIGCHLD porque se murió el hijo y el padre sigue
    exit(0);          
  }
}

void child(){
  // Le cambio SIGTERM solo al hijo
  signal(SIGTERM, sigterm_handler_child);
  while(true){};
}

void father(int id){
  if(alive_children[id]){
    kill(children_pids[id], SIGTERM);
    sleep(1);
  }
}

int main(int argc, char const *argv[]){
  int pid;

  n = atoi(argv[1]);
	int rondas = atoi(argv[2]);
	numero_maldito = atoi(argv[3]);
  
  // No esta en rango el nro maldito o el n
  if((numero_maldito < 0) || (numero_maldito >= n) || (n > 10)){
    printf("Le pifeaste en la entrada \n Nro de procesos: %d \n Nro de rondas: %d \n Nro maldito: %d\n", n, rondas, numero_maldito);
    exit(1);
  }

  // Le cambio el handler a SIGCHILD estando solamente en el padre
  signal(SIGCHLD, sigchld_handler_father);

  // Creo todos los procesos
  for(int i = 0; i < n; i++){
    pid = fork();
    
    if(pid == 0){
      child();
    } else {
      children_pids[i] = pid;
      alive_children[i] = true;
    }
  }

  // Acá solo llega el padre, el sleep lo pongo por si hay algun proceso hijo que todavía
  // no pasó por la función child()
  sleep(5);

  for(int k = 0; k < rondas; k++){
    for(int i = 0; i < n; i ++){
      father(i);
    }
  }
  sleep(1);

  // Esto mata a la cantidad de hijos vivos que quedan y me dice cual mata
  for(int id = 0; id < n; id++){
    if(alive_children[id]){
      kill(children_pids[id], SIGKILL);
      printf("Sobreviví y soy %d con el PID: %d \n", id, children_pids[id]);
    }
  }

  printf("Terminó el programa!\n");
  exit(0);
}
