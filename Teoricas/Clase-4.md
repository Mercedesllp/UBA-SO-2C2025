# Scheduling

Ecuanimidad (Fairness): Cada proceso reciba una dosis justa de CPU.

Eficiencia: tratar de que la CPU esté ocupada todo el tiempo.

Carga del sistema: minimizar la cant. de procesos listos que están esperando CPU.

Tiempo de respuesta: minimizar el tiempo de respuesta percibido por los usuarios interactivos.

Latencia: minimizar el tiempo requerido para que un proceso empiece a dar resultados.

Tiempo de ejecución: minimizar el tiempo total que le toma a un proceso ejecutar completamente.

Rendimiento (throughput): maximizar el número de procesos terminados por unidad de tiempo. Para minimizzarlo se podría ver de implementear SJF (Shortest Job First)

Liberación de recursos: hacer que terminen cuanto antes los procesos que tiene reservados más recursos.

Scheduler con desalojo/preemptive/apropiativo: Se vale de la interrupción del clock para decidir si el proceso actual debe seguir ejecutándose o le toca a otro.

Scheduler cooperativo:  Sin desalojo. Una vez que un proceso obtiene la CPU, ejecuta hasta liberarla de forma voluntaria