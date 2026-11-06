#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int contador = 0;

void sig_handler(int num) {
    contador++;
    
    printf("Chamou Ctrl+C\n");
    
    if (contador == 3) {
        
        struct sigaction s;
        s.sa_handler = SIG_DFL;
        sigemptyset(&s.sa_mask);
        s.sa_flags = 0;
        
        sigaction(SIGINT, &s, NULL);
    
        kill(getpid(), SIGINT);
    
    }
}

int main() {
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */
    printf("Meu pid: %d\n", getpid());

    struct sigaction s;

    s.sa_handler = sig_handler;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);

    while(1) {
        sleep(1);
    }
    return 0;
}
