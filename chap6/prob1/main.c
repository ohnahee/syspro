#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void printFileType(const char *path) {
    struct stat statbuf;
    
    if (lstat(path, &statbuf) == -1) {
        fprintf(stderr, "lstat error for %s: ", path);
        perror("");  // Prints the error message from the last system call
        return;
    }
    

	if (S_ISREG(statbuf.st_mode)) {
        printf("%s: Regular File\n", path);
    } else if (S_ISDIR(statbuf.st_mode)) {
        printf("%s: Directory\n", path);
    } else if (S_ISLNK(statbuf.st_mode)) {
        printf("%s: Symbolic Link\n", path);
    } else if (S_ISCHR(statbuf.st_mode)) {
        printf("%s: Character Device\n", path);
    } else if (S_ISBLK(statbuf.st_mode)) {
        printf("%s: Block Device\n", path);
    } else if (S_ISFIFO(statbuf.st_mode)) {
        printf("%s: FIFO (Named Pipe)\n", path);
    } else if (S_ISSOCK(statbuf.st_mode)) {
        printf("%s: Socket\n", path);
    } else {
        printf("%s: Unknown File Type\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path1> <file_path2> ...\n", argv[0]);
        return 1;
    }
    
    for (int i = 1; i < argc; i++) {
        printFileType(argv[i]);
    }
    
    return 0;
}

