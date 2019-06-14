#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

/**
Este programa en C debe imprimir lo siguiente:

Soy el hijo y mi identificador es 34567
Soy el padre y mi identificar es 34566 y el de mi hijo es 34567
*/

int main(int argc, char** argv)
{
  pid_t pid;

  pid= fork();
  if(pid==0)
  {
    sleep(3);
    printf("Soy el hijo y mi identificador es:%d\n ",(int)getpid()); 
  } // 0 -> hijo 
  else
  {
     int status;
     pid_t pid2;
     printf("Soy el padre y mi identificar es:%d y el de mi hijo es:%d\n "
     ,(int)getpid(),pid);
     pid2 = wait(NULL);
     printf("Termino mi hijo %d\n ", pid2);
  }
}
