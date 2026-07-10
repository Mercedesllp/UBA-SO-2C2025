# Clase 4 

**Concurrencia:** No podemos decir a simple vista en qué orden se ejecutarán.

**Paralelismo:** Dos procesos son paralelos si ejecutan literalmente al mismo tiempo.

**Condición de carrera:** La correctitud del programa depende del orden de ejecución de ciertos eventos.

**Operación atómica:** No puede ser interrumpida por el procesador hasta que termine.

**Variable atómica:** Objeto que nos permite realizar operaciones de escritura y lectura de forma atómica. 

**Semáforo:** Tipo abstracto de datos que permite controlar el acceso de múltiples procesos a un recurso común. La única manera de interactuar con el semáforo es mediante las primitivas `wait()` y `signal()`.

**Sección crítica:** Llamamos sección crítica a la parte del programa que accede a memoria compartida, y queremos que ejecute atómicamente.

## Funciones útiles

### getAndInc():
Devuelve el entero atómico sumado 1.

### getAndAdd(unsigned int value): 
Devuelve el entero atómico sumado la cantidad especificada.

### set(unsigned int value): 
Asigna al objeto un valor pasado por parámetro.

### sem(unsigned int value):
Devuelve un nuevo semáforo inicializado en value.

### wait():
Mientras el valor sea menor o igual a 0 se bloquea el proceso esperando un signal. Luego decrementa el valor de `sem`.

### signal(): 
Incrementa en uno el valor del semáforo y despierta a alguno de los procesos que están esperando en ese semáforo.


