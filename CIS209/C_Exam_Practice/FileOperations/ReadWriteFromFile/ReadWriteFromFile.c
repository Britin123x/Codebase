#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int data[1000000];
  FILE *file;
  char fileInput[30];
  printf("Please place your .bin file in the current directory and input its "
         "exact name, with file extension.");

  scanf("%s", fileInput);

  file = fopen(fileInput, "rb");

  if (file == NULL) {
    printf("Error in opening requested file. \n");
    return 1;
  }

  fread(data, sizeof(data), 1, file);

  fclose(file);

  return 0;
}
