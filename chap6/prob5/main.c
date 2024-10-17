#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void printFilePermissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

void printFileInfo(const char *dirPath, const char *fileName) {
    struct stat statbuf;
    char fullPath[1024];

    snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, fileName);

    if (lstat(fullPath, &statbuf) == -1) {
        perror("lstat error");
        return;
    }

    printFilePermissions(statbuf.st_mode);
    
    printf(" %lu", statbuf.st_nlink);


    struct passwd *pw = getpwuid(statbuf.st_uid);
    struct group  *gr = getgrgid(statbuf.st_gid);
    printf(" %s", pw ? pw->pw_name : "unknown");
    printf(" %s", gr ? gr->gr_name : "unknown");

   
    printf(" %5ld", statbuf.st_size);

    char timeBuf[20];
    struct tm *timeinfo = localtime(&statbuf.st_mtime);
    strftime(timeBuf, sizeof(timeBuf), "%b %d %H:%M", timeinfo);
    printf(" %s", timeBuf);

    printf(" %s\n", fileName);
}

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
        if (entry->d_name[0] == '.') {
            continue; 
        }
        printFileInfo(dirPath, entry->d_name);
    }

  
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        return 1;
    }

    return 0;
}

