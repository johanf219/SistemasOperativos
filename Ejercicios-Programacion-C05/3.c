#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;

  	pid = fork();

  	if(pid==0)
    {	    
    	printf("Hello (hijo)\n");        
    } 
    else
    {
	    sleep(1);
    	printf("Goodbye (padre)\n");
    }
	return 0;
}

