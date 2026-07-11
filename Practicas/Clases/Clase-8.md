# Clase 8

**Bugs de seguridad** son aquellos que exponen más funcionalidad o distinta al usuario que la que el programa dice tener.

**Exploit:** Fragmento de código que utiliza la funcionalidad oculta del programa vulnerable.

Confidencialidad: Garantizar que la información esté disponible solo para personas autorizadas y protegerla de accesos no autorizados.

Integridad: Asegurar que los datos se mantengan precisos y sin alteraciones no autorizadas.

Disponibilidad: Mantener la información accesible y disponible para usuarios autorizados, evitando interrupciones no planificadas.

- Format String: Input no sanitizado, escalamiento de privilegios, pisada de pila o heap.

- Enviroment Variables: No se provee el path completo a la aplicación que se quiere ejecutar, escalamiento de privilegios, cambio de path.

- Buffer overflow: Se ingresa input de usuario directamente sobre un buffer de tamaño limitado, permitiendo que haya overflow.

- Integer overflow: El entero es otro número al pasarse de su rango de representación.

- Escalado de privilegio/Broken Access Control: Si los permisos están mal puede abrir la puerta a ataques.

- Denial of service: Por ejemplo el uso de Fork bombs

Algunos SO implementan uno o más mecanismos para protegerse:

- DEP (Data Execution Prevention): Ninguna región de memoria es escribible y ejecutable
- ASLR (Address Space Layout Randomization): Modifica de manera aleatoria la dirección base de regiones importantes de memoria entre las diferentes ejecuciones de un proceso (impide ataque con instrucciones hardcodeadas).
- Stack Canaries (también conocido como Stack Guards or Stack
Cookies): A nivel compilador se coloca un valor en la pila luego de crear el stack frame, antes de retornar verifica si el valor está bien.
