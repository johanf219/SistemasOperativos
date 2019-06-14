#include<unistd.h>
#include "solucion.h"
#include <stdio.h>

int main(int argc, char** argv)
{
  pid_t pid;
  int valorpadre;
  int x = 20;

  pid = fork();
  if(pid>0)
  {
    int valor=(int)leerEntero("archivo");
    valorpadre = valor*100;
    printf("El valor es:%d\n ",valorpadre);
  }
  else
  {
    printf("fibonacci(%d) = ",x);
    x = fibonacci(x);
    printf("%d\n",x);
    guardarEntero("archivo",x);

    return 0;
  }
}
