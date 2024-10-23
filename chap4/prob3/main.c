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

    char line[256];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file)) {
        printf("%d %s", lineNumber++, line);
    }

    fclose(file);
    return 0;
}

