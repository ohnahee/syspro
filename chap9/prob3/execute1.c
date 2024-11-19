#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Parent process start\n");

    if (fork() == 0) { // Child process
        execl("/bin/echo", "echo", "hello", NULL); // Execute echo command
        fprintf(stderr, "First execution failed\n");
        exit(1);
    }

    printf("Parent process end\n");
    return 0;
}

