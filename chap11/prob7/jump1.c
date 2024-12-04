#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void p1(), p2();
jmp_buf env;

int main() {
    if (setjmp(env) != 0) { 
        printf("Exception handling after return due to error\n");
        exit(0);
    } else {
        printf("First pass\n");
    }

    p1();

    return 0;
}

void p1() {
    printf("Error\n");
    longjmp(env, 1); // Jump back to the saved point in main
}

