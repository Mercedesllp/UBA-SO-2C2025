# IPC

File Descriptor: Índices de una tabla que indica los archivos abiertos por el proceso.

Los fd se heredan de un proceso padre a hijo al usar `fork()` y se mantienen en la llamada a `execve`

Pipes: Son un canal que se puede interpretar como un byte stream

Socket: Interfaz de comunicación entre procesos que permite el intercambio de datos. Hay syscalls para manejarlos de manera homogénea independientemente del tipo.

Sockets Unix: Comunicación rápida y eficiente dentro de un sistema. Usan archivos en el sistema de archivos como puntos de conexión. No requuieren configuración de red.

Sockets de red: Usan direcciones IP y puertos. Permiten comunicación entre diferentes máquinas. Mayor latencia y overhead por protocolos de red.

