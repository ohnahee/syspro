#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>

int main() {
    const char *sourceFile = "1.txt";
    const char *targetFile = "2.txt";
    struct stat statbuf;


    if (stat(sourceFile, &statbuf) == -1) {
        perror("Error getting source file information");
        return 1;
    }

    
    struct utimbuf new_times;
    new_times.actime = statbuf.st_atime; 
    new_times.modtime = statbuf.st_mtime; 


    if (utime(targetFile, &new_times) == -1) {
        perror("Error setting target file times");
        return 1;
    }

    printf("Time values from '%s' have been applied to '%s'\n", sourceFile, targetFile);
    return 0;
}

