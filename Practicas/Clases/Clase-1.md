# Clase 1

## Conceptos

**Programa:** Conjunto de instrucciones diseñadas para realizar una tarea, almacenadas en la memoria.

**Proceso:** Instancia de un programa que está en ejecución, incluyendo su estado y recursos asignados.

**Capabilities:** Los procesos pueden ser privilegiados o no privilegiados. Las capabilities son las unidades resultantes de la división de privilegios tradicionalmente con root, que pueden ser habilitadas o deshabilitadas.

**Subreaper:** Procesos que se pueden autodeclarar como padres de procesos huérfanos que sean descendientes suyos.

**POSIX:** Estándar de mecanismos de interacción con el sistema operativo.

Si no se hace `wait()` del proceso hijo, cuando muere el hijo, el proceso queda en un estado zombie.

El SO hace copias _lazy_. Tanto el padre como el hijo tendrán las mismas páginas físicas hasta que alguna de ellas cambia el contenido, ahí se asigna una página física distinta para el proceso que modifica la memoria (*copy on write*) Sólo se comparten las páginas en modo lectura.

`execve()`: Sustituye la imagen de memoria del programa por la del programa ubicado en filename.

Cada letra luego del prefijo `exec`, nos indica un significado particular de loque hace cada función.

En Linux se puede enviar señales desde un proceso no root a uno root, ya que divide los privilegios tradicionalmente asociados con root en distintas unidades llamadas *capabilities*, que pueden ser habilitadas o deshabilitadas.

`strace`: Herramienta que nos permite generar una traza legible de las llamadas al sistema usadas por un programa dado.

## Funciones útiles

### int fork():
Crea un nuevo proceso copiando el actual. Retorna 0 en el proceso hijo, y el PID del proceso creado en el proceso padre

### void exit(int status):
Termina el proceso actual utilizando el valor de status como el valor de retorno.

### pid_t getppid(void): 
Obtener el PID del padre del proceso actual.

### pid_t getpid(void): 
Conseguir el PID del proceso actual.

### sighandler_t signal(int signum, sighandler_t handler):
Redefinir comportamiento de algunas señales usando funciones void sin parámetros llamados handlers.

### int kill(pid_t pid, int sig):
Envía cualquier señal a cualquier grupo o proceso.

### pid_t wait(int *status): 
Bloquea al padre hasta que el hijo cambie de estado (si no se indica ningún status). El cambio de estado más común es cuando el hijo termina su ejecución.

### pid_t waitpid(pid_t pid, int *status, int options): 
Igual a wait pero espera al proceso correspondiente al pid indicado. 
  
### setcap
Para cambiar las capabilities

### strace
Genera una traza legible de las llamadas al sistema usandas por un programa dado. 

- **-q** -> Omite algunos mensajes ineecesarios.

- **-o \<archivo\>** -> Redirige la salida a \<archivo\>.

- **-f** -> Muestra también la traza de los procesos hijos.

### exit_group()
Termina la ejecución de (y de todos sus threads de haberlos) y no devuelve ningún valor.

---
### Familia exec
Sustituyen la imagen de memoria del programa por la del programa ubicado en filename.

- **l:** Indica que la función es varídica (la aridad es indefinida). Toma una secuencia de argumentos que se le pasa a la imágen a reemplazar. Es útil cuando sabemos de antemano la cantidad de parámetros a utilizar. El último parámetro debe ser NULL.

- **v:** Indica que la función toma un array de punteros a char como los parámetros a usar.

- **e:** Indica que se le pueden pasar variables de entorno tanto de forma varídica como usando un array.

- **p:** Indica que el nombre pasado en file, por defecto lo busque en el pathname que indica la variable de entorno PATH.

#### int execl(const char *pathname, const char \*arg, ... /\*, (char *) NULL */);

#### int execlp(const char *file, const char \*arg, ... /\*, (char *) NULL */);

#### int execle(const char *pathname, const char \*arg, ... /\*, (char *) NULL, char *const envp[] */);

#### int execv(const char *pathname, char *const argv[]);

#### int execvp(const char *file, char *const argv[]);

#### int execvpe(const char *file, char *const argv[], char *const envp[]);

#### int execve(const char *filename, char *const argv[], char *const envp[]):

