#include <stdio.h>
#include <stdlib.h>

int mysystem(const char *cmdstring);

int main() {
    int status;

    // Test 1: "date" command
    status = mysystem("date");
    if (status < 0) {
        perror("Error executing command");
    } else {
        printf("Command finished with exit code %d\n", WEXITSTATUS(status));
    }

    // Test 2: "hello" command (should fail)
    status = mysystem("hello");
    if (status < 0) {
        perror("Error executing command");
    } else {
        printf("Command finished with exit code %d\n", WEXITSTATUS(status));
    }

    // Test 3: "who; exit 44" command
    status = mysystem("who; exit 44");
    if (status < 0) {
        perror("Error executing command");
    } else {
        printf("Command finished with exit code %d\n", WEXITSTATUS(status));
    }

    return 0;
}

