#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <symbolic link file>\n", argv[0]);
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t len = readlink(argv[1], buf, sizeof(buf) - 1);

    if (len == -1) {
        perror("Error reading symbolic link");
        return 1;
    }

    buf[len] = '\0';  // Null-terminate the string
    write(STDOUT_FILENO, buf, len);
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}

