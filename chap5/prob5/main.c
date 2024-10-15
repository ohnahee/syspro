#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "student.h"

int main() {
    int fd = open("student.txt", O_WRONLY | O_CREAT | O_EXCL, 0640);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    struct student st;
    printf("Enter student ID, name, and score:\n");
    
    while (scanf("%d %s %d", &st.id, st.name, &st.score) == 3) {
        lseek(fd, (st.id - START_ID) * sizeof(struct student), SEEK_SET);
        write(fd, &st, sizeof(struct student));
    }

    close(fd);
    return 0;
}

