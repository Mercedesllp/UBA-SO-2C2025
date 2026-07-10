# Clase 5

El **sistema operativo** es responsable de:

  - Saber qué partes de la memoria están en uso.
  - Saber qué proceso usa cada parte de la memoria.
  - Asignar y liberar espacios de memoria.

**Memory managment Unit (MMU):** Se ocupa de la traducción de direcciones virtuales a físicas. Sus objetivos son:

  - **Facilitar el uso** de la memoria: los programadores no tienen que gestionar manualmente la ubicación de código y datos.
  - **Transparencia**: los programas no saben que su memoria es virtual.
  - **Eficiencia**: traducción rápida con poco overhead.
  - **Protección**: los procesos no pueden dañarse entre sí.

El **espacio de direcciones** (es una vista privada de la memoria) de cada proceso se conforma de **code, stack, heap y data**.

Hay distintas maneras para el manejo de las traducciones de memoria virtual a fisica:
  - **Base y límite**: La CPU tiene un único set de registros base y límite. Durante un contexto switch, el SO debe cargar los valores del nuevo proceso.
  - **Segmentación**: Cada espacio de direcciones se separa en segmentos lógicos de distinto tamaño.
  - **Paginación**: La memoria virtual se divide en tamaño fijo (4kb comunmente). La memoria física se divide en marcos de páginas del mismo tamaño. Como cada página se mapea de manera independiente no es necesario que sea contigua la memoria asignada. Evita la fragmentación externa.
  
**Fragmentación interna:** Si se asigna memoria de más, la memoria no utilizada es desperdiciada ya que no pueden usarla otros procesos.

**Segmentation fault:** Se genera al intentar acceder a memoria por fuera del segmento válido.

**Fragmentación externa:** Hay suficiente espacio libre pero está dispersa, dificultando asignar segmentos grandes de memoria.

En C se provee una **memory API** que permite a los programadores pedir y liberar memoria.

**Memoria stack:** 

  - Es administrada implícitamente por el compilador. 
  - Se reserva memoria para variables locales dentro de las funciones.
  - Se libera automáticamente al retornar.
  - Es de tamaño limitado y no puede usarse para estructuras dinámicas.

**Memoria Heap:**

  - El programador reserva y libera memoria manualmente.
  - `malloc()` para reservar.
  - `free()` para liberar.


El **Sistema Operativo** debe:

  - Administrar eficientemente la memoria no utilizada.
  - Manejar los pedidos de asignación y liberación.
  - Evitar y reducir la fragmentación.

**Splitting:** Si un requerimiento de memoria es menor que una porción de memoria libre, se retorna la primera parte y se mantiene el resto en la free list.

**Coalescing:** Cuando la memoria es liberada, se verifica si las porciones aledañas también están libres, y en ese caso se mergean en una única porción más grande. (reduce la fragmentación externa).

Al asignar memoria se suele almacenar un header con el tamaño del bloque y alguna metadata más.

**Paginación a demanda:** en lugar de cargar el programa entero en memoria física para poder ejecutarlo, cargar **sólo las páginas que son necesarias en cada momento**.

**Dirty bit:** Se usa para indicar que una página fue modificada y que hay que bajarla a disco.

**Thrashing:** Lo que hace un proceso que pasa más tiempo cargando y descargando páginas que ejecutando. Para mitigar algunos SO corren un proceso **Out-Of-Memory killer** (ver)

**Localidad:** Conjunto de páginas que se usan activamente al mismo tiempo. Esta es clave para el diseño inteligente de reemplazos de páginas. 

**Localidad temporal:** las páginas más recientemente usadas tienden a ser reusadas en el corto plazo.

**Localidad espacial:** las direcciones cercanas entre sí suelen accederse juntas.

## Funciones útiles

### void* malloc(_size_t_ size)

### void* calloc(_size_t_ nmemb, _size_t_ size)

### void* realloc(_void* \_Nullable_ ptr, _size_t_ size)

### void free (_void* \_Nullable_ ptr)
