
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0) // Hijo
    {
        int wc = wait(NULL);
        printf("Soy el hijo\n");
        printf("wait() %d\n", wc);
    }
    else
    {
        wait(NULL); //Padre
    }   
}
//El algoritmo retorna -1 en el wait porque no existe un otro proceso o hijo dentro del proceso hijo