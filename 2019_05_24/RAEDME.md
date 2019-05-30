# Lenguaje C

En la clase se enseñó cómo crear un repositorio en github desde el terminal de linux

Se desarrollaron tres programas:

* [basico.c](basico.c)
* [litfun.c](litfun.c)
* [litfun.h](litfun.h)

Para compilar el programa se llevan a cabo los siguientes pasos:

* Generar la librería

gcc -c libfun.c -o libfun.o
ar rcs libfun.a libfun.o


* En el paso anterior se generó el archivo litfun.a. Ahora enlazaremos el programa basico.c con la librería litfun.a.

gcc basico.c -L. -lfun -o basico


* Finalmente, el programa se ejecuta:

./basico
