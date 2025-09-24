# Clase IPC

## Funciones útiles

### int pipe(int descriptores[2]):
Crea un pipe unidireccional, el cual tiene un extremo de escritura, y un extremo de lectura. Genera dos descriptores, representando a los extremos de lectura y escritura respectivamente, y los guarda en descriptores.

### int dup2(int oldfd, int newfd):
Si oldfd y newfd son distintos, primero se elimina la referencia al objeto apuntado por newfd, y luego se apunta newfd al mismo objeto que oldfd. (Re mil contra intuitivos los nombres de los parámetros)

### int open(char* path, int flags, ...):
Abre el archivo indicado por path, retornando un descriptor que apunta a dicho archivo.

### int close(int d): 
Cierra para el proceso actual el descriptor d pasado por parámetro. 

### int read(int d, void *b, size_t s): 
Lee s bytes del archivo apuntado por el descriptor d, y los escribe en el buffer b.  
`read(...) == 0` si estoy en el EOF.

### int write(int d, void *b, size_t s): 
Lee s bytes del buffer b, y los escribe en el archivo apuntado por el descriptor d.

### int printf(char* fmt, ...): 
Función variádica que toma un string de formato fmt y cero o más parámetros adicionales, y escribe el resultado en stdout.

### int socket(int domain, int type, int protocol):
Crea un nuevo socket. Vamos a usar la constante AF_UNIX y el tipo SOCK_STREAM. El tercer parámetro suele ser 0, indicando al SO que use la configuración predeterminada de protocolos.

### int bind(int fd, sockaddr* a, socklen_t len):
Asigna una dirección (nombre o IP y puerto) al socket.

```
struct sockaddr_in {
  short sin_family ;    /* must be AF_INET */
  u_short sin_port ;
  struct in_addr sin_addr ;
  char sin_zero [8];    /* Not used , must be zero */
}
```

### int listen(int fd, int backlog):
Setea al socket del servidor como un socket pasivo que recibirá conexiones entrantes. Se maneja una cola para poder recibir varias conexiones entrantes.

### int accept(int fd, sockaddr* a, socklen_t* len):
Extrae de la cola una solicitud de conexión y establece la comunicación entre los sockets. Se bloquea en caso de no existir conexiones pendientes. Devuelve un nuevo fd para conexión.

### int connect(int fd, sockaddr* a, socklen_t* len):
Conectarse a un socket remoto que debe estar escuchando.

### ssize_t send(int s, void *buf, size_t len, int flags):
Transmitir un mensaje a un socket.

### ssize_t recv(int s, void *buf, size_t len, int flags):
Recibir mensajes de un socket.

### int select(int nfds, fd_set *_Nullable restrict readfds, fd_set *_Nullable restrict writefds, fd_set *_Nullable restrict exceptfds, struct timeval *_Nullable restrict timeout):
Le permite a un programa monitorear varios fds, esperando a que uno o más de uno se ponga en _ready_ para algún tipo de opereación de I/O

### int pselect(int _nfds_, fd_set *_Nullable restrict _readfds_, fd_set *_Nullable restrict _writefds_, fd_set *_Nullable restrict _exceptfds_, const struct timespec *_Nullable restrict _timeout_, const sigset_t *_Nullable restrict _sigmask_):
Esta syscall permite a una aplicación esperar de manera segura hasta que un fd se ponga en _ready_ o hasta que se reciba una señal. Es casi idéntica a `select()` pero con las diferencia de que usa un `struct timespec` el cual tiene segundos y nanoseguntos; no modifica el `timeout`; y tiene una `sigmmask`

### int poll(struct pollfd *fds, nfds_t nfds, int timeout);
Hace algo similar a `select()`, espera a que uno de los fds en el conjunto de fds se ponga _ready_ para hacer I/O. No tiene límite de descriptores de archivo (a diferencia de `select()` que tiene 1024 de límite)

### int fcntl(int fd, int op, ... /* arg */ );
Realiza una de las operaciones determinada por `op` en el `fd` abierto. Se usa para indicar que los sockets del servidor sean no bloqueantes.



