#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <original file> <link file>\n", argv[0]);
        return 1;
    }

    int link_status = link(argv[1], argv[2]);
    if (link_status == -1) {
        perror("Error creating link");
        return 1;
    } else {
        printf("Link created successfully between %s and %s.\n", argv[1], argv[2]);
    }

    return 0;
}

