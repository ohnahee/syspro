#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main() {
 int fd = open("db.dat", O_WRONLY | O_CREAT | O_EXC)
 if (fd == -1) {
 
 perror("Error creating file");
 
 return 1;
 
 }
 
 struct student st;
 printf("Enter student ID, name, and score:\n");

 while (scanf("%d %s %d", &st.id, st.name, &st.score) ==
 lseek(fd, (st.id - START_ID) * sizeof(struct stude
 write(fd, &st, sizeof(struct student));
 }


 close(fd);
 return 0;

}
