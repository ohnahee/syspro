#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define NUM_CHILDREN 2

int child_pids[NUM_CHILDREN];

// Signal handler for SIGALRM
void alarm_handler(int signo) {
    printf("SIGALRM received. Terminating child processes.\n");
    for (int i = 0; i < NUM_CHILDREN; i++) {
        kill(child_pids[i], SIGTERM); // Terminate child processes
    }
    exit(0);
}

// Function to simulate child process work
void child_work(int id) {
    for (int i = 1; i <= 10; i++) {
        printf("child [%d] execute: %d\n", id, i);
        sleep(1);
    }
    exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler); // Register SIGALRM handler
    alarm(7); // Set alarm to trigger after 7 seconds

    for (int i = 0; i < NUM_CHILDREN; i++) {
        if ((child_pids[i] = fork()) == 0) {
            // Child process
            child_work(i + 1);
        } else if (child_pids[i] < 0) {
            perror("fork");
            exit(1);
        }
    }

    // Parent process waits for all children to finish
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("All child processes finished.\n");
    return 0;
}

