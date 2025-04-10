//exercicio_02
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(int argc, char **argv) {
    pid_t pid = fork();
    int v = 100;
    if (pid == 0) {
        int *ptr = &v;
        *ptr += 100;  
        printf("Filho - v = %d (Endereço: %p)\n", v, &v);
        exit(0); 
    } else if (pid > 0) { 
        wait(NULL);
        printf("Pai - v = %d (Endereço: %p)\n", v, &v);
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}