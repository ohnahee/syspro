#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Parent process start\n");

    if (fork() == 0) { // First child process
        execl("/bin/echo", "echo", "hello", NULL); // Execute echo command
        fprintf(stderr, "First execution failed\n");
        exit(1);
    }

    if (fork() == 0) { // Second child process
        execl("/bin/date", "date", NULL); // Execute date command
        fprintf(stderr, "Second execution failed\n");
        exit(2);
    }

    if (fork() == 0) { // Third child process
        execl("/bin/ls", "ls", "-l", NULL); // Execute ls command
        fprintf(stderr, "Third execution failed\n");
        exit(3);
    }

    printf("Parent process end\n");
    return 0;
}

