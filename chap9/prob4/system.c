#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int mysystem(const char *cmdstring) {
    int pid, status;

    // If cmdstring is NULL, return 1
    if (cmdstring == NULL) {
        return 1;
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) { // Fork failed
        return -1;
    }

    if (pid == 0) { // Child process
        // Execute the command using /bin/sh
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127); // If execl fails
    }

    // Parent process waits for the child to complete
    do {
        if (waitpid(pid, &status, 0) == -1) {
            if (errno != EINTR) { // Waitpid error other than EINTR
                return -1;
            }
        } else { // Child exited, return status
            return status;
        }
    } while (1);
}

