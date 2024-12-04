#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// SIGALRM handler
void alarm_handler(int signum) {
    printf("Wake up\n");
    _exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5);

    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    return 0;
}

