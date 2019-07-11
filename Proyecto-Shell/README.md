# SHELL

## Integrantes

Johan Florez Benanvides 1734417
Cristian Danilo Pascumal 1723041
Andres Felipe Valencia 1667639

## Programas
* [shell.c](shell.c)
* [funciiones.c](funciones.c)
* [funciones.h](funciones.h)

se hace una shell con comandos básicos, para compilar el programa se llevan a cabo los siguientes pasos:

* Generar libreria
```
gcc -c funciones.c -o funciones.o
ar rcs funciones.a funciones.o
``` 
* Como se hace uso de la libreria ReadLine se enlaza el programa usando:

```
gcc shell.c -L/usr/include -lreadline -o shell
```
* finalmente, se ejecuta el programa:
```
./shell
```

