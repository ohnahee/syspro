#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;

// Signal handler for SIGALRM
void alarmHandler() {
    printf("[alarm] child process %d timeout\n", pid);
    kill(pid, SIGINT); // Force terminate child process
}

int main(int argc, char *argv[]) {
    int child, status, limit;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <time_limit> <command>\n", argv[0]);
        return 1;
    }

    // Register SIGALRM handler
    signal(SIGALRM, alarmHandler);

    // Read time limit from arguments
    sscanf(argv[1], "%d", &limit);
    alarm(limit); // Set alarm

    // Fork a child process
    pid = fork();
    if (pid == 0) { // Child process
        execvp(argv[2], &argv[2]); // Execute command
        fprintf(stderr, "%s: Cannot execute\n", argv[2]);
        return 1;
    } else if (pid > 0) { // Parent process
        child = wait(&status); // Wait for child process
        printf("[%d] child process %d exit\n", getpid(), child);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}

