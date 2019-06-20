#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>



int main(int argc, char *argv[]) {
  	     
    int var = 0;
    int i   = 0;
     
    if( argc < 2 )
    {
        printf("Introduzca argumentos");
    }
  
    FILE *texto;     
    texto = fopen(argv[1],"r");       
    //moves the file pointer to the end.
    fseek(texto,0,SEEK_END);
    var = ftell(texto); //pocision 
     
    while( i < var )
    {
        i++;
        fseek(texto,-i,SEEK_END);
        printf("%c",fgetc(texto));
    }
    printf("\n");
    fclose(texto); 
    
    return 0;
}
