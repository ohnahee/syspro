#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    const char *dirPath = argv[1];
    DIR *dir;
    struct dirent *entry;

    
    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

 
    while ((entry = readdir(dir)) != NULL) {
        printf("Inode: %lu - Name: %s\n", entry->d_ino, entry->d_name);
    }

    // Close the directory when done
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        return 1;
    }

    return 0;
}

