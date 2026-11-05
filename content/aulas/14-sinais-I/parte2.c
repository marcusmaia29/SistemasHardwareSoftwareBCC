#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main() {
    pid_t filho;

    int regulador = 0;
    filho = fork();
    
   

    if (filho == 0) {
    
        printf("%d\n", getpid());
        while(1) {
        }

    } else {
        
        
        int status;

        pid_t pid_terminou = wait(&status);

        printf("O processo filho terminou: %d\n", pid_terminou);

        printf("WIFEXITED: %d\n", WIFEXITED(status));
        printf("WIFSIGNALED: %d\n", WIFSIGNALED(status));

        if (WIFSIGNALED(status)) {
            int sinal = WTERMSIG(status);

            printf("WTERMSIG: %d\n", sinal);
            printf("Sinal recebido: %s\n", strsignal(sinal));
        }   
    }

    return 0;
}
   
