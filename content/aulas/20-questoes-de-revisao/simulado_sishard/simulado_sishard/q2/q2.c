// Leia o PDF ou MD antes de iniciar este exercício!

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    int ret;
    int wst;

    pid_t filho = fork();

    do {
        // Construa a chamada do executavel siscoin. Veja enunciado.
        if (filho == 0) {
            char *args[] = {"./siscoin", argv[1], argv[2], argv[3], NULL};
            execvp(args, filho);
            printf("execvp falhou\n");
        } else {

            int status;
            wait(&status);

            if (WIFESTATUS(status)) {
                printf("O filho retornou: %d\n", WEXITEDSTATUS(status));
            }

        }


        // No pai, espere e trate o resultado

        // DICA: ao atribuir o return do siscoin, faça casting para (char)

    } while (ret > 0); // Repita enquanto houver falha. 
                       // Para se tem problema com o valor ou a qtde de parâmetros
                       // Esta validação está sendo feita em siscoin

    return 0;
}