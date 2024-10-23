#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [source file] [destination file]\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        perror("Failed to open source file");
        return 1;
    }

    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        perror("Failed to open destination file");
        fclose(sourceFile);
        return 1;
    }

    int c;
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    return 0;
}

