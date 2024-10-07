|              |                |
|    :---      |      ---:      |
| Nombre: Kevin Martin Samayoa Urizar | Curso: Sistemas Operativos 1 |
| Carnet: 200915348                   | Fecha: 06/10/2024            |

# ACTIVIDAD 7

## Completely Fair Scheduler (CFS)

Es el planificado por defecto del kernel de Linux. Está diseñado para mejorar el rendimiento y la distribucion de tiempo de CPU de manera proporcional y balanceada entre los procesos. 

## Caracteristicas principales

* Equidad en la asignación del CPU: El objetivo principal es garantizar que cada proceso reciba una cantidad justa de tiempo de CPU, proporcional a su prioridad.

* Basado en tiempo virtual: En lugar de usar una cola de prioridad para los procesos, el CFS utiliza un "tiempo virtual" para calcular el tiempo de uso de cada proceso y compararlo con el de los demas. El proceso con menos tiempo virtual obtiene más acceso al CPU.

* Árbol rojo-negro: Organiza los proceso en una estructura con este nombre, para seleccionar el siguiente proceso a ejecutar en un tiempo logaritmico.
![imagen](arbol.svg)

* Prioridades ponderadas: Procesos con prioridad más alta obtiene mas tiempo de CPU (comparado con los procesos de baja prioridad)

* Sin intervalos de tiempo fijo: Distribuye el tiempo de forma dinámica en funcion del tiempo que ya han recibido los procesos. 

## Funcionamiento 

1. Carta de procesos: Carga los procesos al árbol rojo-negro y organizados de acuerdo al tiempo virtual que han utilizado.

2. Repartición de tiempo: Cada vez que un proceso se ejecuta, su tiempo real de CPU se convierte en tiempo virtual, ponderado según su prioridad. Luego el proceso se reinserta en el árbol y el proceso con menos tiempo virtual se ejecuta.

3. Calculadora de tiempo virtual: Ajusta dinámicamente el tiempo máximo que un proceso debería esperar antes de que se vuelva a asignar CPU en función de la carga del sistema y numero de procesos.

4. Grupo de tareas: Agrupa tareas en "task groups" y distribuye el tiempo entre los grupos, proporcionando una forma de control sobre el uso de CPU en entornos multiusuario. 