#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;    
    int x = 100;
    printf("X es: %d\n",x);
  	pid = fork();
  	if(pid==0)
    {
    printf("Soy el hijo y mi identificador es %d\n",(int) getpid());  
    x = x+1;
    printf("X en el proceso hijo es %d\n",x);}
    else
    {
	wait(NULL);
    printf("Soy el padre,y mi identificador es %d y el de mi hijo es %d\n",(int)getpid(),pid);
      x = x-1;
      printf("X en el proceso hijo es %d\n",x);
    }
	return 0;
}

