#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

void p1();
void intHandler();
jmp_buf env;

int main() {
    signal(SIGINT, intHandler); // Register signal handler for SIGINT

    if (setjmp(env) != 0) {
        printf("Return due to interrupt\n");
        exit(0);
    } else {
        printf("First pass\n");
    }

    p1();

    return 0;
}

void p1() {
    while (1) {
        printf("Loop\n");
        sleep(1);
    }
}

void intHandler() {
    printf("Interrupt\n");
    longjmp(env, 1); // Jump back to the saved point in main
}

