// Leia o PDF ou MD antes de iniciar este exercício!


// Faça os includes necessários aqui
// #include ...
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void *thread1(void *_arg) {

    printf("A\n");

    sem_post(&sem_inicio);
    sem_post(&sem_inicio);
    sem_post(&sem_inicio);

    sem_wait(&sem_fim);
    sem_wait(&sem_fim);
    sem_wait(&sem_fim);

    printf("E\n");

    return NULL;
}

void *thread2(void *_arg) {

    sem_wait(&sem_inicio);

    printf("B\n");

    sem_post(&sem_fim);

    return NULL;
}

void *thread3(void *_arg) {

    sem_wait(&sem_inicio);

    printf("C\n");

    sem_post(&sem_fim);

    return NULL;
}

void *thread4(void *_arg) {

    sem_wait(&sem_inicio);

    printf("D\n");

    sem_post(&sem_fim);

    return NULL;
}

sem_t sem_inicio;
sem_t sem_fim;

int main(int argc, char *argv[]) {

    sem_init(&sem_inicio, 0, 0);
    sem_init(&sem_fim, 0, 0);
    
    // Crie TODAS as threads em um laço. Voce deve utilizar semaforos para sincronizacao.
    void *(*funcoes[])(void *) = {
        thread1,
        thread2,
        thread3,
        thread4
    };

    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, funcoes[i], NULL);
    }

    // Espere por TODAS as threads
    for (int i = 0. i < 4; i++) {
        pthread_join(&threads[i], NULL, funcoes[i], NULL);
    }

    sem_destroy(&sem_inicio);
    sem_destroy(&sem_fim);
    
    return 0;
}