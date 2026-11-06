// Leia o PDF ou MD antes de iniciar este exercício!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

// Variável GLOBAL para armazenar o valor de PI aproximado
double pi = 0.0;

// Função que gera um numero aleatorio uniformemente entre 0.0 e 1.0
// Você não deve alterar esta função
double random_zero_one() {
    return (double)random()/(double)RAND_MAX;
}

// Função que calcula o valor de pi por simulação (Monte Carlo)
// Você não deve alterar esta função
double aproxima_pi() {
    long dentro = 0;
    long total_pontos = 0;

    double x,y,d;
    while (1) {
        x = random_zero_one();
        y = random_zero_one();
        d = x*x + y*y;
        if (d<=1) {
            dentro++;
        }
        total_pontos++;
        pi = 4.0 * ((double)dentro/(double)total_pontos);
        if (random_zero_one() < 0.008) {
            sleep(1);
        }
    }
}

// Crie AQUI a função que exporta o valor de pi para um arquivo chamado pi.txt
void exporta_pi() {
    char buffer[100];

    sprintf(buffer, "%f", pi);

    int fd = open("pi.txt", O_WRONLY | O_CREAT | O_TRUNC, 0700);

    write(fd, buffer, strlen(buffer));

    close(fd);
}

// Esta função deve ser chamada pelo handler quando este for acionado

// Crie AQUI a função que será o handler do sinal
void handler(int sinal) {

    printf("Control+c do terminal, o sinal é: %d\n", sinal);
    printf("Valor de pi: %f\n", pi);

    exporta_pi();
    exit(0);
}

int main() {

    // Exiba o PID deste processo
    printf("O PID do processo é: %d\n", getpid());
    // Registre AQUI seu handler para o sinal SIGINT!
    struct sigaction s;

    s.sa_handler = handler;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);

    srand(time(NULL));
    aproxima_pi();

    return 0;
}