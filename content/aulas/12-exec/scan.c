#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main () {
    
    int numero;

    while(1) {
        scanf("%d", &numero);
    
        pid_t filho = fork();

        if (filho == 0) {

            char numero_str[20];

            sprintf(numero_str, "%d", numero);

            char *args[] = {"./eh_par", numero_str, NULL};

            execvp(args[0], args);

            printf("Erro no execvp!");
            return 0;

        } else {

            int status;
            wait(&status);

            if (WIFEXITED(status)) {
                int retorno = WEXITSTATUS(status);
                
                if (retorno == 1) {

                } else if (retorno == 0) {
                    
                } else if (retorno == 255) {
            
                    break;
                }
            
            }
            
        }
    
    
    }

    return 0;

}