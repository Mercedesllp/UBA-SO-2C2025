# Memoria

La memoria también se comparte, no solo para comunicar procesos, si no también para implementar la multiprogramación.

Swapping: Pasar a disco el espacio de memoria de los procesos que no se están ejecutando.

Problemas de memoria:
- Reubicación (cambio de contexto, swapping)
- Protección (memoria privada de los procesos)
- Manejo del espacio libre (evitando la fragmentación)

Fragmentación: Tener memoria suficiente para atender una solicitud pero no es continua (hay interna de los bloques y externa), compactar es costoso. Soluciones pueden ser bitmap de la memoria en bloques de igual tamaño (no muy usada), lista enlazada es la otra.

Lista enlazada: Cada nodo representa a un proceso o bloque libre, donde figuran el tamaño del bloque y sus límites.

Coalesing: Fusionando

Dónde asignar? First fit - Best fit - Quick fit - Todos fallan por ingenuidad, problemas con fragmentación interna y externa. Otros más complejos son listas segregadas para los tamaños más comunes, Slab allocator para pre-asignar memoria: usados en kernels. Buddy allocator: divide la memoria en potencias de 2, splitting y
coalescing recursivo

Para correr programas que no requieren todo ya y todo el tiempo se podría combinar swapping con virtualización del espacio de direcciones -> **memoria virtual**. Se usa la unidad **Memory Management Unit (MMU)**.

La memo virtual esta dividida en bloques de tamaño fijo llamados páginas y el de memoria física en bloques del mismo tamaño llamados marcos/page frames.

Paginación a demanda: en lugar de cargar el programa entero en memoria física para poder ejecutarlo, cargar sólo las páginas que son necesarias en cada momento.

Se agregó una cache llamada **Translation Lookaside Buffer (TLB)**, mapea directamente páginas a frames, cuando una entrada no está busca en la tabla como siempre, pero además se ubica en el cache, apuntando a que futuros accesos sean más rápidos.

Para la elección de que páginas dejar en memoria hay varios algoritmos:

- FIFO
- Second Chance
- Not recently used: Prioridades para desalojar una página: Las que no fueron ni referenciadas ni modificadas son las más convenientes.
- Last recently used: Asocia a cada página el tiempo de la última vez que se usó. Cuando se tiene que reemplazar una página, se elige la que hace más tiempo que no se usa. 

El mejor algoritmo de reemplazo es el que tenga el menor page fault rate

Qué sucede en un page fault? ...

Cuando el SO se la pasa cambiando páginas de memoria a disco ida y vuelta se dice que se está haciendo **trashing**

Para el problema de protección cada proceso tiene su propia tabla de páginas. No hay forma de acceder a una página de otro, (una manera de hacer esto es que cada proceso tenga su propio espacio de memoria (segmento)).

La alternativa más común es combinar segmentación con paginado.

Para los `fork()` de los procesos se hace copy-on-write.
