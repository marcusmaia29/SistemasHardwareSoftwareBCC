#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

    if (argc != 3) {
        printf("Número de argumentos inválidos!\n");
        return 0;
    }

    char buffer[1];

    int fd1 = open(argv[1],O_RDONLY);
    if (fd1 == -1) {
        perror("Falha ao abrir arquivo de origem!");
        return 1;
    }
    
    int fd2 = open(argv[2],O_WRONLY | O_CREAT, 0700);

    if (fd2 == -1) {
        perror("Falha ao abrir arquivo de destino!");
        close(fd1);
        return 1;
    }

    while(read(fd1, buffer, 1) > 0) {
        write(fd2, buffer, 1);
    }

    close(fd1);
    close(fd2);

    return 0;
}