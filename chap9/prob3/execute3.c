#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int child, pid, status;

    pid = fork();
    if (pid == 0) { // Child process
        execvp(argv[1], &argv[1]); // Execute the command
        fprintf(stderr, "%s: execution failed\n", argv[1]);
        exit(1);
    } else { // Parent process
        child = wait(&status); // Wait for child process
        printf("[%d] Child process %d terminated\n", getpid(), child);
        printf("Exit code %d\n", status >> 8);
    }
    return 0;
}

