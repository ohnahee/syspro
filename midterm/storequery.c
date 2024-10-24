#include <stdio.h>
#include <stdlib.h>
#include "db.h"

int main(int argc, char *argv[]) {
 if (argc < 2) {
 printf("Usage: %s [file name]\n", argv[0]);
 return 1;
 }
 
 FILE *file = fopen(argv[1], "r");
 if (file == NULL) {
 perror("Failed to open file");
 return 1;
 }
 
 Struct sturuct;
 printf("--Goods query--\n");

 while (fscanf(file, "%d %s", &struct.id, struct.name)){
 printf("%d %s", struct.id, struct.name);
 }


 printf("-------------------------------\n");
 
 fclose(file);
 
 return 0;

}
