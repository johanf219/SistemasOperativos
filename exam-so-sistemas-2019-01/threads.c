#include "mycommon.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include <time.h>

puerta la_puerta;
volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
     
    for (i = 0; i < loops; i++) {
	cerrar_puerta(la_puerta);
        counter++;
        abrir_puerta(la_puerta);

    }
     
    return NULL;
}

int main(int argc, char *argv[]) {
    	clock_t tiempoInicial, tiempoFinal;
	double segundos;
    if (argc != 2) { 
		fprintf(stderr, "usage: threads <loops>\n"); 
		exit(1); 
    }
    crear_puerta(la_puerta);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
	tiempoInicial = clock();
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
	tiempoFinal = clock();
	segundos = (double)((tiempoFinal-tiempoInicial));
    printf("Final value   : %d\n", counter);
	printf("miliegundos : %f\n",segundos);
	
    destruir_puerta(la_puerta);
    return 0;
}
