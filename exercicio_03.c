//exercicio_03
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    pid_t pid1 = fork();
    int v = 100;
    if (pid1 == 0) {
        v += 100; 
        
        pid_t pid2 = fork();
        if (pid2 == 0) { 
            v += 100; 
            printf("Neto - v = %d\n", v);
            exit(0);
        } else if (pid2 > 0) { 
            wait(NULL);
            printf("Filho1 - v = %d\n", v);
            exit(0);
        } else {
            perror("fork");
            exit(1);
        }
    } else if (pid1 > 0) { 
        wait(NULL);
        printf("Pai - v = %d\n", v);
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}