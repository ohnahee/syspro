#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid1, pid2, status;

    printf("[%d] Parent process start\n", getpid());

    pid1 = fork();
    if (pid1 == 0) {
        // First child process
        printf("[%d] Child process [1] start\n", getpid());
        sleep(1);
        printf("[%d] Child process [1] end\n", getpid());
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        // Second child process
        printf("[%d] Child process [2] start\n", getpid());
        sleep(2);
        printf("[%d] Child process [2] end\n", getpid());
        exit(2);
    }

    // Parent process waits for specific children
    int child1 = waitpid(pid1, &status, 0);
    printf("[%d] Child process [1] %d end\n", getpid(), child1);
    printf("Exit code %d\n", WEXITSTATUS(status));

    int child2 = waitpid(pid2, &status, 0);
    printf("[%d] Child process [2] %d end\n", getpid(), child2);
    printf("Exit code %d\n", WEXITSTATUS(status));

    return 0;
}

