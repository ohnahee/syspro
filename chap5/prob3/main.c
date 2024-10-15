#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    // Open the source file in read-only mode
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open or create the destination file in write-only mode
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(src_fd);
        return 1;
    }

    char buffer[512];
    ssize_t bytesRead, bytesWritten;
    
    // Read data from the source file and write it to the destination file
    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading source file");
    }

    close(src_fd);
    close(dest_fd);
    return 0;
}

