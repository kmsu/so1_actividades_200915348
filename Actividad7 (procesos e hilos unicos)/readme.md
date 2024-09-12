|              |                |
|    :---      |      ---:      |
| Nombre: Kevin Martin Samayoa Urizar | Curso: Sistemas Operativos 1 |
| Carnet: 200915348                   | Fecha: 16/09/2024            |

# ACTIVIDAD 7

## Contenido
- [Codigo original](#original)
- [Codigo corregido](#correccion)
- [Explicación](#explicacion)
- [Salida](#resultados)
- [Capturas](#capturas)

---

<a name="original"></a>
## Codigo original

```
    pid_t pid;

    pid = fork()
    if (pid == 0) { /*child process */
        fork();
        thread_create( ...);
    }
    fork();
```

<a name="correccion"></a>
## Codigo corregido

 ```
    void* thread_function(void *arg) {
        printf("H. Hilo creado en el proceso: %d, ID del hilo: %lu\n", getpid(), pthread_self());
    }

    int main() {
        pid_t pid;
        pthread_t thread_id;

        printf("P. Proceso inicial PID: %d\n", getpid());

        pid = fork();
        if (pid == 0) { // Proceso hijo
            printf("P. Proceso hijo PID: %d, padre PID: %d\n", getpid(), getppid());

            pid_t child_pid = fork();
            if (child_pid == 0) { // Hijo del hijo
                printf("P. Hijo del hijo PID: %d, padre PID: %d\n", getpid(), getppid());
            }
            // Esto lo ejecuta el proceso hijo y el hijo del hijo
            pthread_create(&thread_id, NULL, thread_function, NULL);
        } else {
            wait(NULL);
        }

        // El proceso padre original, el primer hijo y el hijo del hijo pasan por aca
        pid = fork();
        if (pid == 0) { // Nuevo proceso hijo
            printf("P. Nuevo proceso hijo PID: %d, padre PID: %d\n", getpid(), getppid());
        } else {
            wait(NULL);
        }

        return 0;
    }
```

<a name="explicacion"></a>
## Explicación

* Para lograr que el codigo funcione, se crea una variable de tipo `pthread_t`, en este caso la llamamos `thread_id` quedando de la siguiente forma `pthread_t thread_id;`.

    Se imprime el proceso inicial, luego con el `fork` se clona y se crea el proceso hijo por lo que hasta ahora existen 2 procesos. Luego se crea otro fork para el hijo con `pid_t child_pid` y con esto se acumulan 3 procesos. y luego se genera 2 hilos por medio de `pthread_create`. Los hilos son por el hijo del hijo y por el hijo.

    Debido a que cada `fork` clona el proceso padre, los tres procesos deben llegar al ultimo fork y este genera un proceso nuevo por cada uno que llego, lo que produce un total de 6 procesos. y los hilos mueren al terminar la ejecucion del metodo `thread_function` por lo que solo se generaron dos hilos en toda la ejecucion. 

* Tomando en cuenta los `fork` utilizados y su comportamiento podemos calcular que se generan tres proceso y al final estos se duplican, generando así un total de 6 procesos.

* Para el número de hilos únicos, solo se cuenta el número de llamadas a `pthread_create()`, y como se puede ver en el código, este se llama dos veces, uno por el proceso "nieto" y otro por el proceso "hijo".

<a name="resultados"></a>
## Resultados

a) ¿Cuántos procesos únicos son creados? R// 6

b) ¿Cuántos hilos únicos son creados? R// 2

<a name="capturas"></a>
## Capturas

Se muestra una captura de la salida del código

![salida](capturas/Salida.png)