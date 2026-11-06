// Leia o PDF ou MD antes de iniciar este exercício!

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    int ret;
    int wst;

    do {
        // Construa a chamada do executavel siscoin. Veja enunciado.
        pid_t filho = fork();
        
        if (filho == 0) {
            char *args[] = {"./siscoin", argv[1], argv[2], argv[3], NULL};
            execvp(args[0], args);
            printf("execvp falhou\n");
            return 1;
            
        } else {

            // No pai, espere e trate o resultado
            wait(&wst);

            // DICA: ao atribuir o return do siscoin, faça casting para (char)
            if (WIFEXITED(wst)) {
                printf("O filho retornou: %d\n", WEXITSTATUS(wst));
                ret = (char) WEXITSTATUS(wst);
            }   

        }
        
    } while (ret > 0); // Repita enquanto houver falha. 
                       // Para se tem problema com o valor ou a qtde de parâmetros
                       // Esta validação está sendo feita em siscoin
    return 0;
}