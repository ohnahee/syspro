#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <link file>\n", argv[0]);
        return 1;
    }

    int unlink_status = unlink(argv[1]);
    if (unlink_status == -1) {
        perror("Error deleting link");
        return 1;
    } else {
        printf("Link %s deleted successfully.\n", argv[1]);
    }

    return 0;
}

