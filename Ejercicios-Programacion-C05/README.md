# Capitulo 5

## Punto1

### Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

la variable en el proceso hijo es de 101 por la definicion de x = x+1
en el caso en que se modifiquen las dos no se afectan, se tomaria x=100 
tanto para el hijo como para el padre

## punto2

### Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?


ambos pueden acceder al mismo tiempo y se respeta la linea en la cual cada
proceso esta escribiendo de tal modo que no hay conflitos en el archivo.

## punto3

### Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?

Es posible hacerlo sin wait gracias a la funcion sleep que duerme el procedimiento padre por 1 segundo

## punto4

### Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including execl(), execle(), execlp(), execv(), execvp(), and execvP(). Why do you think there are so many variants of the same basic call?

Los diferentes llamados de exexc se hacen segun las entradas que se le pasen

## punto5

### Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?

El algoritmo retorna -1 en el wait porque no existe un otro proceso o hijo dentro del proceso hijo

## punto6

### Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?

En este caso se utiliza la funciòn waitpid para dejar en espera determinados procesos especificos.

## punto7

### Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?

cuando el hijo hace close(STDOUT_FILENO); no puede imprimir nada pues esta cerrando su propia salida.