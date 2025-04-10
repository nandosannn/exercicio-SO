//exercicio_01
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    printf("Processo original (PID: %d)\n", getpid());
    
    for (int i = 1; i <= 4; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Código do filho
            printf("Filho %d (PID: %d), Pai: %d\n", i, getpid(), getppid());
            sleep(i);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
            exit(1);
        }
    }
    
    int status;
    while (wait(&status) > 0) {
        printf("Processo pai (PID: %d) recebeu filho\n", getpid());
    }
    
    printf("Processo (PID: %d) terminou\n", getpid());
    return 0;
}