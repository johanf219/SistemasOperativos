# Tarea de programación en C

la siguiente actividad tiene como proposito evidenciar de una manera mas
 explicita la virtualización y concurrencia, llevada a cabo por un sistema
 operativo

* [common.h](common.h)
* [common_threads.h](common_threads.h)
* [mycommon.h](mycommon.h)
* [mem.c](mem.c)
* [threads.c](threads.c)
* [io.c](io.c)
* [cpu.c](cpu.c)
* [tarea.txt](tarea.txt)

mem.c :

 Lo que se hizo en este programa fue una virtualización en memoria de
 procesos, para lograr esto se siguieron los siguientes pasos:

Desactivamos la generación aleatoria de espacios de memoria a traves del 
siguiente comando:
```
sudo sh -c 'echo 0 > /proc/sys/kernel/randomize_va_space'
```
compilamos y ejecutamos el programa mem.c, que nos permite evidenciar
 como podemos crear dos procesos que apuntan a la misma dirección en memoria
 pero que acceden a diferentes valores

Lo ejecutamos
```
./mem (número) & ./(número)
```
threads.c:

Lo que se hizo en este punto fue añadir la funcionalidad de unas "puertas" a
 los hilos que habíamos creado en este programa, por la razón de que al no
 existir  dichas puertas, La concurrencia de los hilos al acceder al mismo
 dato, ocasionaba que se perdieran sumas a medida que le dabamos a counter un
 valor mas grande.
las puertas nos permiten que gestionar la forma en la que los hilos acceden
 concurrentemente a una zona de codigo, de esta manera permitiendonos dar un
 resultado acertado.

Lo ejecutamos
```
./threads (valor)
```
Io.c :

 Este programa se encarga de invertir el texto que hayamos guardado
 previamente en un archivo de este mismo tipo y recibe como entrada el nombre
 de este

Lo ejecutamos
```
./io (archivo)
```
