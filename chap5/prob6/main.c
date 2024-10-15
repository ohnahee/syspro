#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct student st;
    int searchId;
    char choice;

    do {
        printf("Enter Student ID to search: ");
        if (scanf("%d", &searchId) != 1) {
            fprintf(stderr, "Input error\n");
            close(fd);
            return 1;
        }

        // Move to the corresponding record position
        lseek(fd, (searchId - START_ID) * sizeof(struct student), SEEK_SET);
        
        // Read data
        if (read(fd, &st, sizeof(struct student)) > 0 && st.id != 0) {
            printf("Student ID: %d\n", st.id);
            printf("Name: %s\n", st.name);
            printf("Score: %d\n", st.score);
        } else {
            printf("Record for Student ID %d not found\n", searchId);
        }

        // Ask if the user wants to continue
        printf("Continue? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    close(fd);
    return 0;
}

