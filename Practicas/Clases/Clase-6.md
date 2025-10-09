# Clase 6

**Drivers:** Módulos de software que pueden ser añadidos al SO para manejar dispositivos E/S.

**Controllers:** Componente mecánico y/o electrónico que trabaja como una interfaz entre un dispositivo y el driver.

**E/S síncrona:** La ejecución de la CPU que solicita la E/S, espera por su culminación (de la E/S).

**E/S asíncrona:** Cada E/S procede concurrentemente con la ejecución del CPU que la solicita.

**Método de acceso:** Las 2 técnicas que le permiten al CPU atender eventos que suceden en cualquier momento y no están relacionados a los procesos de ejecución son el **polling** y las **interrupciones**.

**Polling:** Se basa en hacer un ciclo que se la pase preguntando si cambia el status del dispositivo.

**Interrupciones:** Depende de que el hardware soporte interrupciones. El controller pone la señal de interrupción en un bus para cuando quiera que el CPU le de bola. El handler maneja esta señal como le sea indicado.

**Software para E/S:** En el nivel **usuario**, se tienen bibliotecas (por ejemplo **stdio** en C), luego se tienen los módulos de nivel **kernel** los cuales serían los drivers y para el nivel **hardware** se tiene el firmware.

**Handler:** También conocidos como rutinas de servicios de interrupciones (**ISR**) son callback functions que se alojan en el driver que se encargan de manejar la interrupción.

Un driver corre dentro del contexto de un proceso (o sea, puede acceder a sus datos), para punteros que nos pasa el usuario usamos `copy_from_user()` y `copy_to_user()`.

Varios procesos pueden querer **ejecutar el driver a la vez**, por esto se generan horribles race conditions.

Tenemos **primitivas de sincronización** (las cuales se encargan de la sincronización de recursos compartidos por distintos procesos o threads). Estas y las **estructuras de datos** que pueda llegar a necesitar se inicializan al cargar el driver en el kernel.

Un driver no se linkea conta bibliotecas, asi que solo se pueden usar funciones que sean parte del kernel.


## La API de un Driver

Un driver debe **implementar** los siguientes procedimientos para ser cargado por el sistema operativo.

`int driver_init()`  
Invocada durante la carga del SO.

`int driver_open()`  
Invocada al solicitarse un open.

`int driver_close()`  
Invocada al solicitarse un close.

`int driver_read(int *data)`  
Invocada al solicitarse un read.

`int driver_write(int *data)`  
Invocada al solicitarse un write.

`int driver_remove()`  
Invocada durante la descarga del SO

## Funciones de kernel para drivers

Para programar un driver se tienen las siguientes **syscalls**.

`void OUT(int IO_address, int data)`  
Escribe data en el registro de E/S.

`int IN(int IO_address)`  
Devuelve el valor almacenado en el registro de E/S.

`int request_irq(int irq, void *handler)`  
Permite asociar el procedimiento handler a la interrupción IRQ. Devuelve `IRQ_ERROR` si ya está asociada a otro handler.

`int free_irq(int irq)`  
Libera la interrupción IRQ del procedimiento asociado.


