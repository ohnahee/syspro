#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file name]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
    return 0;
}

