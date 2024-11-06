#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct student record;
    printf("Enter StudentID you want to modify: ");
    int id;
    scanf("%d", &id);

    // Lock the file
    if (lockf(fd, F_LOCK, 0) == -1) {
        perror("Error locking file");
        close(fd);
        exit(1);
    }

    lseek(fd, (id - START_ID) * sizeof(struct student), SEEK_SET);
    if (read(fd, &record, sizeof(struct student)) > 0 && record.id != 0) {
        printf("Name:%s\t StuID:%d\t Score:%d\n", record.name, record.id, record.score);
        printf("Enter new score: ");
        scanf("%d", &record.score);
        lseek(fd, -sizeof(struct student), SEEK_CUR);
        write(fd, &record, sizeof(struct student));
    } else {
        printf("No record found\n");
    }

    // Unlock the file
    if (lockf(fd, F_ULOCK, 0) == -1) {
        perror("Error unlocking file");
        close(fd);
        exit(1);
    }

    close(fd);
    return 0;
}

