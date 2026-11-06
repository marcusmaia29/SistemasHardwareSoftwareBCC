#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int status = 0;

void operacao_lenta() {
    sleep(10);
}


void sigint_handler(int num) {
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);
    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num) {
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main() {
    /* TODO: registar SIGINT aqui. */
    struct sigaction s_int;

    s_int.sa_handler = sigint_handler;
    sigemptyset(&s_int.sa_mask);
    sigaddset(&s_int.sa_mask, SIGTERM);
    s_int.sa_flags = 0;

    sigaction(SIGINT, &s_int, NULL);
    


    /* TODO: registar SIGTERM aqui. */
    struct sigaction s_term;

    s_term.sa_handler = sigterm_handler;
    sigemptyset(&s_term.sa_mask);
    sigaddset(&s_term.sa_mask, SIGINT);
    s_term.sa_flags = 0;

    sigaction(SIGTERM, &s_term, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
