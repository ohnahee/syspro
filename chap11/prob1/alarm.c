#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void alarm_handler(int signum) {
    printf("SIGALRM triggered! Exiting program\n");
    _exit(0); 
}

int main() {
    signal(SIGALRM, alarm_handler); 

	alarm(5); 

    printf("Starting loop\n");
    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d seconds elapsed\n", i);
    }

    return 0;
}

