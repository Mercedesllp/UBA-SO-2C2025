# Procesos

Cuando el SO comienza, lanza un proceso que se suele llamar `init` o `systemd`.

- `fork()` crea un proceso exactamente igual al actual. Retorna el pid del hijo para el padre y 0 en el hijo.

preemption: Cuando se acaba el quantum, le toca el turno al siguiente proceso.

PCB: Process Control Block - Donde se encuenta el IP y otras cosas del proceso.

Las syscalls proveen una interfaz a los servicios brindados por el sistema operativo: *la API (Application Programming Interface)* del SO.

wrapper functions: Permiten interactuar con el sistema con mayor portabilidad y sencillez. La biblioteca estándar de C incluye funciones que no son syscalls, pero las utilizan para funcionar (pej: `printf()` invoca a la syscall `write()`).

Busy waiting: El proceso no libera la CPU. Un único proceso de ejecución a la vez.

Polling: El proceso libera la CPU, pero todavía recibe un quantum que desperdicia hasta que la E/S esté terminada.

Interrupciones: El SO no le otorga más quanta al proceso hasta que su E/S esté lista y se comunica mediante una interrupción.

Multiprogramación: Capacidad de un SO de tener varios procesos en ejecución.

Multiprocesamiento: Tipo de procesamiento que sucede en los multiprocesadores.

Multiprogramación desde el código:
- Bloquante: Hago syscall, para cuando recibo el control, la E/S terminó. Mientras, me bloqueo.
- No bloqueante: Hago la syscall, que retorna en seguida. Puedo seguir haciendo otras cosas, pero debo enterarme de alguna forma si la E/S terminó.

carga del sistema = cantidad de procesos listos

tabla de procesos = lista de PCBs

señales = mecanismo que incorporan los sistemas operativos POSIX que permiten notificar a un proceso la ocurrencia de un evento.




