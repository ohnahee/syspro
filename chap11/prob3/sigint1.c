#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void intHandler(int signo) {
    printf("Interrupt signal received\n");
    printf("Signal number: %d\n", signo);
    exit(0); 
}

int main() {
    
    signal(SIGINT, intHandler);

    while (1) {
        pause();
    }

    printf("End of program\n");
    return 0;
}

