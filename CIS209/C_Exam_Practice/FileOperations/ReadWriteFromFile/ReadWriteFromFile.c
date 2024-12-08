#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ReadDataFromFile(char *fileName, int *totalLines);

int main() {
  FILE *file;
  int fileRows = 0;

  return 0;
}

char *ReadDataFromFile(char *fileName, int *totalLines) {
  FILE *fileRead;
  fileRead = fopen(fileName, "r");

  if (fileRead == NULL)
    return NULL;

  // Get the file sile for the entire allocation
  fseek(fileRead, 0, SEEK_END);
  size_t size = ftell(fileRead);
  fseek(fileRead, 0, SEEK_SET);

  while (!feof(fileRead)) {
    if (fgetc(fileRead) == '\n')
      (*totalLines)++;
  }

  fseek(fileRead, 0, SEEK_SET);

  char *fileData =
      malloc(size * sizeof(char)); // Creates a char pointer for the
                                   // entire file to be allocatted.
}
