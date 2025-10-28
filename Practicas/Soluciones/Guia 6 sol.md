## Ejercicio 2

```C
semaphore mutex;

int driver_init(){
  sema_init(&mutex, 1);
  OUT(CHRONO_CTRL, CHRONO_RESET);
}

int driver_read(int *data){
  sema_wait(&mutex);
  int time = IN(CHRONO_CURRENT_TIME);
  sema_signal(&mutex);
  copy_to_user(data, &time, sizeof(int));
  return IO_OK;
}

int driver_write(int *data){
  sema_wait(&mutex);
  OUT(CHRONO_CTRL, CHRONO_RESET);
  sema_signal(&mutex);
  return IO_OK;
}
```

## Ejercicio 3

```C
int driver_init(){
  sema_init(&mutex, 1);
  OUT(BTN_STATUS, 0);
}

int driver_read(int *data){
  sema_wait(&mutex);
  while(IN(BTN_STATUS) & 1); // espera a que se presione la tecla
  int btn_pressed = BTN_PRESSED;
  sema_signal(&mutex);
  copy_to_user(data, &btn_pressed, sizeof(int));
  return IO_OK;
}

int driver_write(int *data){
  sema_wait(&mutex);
  int btn_action;
  copy_from_user(&btn_action, data, sizeof(int));
  if(btn_action & 2){ // si se pide resetear, se hace
    OUT(BTN_STATUS, 0);  // no se si se supone que lo deje encendido al que se resetee, 
                         // calculo que no
  }
  sema_signal(&mutex);
  return IO_OK;
}
```