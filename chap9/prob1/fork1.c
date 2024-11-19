#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    printf("[%d] Process start\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    printf("[%d] Process : return value %d\n", getpid(), pid);

    return 0;
}

