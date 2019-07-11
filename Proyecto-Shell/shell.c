#include "funciones.c"
#define maxCom 100 //numero máximo de comandos soportado


int main(){
	char inputString[maxCom];
	initShell();
	
	while(1){
		strDigitado(inputString);
		executeCommand();
	}
	return 0;
}
