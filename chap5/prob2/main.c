#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file name]\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[512];
    ssize_t bytesRead;
    int total = 0;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        total += bytesRead;
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    printf("File name: %s\n", argv[1]);
    printf("File size: %d bytes\n", total);

    close(fd);
    return 0;
}

