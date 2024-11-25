#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node
struct student {
    int id;
    char name[20];
    struct student *next;
};

int main() {
    struct student *head = NULL, *p;
    int id, count = 0;
    char name[20];

    printf("Enter student ID and name (Enter 'x' to stop):\n");

    while (scanf("%d %s", &id, name) == 2) {
        p = (struct student *)malloc(sizeof(struct student));
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }

        p->id = id;
        strcpy(p->name, name);
        p->next = head;
        head = p;
        count++;
    }

    printf("\n* Student Information (Reversed Order) *\n");
    p = head;
    while (p != NULL) {
        printf("ID: %d, Name: %s\n", p->id, p->name);
        p = p->next;
    }

    printf("Total students: %d\n", count);

    // Free allocated memory
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }

    return 0;
}

