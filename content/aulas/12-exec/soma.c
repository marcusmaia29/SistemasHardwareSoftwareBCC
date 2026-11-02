#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


    if (argc < 3) {
        printf("Erro: informe pelo menos 2 números .\n");
        return 1;
    }

    if (argc >= 3) {
        
        double soma = 0;

        for (int i = 1; i < argc; i++) {
            soma+= atof(argv[i]);
            
        }
        
        printf("A soma  dos argumentos é: %f\n", soma);
    }

    return 0;

}