#include <stdio.h>
#include <string.h>

#define MAX_LINES 5     
#define MAX_LENGTH 100   

int main() {
    char lines[MAX_LINES][MAX_LENGTH];  
    char temp[MAX_LENGTH];
    int i, j;


    i = 0;
    while (i < MAX_LINES) {
		fgets(lines[i], MAX_LENGTH, stdin);

        lines[i][strcspn(lines[i], "\n")] = '\0';
        i++;
    }

    for (i = 0; i < MAX_LINES - 1; i++) {
        for (j = i + 1; j < MAX_LINES; j++) {
            if (strlen(lines[i]) < strlen(lines[j])) {
                
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    for (i = 0; i < MAX_LINES; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

