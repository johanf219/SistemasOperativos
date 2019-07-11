#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    
    if (pid == 0) 
    {
        printf("Soy el hijo y mi p es %d\n", getpid());
        exit(0);
    }
    else
    {
        int wc;
        waitpid(pid, &wc, 0);
        printf("Soy el padre y mi p es %d\n", getpid());        
    }
}

//En este caso se utiliza la funciòn waitpid para dejar en espera determinados procesos especificos.