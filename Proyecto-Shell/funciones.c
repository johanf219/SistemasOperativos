#include <stdio.h>
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<linux/limits.h>
#include<pwd.h>
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 

char SHELL_PATH[PATH_MAX]; 
char* buffer;
char* user;
char* aux;

void clearShell(){
	printf("\033[H\033[J");
}

void initShell(){
	clearShell();
	printf("...........(0 0)\n");
	printf(".----oOO-- (_)-----.\n");
	printf("╔══════════════════════╗\n");
	printf("║ Bienvenido a la Shell║\n");
	printf("╚══════════════════════╝\n");
	printf("'-----------------oOO\n");
	printf(".........|__|__|\n");
	printf(".......... || ||\n");
	printf("....... ooO Ooo\n");
	sleep(1);
	clearShell();
	user = getenv("USER");
	aux = " ~ ";
	strcat(user, aux);
}

void dirShell(){
	DIR *dir;
 	struct dirent *directorio;
	dir=opendir(".");
	while((directorio=readdir(dir))!=NULL){
		printf("%s\n ",directorio->d_name);	
	}
	
}

void strDigitado(char* command){
	buffer=readline(user);
	if(strlen(command)!=0){
		add_history(command);
		strcpy(command, buffer);
	}
}

void cdShell(){
	char command[100];
	char* token;
	strcpy(command,buffer);
	token = strtok(command, " ");
	token = strtok(NULL, " ");
	if(token == NULL){
		chdir("/home/");
	} else { chdir(token); }
}

void environShell(){
	getcwd(SHELL_PATH,sizeof(SHELL_PATH));
	printf("User: %s\n Dir: %s\n",user,SHELL_PATH);
}

void pauseShell(){
	int input;
	int aux=10;
	printf("Presione Enter para salir del modo pausa \n");
	while(1){
		input=getchar();
		if(aux==10 && input==10){
			break;
		} else {aux = input;}
	}
}

void echoShell(){
}

void helpShell(){
	printf( "cd  Volver al directorio /home/ \n"
		"dir  Listar documentos dentro del directorio \n"
		"pause  Puasar la Shell \n"
		"exit  Salir de la Shell \n"
		"clear  Limpiar la Shell \n"
		"environ Listar user y directorio \n"
		"echo  Mostrar salida de funcion \n");
}

void otherCommand(){
	char command[10];
	char *buffer2[20];
	char* token;
	int i=0;
	token=strtok(buffer, " ");
	if(token != NULL) strcpy(command, token);
	while(token != NULL){
		buffer2[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	
	pid_t pid;
	int status;
	pid=fork();
	if(pid<0) printf("Error creando el hijo");
	else if(pid == 0){
		if(execvp(command, buffer2) < 0) {
			printf("Error en el comando: %s\n",command);
			exit(1);
		}
	} else { wait(NULL);}
}

int executeCommand(){
	int commands=8, option;
	char* listOfCommands[commands];
	char aux2[100];
	char* aux;
	strcpy(aux2, buffer);	
	aux = strtok(aux2, " ");	

	listOfCommands[0] = "cd";
	listOfCommands[1] = "dir";
	listOfCommands[2] = "pause";
	listOfCommands[3] = "exit";
	listOfCommands[4] = "clear";
	listOfCommands[5] = "environ";
	listOfCommands[6] = "echo";
	listOfCommands[7] = "help";	

	for(int i=0; i<commands; i++){
		if(strcmp(aux,listOfCommands[i])==0){
			option=i+1;
			break;
		}
	}
	
	switch(option){
	case 1:
		cdShell();
		return 1;
	
	case 2:
		dirShell();
		return 1;
	
	case 3:
		pauseShell();
		return 1;
		
	case 4:
		exit(0);
		
	case 5:
		clearShell();
		return 1;
	
	case 6:
		environShell();
		return 1;
		
	case 7:
		echoShell();

	case 8:
		helpShell();
		return 1;
		
	default:
		otherCommand();
		//printf("Comando no encontrado \n");
		return 1;
	}
	
	return 0;
}










