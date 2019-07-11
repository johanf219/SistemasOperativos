#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    struct stat sb;
    int archivo = open("archivo.txt", O_CREAT | O_RDWR, S_IRWXU);
    
    int rc = fork();

    if (rc == 0)
    {
        const char * hijo = "Hola soy el hijo\n";
        sleep(1);
        printf("Hijo escribiendo... \n");        
        write(archivo, hijo , strlen(hijo));
        exit(0);
    }
    else if (rc > 0)
    {
        wait(NULL);
        const char * parent_msg = "Hola soy el padre\n";
        sleep(1);
        printf("Padre escribiendo...\n");
        write(archivo, parent_msg, strlen(parent_msg));
    }
    sleep(1);
    printf("Revise archivo.txt \n");

}
