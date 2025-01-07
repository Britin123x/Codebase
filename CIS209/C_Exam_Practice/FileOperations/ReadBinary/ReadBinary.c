#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int data[1000000];
  FILE *file;
  char fileInput[30];
  printf("Please place your .bin file in the current directory and input its "
         "exact name, with file extension.\n ");

  printf("File Name:");
  scanf("%s", fileInput);

  file = fopen(fileInput, "rb");

  if (file == NULL) {
    printf("Error in opening requested file. \n");
    return 1;
  }

  fread(data, sizeof(data), 1, file);

  fclose(file);

  for (int i = 0; i < 1000000; i++) {
    if (data[i] == EOF)
      break;
    else
      printf("%d\n", data[i]);
  }

  return 0;
}
