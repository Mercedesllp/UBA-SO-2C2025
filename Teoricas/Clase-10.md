# Virtualización

Def: Es la posibilidad de que un conjunto de recursos físicos se vean como varias copias de recursos lógicos.

**Simulación:** En el sistema anfitrión se construye una variable de estado artificial que representa al sistema huésped. Se lee cada instrucción y se modifica el estado como si ésta ejecutase realmente. Puede ser muy lento.

**Emulación de HW:** El sistema emulado se ejecuta realmente en la CPU del anfitrión. Se emulan componentes de HW.

Virtualización asistida por HW:
- Nace para evitar los problemas de:  
  - Ring aliasing: Programas para modo kernel ejecutados en modo usuario.
  - Address-space compression: Que la máquina virtual no pise la memoria del propio emulador. Desde el punto de vista del anfitrión sos un único proceso.
  - Non-faulting access to rpivileged state: Algunas instrucciones privilegiadas generan un trap cuando se ejecultan sin permiso.
  - Interrupt virtualization: Hay que simularle las interrupciones la SO huésped.
  - Access to hidden state: Parte del estado del procesador no es consultable por SW.
  - Ring compression: No hay protección entre el kernel y programas de usuario.
  - Frequent access to privileged resources: Cuello de botella en recursos accedidos frecuentemente.

- Para solucionar esto en Intel se agregaron al procesador las extenciones VT-x (VMX root, VMX non-root). Se agrega la Virtual Machine Control Structure (en memoria) tiene los estados de ambos y campos de control para ver qué interrupciónes, puertos de E/S recibe el huésped.

Contenedores: No son una virtualización completa. Cada imagen se construye en capas (base, dependencias, app, configuraciones). Los componentes fundamentales son:
- Namespaces: (Aislamiento) Proveen aislamiento entre procesos.
- Cgroups: Permiten limitar y contabilizar recursos.
- Layered FS: Modelo donde se apilan capas de solo lectura y una capa superior de escritura. Cada capa representa cambios respecto a la anterior.

Una imágen de Docker es una plantilla inmutable usada para crear contenedores. Contiene todo lo necesario para ejecutar una aplicación (código, dependencias, herramientas, bibliotecas y configuración). Son capas que se apilan sobre una capa base común.


OCI: Open Cantainer Initiative: Estándar abierto para contenedores. Define dos especificaciones principales:
- OCI Image Spec
- OCI Runtime Spec

Orquestación de aplicaciones contenerizadas:
- Kubernetes: Plataforma de código abierto para automatizar la implementación, el escalado y la administración de alplicaciones en contenedores.
- Openshift (y OKD): Usa Kubernetes de base, agrega restricciones de seguridad por defecto, interfaz web más completa, manejo de roles, facilidades para el desarrollador.

Cloud

Trusted Excecution Enviroment: Área protegida dentro de un CPU, ejecuta código y protege datos confidenciales.