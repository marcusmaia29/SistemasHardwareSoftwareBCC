#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    if (argc != 2) {
        printf("Número de argumentos inválidos!\n");
        return 0;
    }

    long number = atol(argv[1]);

    if (number < 0) {
        printf("O número é negativo!\n");
        return -1;
    }
    
    if (number % 2 == 0) {
        printf("O número é par!\n");
        return 1;
    } else {
        printf("O número é ímpar!\n");
        return 0;
    }

}

