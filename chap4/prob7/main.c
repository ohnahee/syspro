#include <stdio.h>
#include <stdlib.h>
#include "student.h"

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

    Student student;
    printf("ID Name Score\n");
    printf("-------------------------------\n");
    
    while (fscanf(file, "%d %s %hd", &student.id, student.name, &student.score) == 3) {
        printf("%d %s %hd\n", student.id, student.name, student.score);
    }

    printf("-------------------------------\n");
    fclose(file);
    return 0;
}

