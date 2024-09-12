#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    pid_t pid;

    /* fork a child process */
    pid = fork();

    if (pid < 0) { /* error occured */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0) { /* child process */
        execlp("/bin/ls", "ls", NULL);
        _exit(0); //Esto asegura terminar el proceso hijo (se convierte en zombie si el padre no lo recoje)
    }
    else { /* parent process */
        printf("Proceso padre, el proceso hijo ya termino pero aun no lo recojere\n");

        //dormir para observar el proceso zombi
        sleep(60);

        /* parent will wait for the child to complete */ //el proceso padre finalmente recoje al proceso hijo
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}