#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid, status;

    printf("[%d] Parent process start\n", getpid());

    pid = fork();

    if (pid == 0) {
        // Child process
        printf("[%d] Child process start\n", getpid());
        exit(1);
    } else if (pid > 0) {
        // Parent process waits for the child
        int child = wait(&status);
        printf("[%d] Child process %d end\n", getpid(), child);
        printf("Exit code %d\n", WEXITSTATUS(status));
    } else {
        perror("fork failed");
    }

    return 0;
}

