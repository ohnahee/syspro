#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_path> <permissions_in_octal>\n", argv[0]);
        return 1;
    }

    const char *filePath = argv[1];
    int permissions = strtol(argv[2], NULL, 8);  // Convert permissions from string to octal integer

    // Attempt to change file permissions
    if (chmod(filePath, permissions) == -1) {
        perror("Error changing file permissions");
        return 1;
    }

    printf("Permissions for '%s' changed to '%o'\n", filePath, permissions);
    return 0;
}

