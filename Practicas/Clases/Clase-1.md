# Clase 1

## Funciones útiles

### int fork():
Crea un nuevo proceso copiando el actual. Retorna 0 en el proceso hijo, y el PID del proceso creado en el proceso padre

### void exit(int status):
Termina el proceso actual utilizando el valor de status como el valor de retorno.

### pid t getppid(void): 
Obtener el PID del padre del proceso actual.

### pid t getpid(void): 
Conseguir el PID del proceso actual.

### sighandler_t signal(int signum, sighandler_t handler);
Redefinir comportamiento de algunas señales usando funciones void sin parámetros llamados handlers.

### int kill(pid_t pid, int sig);
Envía cualquier señal a cualquier grupo o proceso.

### pid t wait(int *status): 
Bloquea al padre hasta que el hijo cambie de estado (si no se indica ningún status). El cambio de estado más común es cuando el hijo termina su ejecución.

### pid t waitpid(pid t pid, int *status, int options): 
Igual a wait pero espera al proceso correspondiente al pid indicado. 

### int execve(const char *filename, char *const argv[], char *const envp[]):
Sustituye la imagen de memoria del programa por la del programa ubicado en filename.

