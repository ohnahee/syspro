#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = creat("myfile", 0600);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    // Write to the original file descriptor
    write(fd, "Hello! Linux", 12);

    // Duplicate the file descriptor
    int fd_copy = dup(fd);
    if (fd_copy == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    // Write to the duplicated file descriptor
    write(fd_copy, "Bye! Linux", 10);

    // Close both file descriptors
    close(fd);
    close(fd_copy);

    return 0;
}

