# Solución

## Parte 1 

### Ejercicio 8:

No son iguales porque el hijo retorna 1,2,3 y el padre muestra 3 veces el 0 debido a que no lo modifica en ningún momento y los procesos no comparten memoria entre si.

## Parte 2

### Ejercicio 11:

**a)**
``` C
void main(){
  int nro;
  pid_t pid = fork();

  if(pid == 0){
    nro = 1;
    pid_t parent_pid = getppid();

    while(true){
      brecive(parent_pid);
      bsend(parent_pid, nro);
      nro += 2;
    }

  } else{
    nro = 0;
    while(true){
      bsend(pid, nro);
      brecive(pid);
      nro += 2;
    }
  }
}
```

**b)**

``` C
void main(){
  int nro;
  pid_t pid_hijo1 = fork();
  pid_t pid_hijo2 = fork();

  // Soy el hijo 1
  if((pid_hijo1 == 0) && (pid_hijo2 != 0)){
    nro = 1;
    pid_t pid_padre = getppid();

    while(nro < 50){
      brecive(pid_padre);
      bsend(pid_hijo2, nro);
      nro += 3;
    }

  } else if (pid_hijo2 == 0){ // Soy el hijo 2
    nro = 2;

    while(nro < 50){
      brecive(pid_hijo1);
      bsend(pid_padre, nro);
      nro += 3;
    }

  } else{ // Soy el padre
    nro = 0;

    while(nro < 50){
      bsend(pid_hijo1, nro);
      brecive(pid_hijo2);
      nro += 3;
    }

    // Espero a que se mueran los hijos
    wait(NULL);
    wait(NULL);
  }

  exit(EXIT_SUCCESS);
}
```

### Ejercicio 12:

**a)**  
La secuencia no es realizable en el sistema operativo debido a que este tiene una cola de mensajes de capacidad cero, o sea, el envio solo se completa cuando el otro proceso esta listo para recibir.  
Queda algo del estilo:

``` C
/*
No se si esto esta bien la verdad.
*/

                  [1]   [2]   [3]
Procesador 1 ->         CMD1        ...
Procesador 2 ->   CMD2        CMD2  ...
```



**b)**  
Si el sistema operativo tuviese capacidad 1 de cola de mensajes ya funcionaría el programa que queremos.

### Ejercicio 13:

**a)**
``` C
pid_derecha y pid_izquierda.
int result;

void proceso_izquierda() {
  result = 0;
  while (true) {
    send(pid_derecha, &result);
    result = cómputo_muy_difícil_1();
  }
}

void proceso_derecha() {
  int left_result;

  while(true) {
    result = cómputo_muy_difícil_2();
    receive(pid_izquierda, &left_result);
    printf("%s %s", left_result, result);
  }
}
```

**b)**  
Creería que el tamaño podría ser 0 al ser que `send()` y `recieve()` no son bloqueantes.

### Ejercicio 14:
Si tengo un proceso que tiene que recibir mensajes de varias fuentes y el cliente antes de continuar ejecutando debe recibir su respuesta (por ejemplo un sistema de loggeo de una página).

### Ejercicio 15:




