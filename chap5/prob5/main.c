#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    struct student st;
    printf("Enter student ID, name, and score:\n");
    
    while (scanf("%d %s %d", &st.id, st.name, &st.score) == 3) {
        lseek(fd, (st.id - START_ID) * sizeof(struct student), SEEK_SET);
        if (write(fd, &st, sizeof(struct student)) == -1) {
            perror("Error writing to file");
            close(fd);
            return 1;
        }
    }

    close(fd);
    return 0;
}

