#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
  char type;
  char name[MAX_NAME_LENGTH];
  short age;
  double average;
} Student;

bool write_data(char *fileName, Student *data, int total);
Student *read_data(char *fileName, int *total);
Student *read_from_csv(char *fileName, int *total);
int countLines(char *fileName);

int main(void) {
  int totalStudents;
  int total;
  char fileName[10] = "file.csv";
  total = countLines("file.csv");
  Student *file_data;

  file_data = read_data(fileName, &total);
  if (file_data == NULL) {
    printf("Error reading from CSV file.\n");
    return 1;
  }
  printf("Begin CSV Readback: \n \n");
  for (int i = 0; i < total; i++) {
    printf("%c, %s, %hi, %f\n", file_data[i].type, file_data[i].name,
           file_data[i].age, file_data[i].average);
  }
}

Student *read_from_csv(char *fileName, int *total) {
  FILE *inputCSV;
  inputCSV = fopen(fileName, "r");

  if (inputCSV == NULL) {
    printf("Open CSV file returns null pointer.\n");
    return NULL;
  }
  Student *output = malloc(sizeof(Student) * (*total));
  Student buffer;
  bool ReadFailure = false;
  for (int i = 0; i < *total; i++) {
    if (fscanf(inputCSV, "%c, ", &buffer.type) == EOF)
      ReadFailure = true;
    if (fscanf(inputCSV, "%s, ", buffer.name) == EOF)
      ReadFailure = true;
    if (fscanf(inputCSV, "%hi, ", &buffer.age) == EOF)
      ReadFailure = true;
    if (fscanf(inputCSV, "%lf \n", &buffer.average) == EOF)
      ReadFailure = true;

    if (ReadFailure) {
      free(output);
      printf("Error reading data from CSV\n");
      return NULL;
    }

    buffer.type = output[i].type;
    strcpy(output[i].name, buffer.name);
    buffer.age = output[i].age;
    buffer.average = output[i].average;
  }

  if (fclose(inputCSV) == EOF) {
    free(output);
    return NULL;
  }

  return output;
}

Student *read_data(char *fileName, int *total) {}

bool write_data(char *fileName, Student *data, int total) {
  FILE *writeFile;
  writeFile = fopen(fileName, "wb");
}

int countLines(char *fileName) {
  FILE *inputFile;
  inputFile = fopen(fileName, "r");
  bool lineCount = true;
  char c;
  int totalElements = 0; // Start with 0 elements read.
  while (lineCount) {
    c = fgetc(inputFile);
    if (c == '\n')
      totalElements++;
    else if (c == EOF)
      lineCount = false;
  }
  fclose(inputFile);
  return totalElements;
}
