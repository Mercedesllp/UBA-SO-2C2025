# Clase 3

## Conceptos

**Multiprogramación:** Tener procesos corriendo todo el tiempo para maximizar la utilización de la CPU. Cuando un proceso llega, se inicializa su PCB (Process Control Block).  

Muchos procesos (técnicamente sus PCB's) se mantienen en memoria al mismo tiempo. Cuando se libera la CPU se debe elegir otro proceso de la cola de ready y darle CPU. O sea **CPU Scheduling**.

**Programa intensivo en I/O:** Tiene muchas ráfagas de CPU cortitas. Esto sucede porque se la pasa esperando un input o generando un output, lo cual es algo que toma mucho tiempo (todo proceso que requiera comunicarse con el exterior consume mucho más tiempo en espera que uno que no).

**Programa intesivo en CPU:** Suele tener pocas ráfagas de CPU largas.

**Scheduler del SO:** Responsable de seleccionar un proceso de todos los que esten ready y darle CPU para que se procese.

**Nonpreemptive o cooperativo:** Sin desalojo. Una vez el proceso obtiene la CPU se ejecuta hasta liberarla de forma voluntaria (puede haber terminado o pasar a un estado waiting).

**Preemptive o no cooperativo:** Con desalojo. El scheduler puede determinar cuando sacarle la CPU a un proceso.

## Criterios y objetivos

**Uso de CPU: (Maximizar)** Mantener la CPU tan ocupada como sea posible.

**Throughput: (Maximizar)** Cantidad de procesos terminados por unidad de tiempo.

**Turnaround: (Minimizar)** Cuánto le toma a un proceso terminar de ejecutar (tiempo esperando en ready + tiempo ejecutando en CPU + tiempo haciendo I/O). 

**Waiting time: (Minimizar)** Suma de los períodos en ready.

**Response time: (Minimizar)** Tiempo que pasa desde que el proceso es "lanzado" (se encuentra en _idle_ por primera vez) hasta la primera vez que esta running.

## Algoritmos de scheduling

**First-Come, First-Served:**  
Se da el procesador al primer proceso que lo pide. Es _nonpreemptive_.

**Roud-Robin:**  
Sigue la cola ready en orden de llegada de cada proceso, dandole la CPU a cada proceso por un quantum de tiempo.

**Shortest-Job-First:**  
Se asocia a cada proceso el largo de su proxima ráfaga de CPU y se elige para ejecutar el proceso que tenga la menor.  
Si llega un proceso que tiene una ráfaga de CPU menor a lo que le falta al proceso ejecutando actualmente, depende de scheduler y puede hacer las siguentes cosas:
  - Tiene una versión _preemptive_ donde el scheduler desaloja al proceso en ejecución y le da la CPU al nuevo (**shortest-remaining-time-first**).
  
  - Tiene una versión _nonpreemptive_ donde el proceso en ejecución continúa hasta que termina su ráfaga de CPU.

Es lo más optimo respecto al waiting time, pero no podemos saber de antemano la longitud de la próxima ráfaga de CPU.

**Multilevel Queue:**  
- Se mantienen las colas separadas para cada prioridad.

- Se ejecutan primero los procesos en la cola de mayor prioridad.

- Cada cola tiene prioridad absoluta sobre las colas de menor prioridad.

- La prioridad de cada proceso es estática, así que cada proceso vive en siempre la misma cola.

- Se suele usar RR dentro de cada cola, aunque puede variar.

- Se suele aplicar para particionar los procesos que requieren distinto response time.

**Multilevel Feedback Queue:**
- Se permite a los procesos cambiarse de cola.

- Suele separar a los procesos según sus ráfagas de CPU: a mayor uso de CPU, más baja la prioridad.

- Puede implementar _aging_ para evitar _starvation_ de los procesos con menor prioridad.
