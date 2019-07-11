#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0) // child process
    {
        printf("Soy el hijo\n");
        close(STDOUT_FILENO);
        printf("Escribiendo despues de cerrar??\n");
    }
    else
    {
        wait(NULL);
        printf("soy el padre\n");
    }
}

//cuando el hijo hace close(STDOUT_FILENO); no puede imprimir nada pues esta cerrando su propia salida.