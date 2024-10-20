#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void list_directory(const char *path, int show_inode, int show_slash, int show_quoted) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];

    dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (lstat(full_path, &file_stat) == -1) {
            perror("Unable to get file stat");
            continue;
        }

        if (show_inode) {
            printf("%lu ", entry->d_ino);
        }

        printf("%s", entry->d_name);

        if (show_slash && S_ISDIR(file_stat.st_mode)) {
            printf("/");
        }

        if (show_quoted) {
            printf(" \"%s\"", entry->d_name);
        }

        printf("\n");
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    int show_inode = 0;
    int show_slash = 0;
    int show_quoted = 0;
    const char *path = ".";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            show_inode = 1;
        } else if (strcmp(argv[i], "-p") == 0) {
            show_slash = 1;
        } else if (strcmp(argv[i], "-Q") == 0) {
            show_quoted = 1;
        } else {
            path = argv[i];
        }
    }

    list_directory(path, show_inode, show_slash, show_quoted);

    return 0;
}

