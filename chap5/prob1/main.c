#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;

    // Check if filename argument is provided
    if (argc != 2) {
        printf("Usage: %s [filename].txt\n", argv[0]);
        return 1;
    }

    // Open the file in read/write mode
    fd = open(argv[1], O_RDWR);

    // Handle file open error
    if (fd == -1) {
        printf("File open error\n");
        return 1;
    } else {
        printf("File %s success : %d\n", argv[1], fd);
    }

    // Close the file
    close(fd);
    return 0;
}

