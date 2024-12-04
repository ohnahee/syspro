#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Signal handler
void sigint_handler(int signo) {
    static int count = 0;
    count++;

    if (count == 1) {
        printf("Signal number: %d\n", signo);
        printf("Press it again to exit.\n");
    } else {
        printf("Exiting program.\n");
        exit(0);
    }
}

int main(void) {
    struct sigaction newact, oldact;

    // Set up the signal handler
    newact.sa_handler = sigint_handler;
    sigfillset(&newact.sa_mask); // Block all signals during handler execution
    newact.sa_flags = 0;

    // Register SIGINT handler
    sigaction(SIGINT, &newact, &oldact);

    printf("Type Ctrl-C to test signal handling.\n");
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}

