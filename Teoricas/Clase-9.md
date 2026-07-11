# Seguridad

La seguridad de la información se entiende como la preservación de las siguientes características:
- Confidencialidad
- Integridad
- Disponibilidad

Los sistemas de seguridad suelen tener:
- Sujetos
- Objetos
- Acciones

La idea es decir qué sujetos pueden realizar qué acciones sobre qué objetos. 

Los procesos son sujeto y objeto.

La abtracción mas común es la de usuario (sujeto del SO, que puede ejecutar acciones y a veces es dueño de archivos, procesos, memoria, puertos, etc)

Se pueden agrupar en colecciones de usuarios que son sujetos del sistema de permisos.

Otra abstracción son los roles (pej admin etc)

AAA:
- Authentication: Sos quién decís ser
- Authorization: Qué podés hacer
- Accounting: Dejo registrado qué hiciste

Matriz de control de accesos (sujetos x objetos) con entradas de permisos en cada celda. - **Discretionary Access Control - DAC**

**MAC: Mandatory Access Control:** Para manejar información altamente sensible, cada sujeto tiene un grado. Los objetos creados heredan el grado del último sujeto que los modificó.

d rwx r-x r-x -> En UNIX (owner/group/user)

Ataques por errores de implementación:

- Buffer overflow: Se excede el tamaño que era destinado para el dato y se pisan otros datos. Se debe limitar el contenido que ingresa.

- Control de parámetros: Los parámetros se corren con código maligno y privilegios. Se debe sanitizar la entrada.

- Race condition: Comportamiento anómalo debido a una dependencia crítica inesperada en el timing de los eventos. 

- Malware: Diseñado para llevar a cabo acciones no deseadas y sin el consentimiento explícito del usuario (virus, troyanos, gusanos, bots, ...)

- Denial of service

- Escalado de privilegios