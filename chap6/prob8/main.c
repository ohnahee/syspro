#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source file> <link name>\n", argv[0]);
        return 1;
    }

    int symlink_status = symlink(argv[1], argv[2]);
    if (symlink_status == -1) {
        perror("Error creating symbolic link");
        return 1;
    } else {
        printf("Symbolic link %s created successfully for %s.\n", argv[2], argv[1]);
    }

    return 0;
}

