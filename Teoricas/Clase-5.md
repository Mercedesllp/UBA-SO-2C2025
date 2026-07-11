# Clase 5

**Concatenación y concurrencia:** Problemas fundamentales (que los problemas dependan entre sí y que se puedan correr varios procesos al mismo tiempo y no saber quien arranca).

**Programación distribuida:** Desarrollo de SW donde los componentes de una aplicación se ejecutan en múltiples computadoras independientes que se comunican entre sí a través de una red.

**Programación Paralela:** Divide un problema complejo en varias tareas más pequeñas y las ejecuta simultáneamente usando múltiples unidades de procesamiento.

**Race condition:** Cuando el resultado depende de la secuencia o el momento en que múltiples procesos o hilos acceden y manipulan un recurso compartido.

**Sección crítica:** Pedazo de código tal que solo hay un proceso a la vez; todo proceso que esté esperando entrar a CRIT va a entrar; ningún proceso fuera de CRIT puede bloquear a otro.

- Solo hay un proceso a la vez en CRIT.
- Todo ṕroceso que esté esperando entrar a CRIT va a entrar.
- Ningún proceso fuera de CRIT puede bloquear a otro.

**TestAndSet (TAS):** Establece atómicamente el valor de una variable entera en 1 (el lugar de memoria que utiliza lo determinás vos en un lugar de la memoria compartida). Es para saber si un proceso puede o no entrar a una sección crítica.

**Busy waiting:** Gastar CPU cuando no es necesario (Poner en un while una función de testandset()).

**sleep():** Syscall que se utiliza para no hacer busy waiting (la solución más básica).

**Modelo Productor-Consumidor:** Ambos procesos (productor/consumidor, o sea, el proceso que esta ejecutando en CRIT y el que lo está esperando) comparten un buffer de tamaño limitado más algunos índices para saber dónde se colocó el último elemento. Esto tiene más problemas.

**Semáforos:** Se inventaron para resolver el anterior modelo. Es para mandar a dormir a algun proceso y poder despertar remotamente a los procesos que sean necesarios.

**Mutex (mutual exclusion):** Variable con dominio binario (puede tener 1 o 0 de valor).

**Deadlock:** Se traban los procesos entre sí esperando al otro.

**Condiciones de Coffman:** condiciones para la existencia de un deadelock:

- **Exclusión mutua:** Un recurso no puede estar asignado a más de un proceso.
- **Hold and wait:** Los procesos que ya tienen algún recurso pueden solicitar otro.
- **No preemption:** No hay mecanismo compulsivo para quitarle los
recursos a un proceso.
- **Espera circular:** Tiene que haber un ciclo de N $\geq$ 2 procesos, tal que Pi espera un recurso que tiene Pi+1.