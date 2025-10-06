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

Hay distintas maneras para el manejo de las traducciones:
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


## Funciones útiles

### void* malloc(size_t size)

### calloc(size_t nmemb, size_t size)

### realloc
