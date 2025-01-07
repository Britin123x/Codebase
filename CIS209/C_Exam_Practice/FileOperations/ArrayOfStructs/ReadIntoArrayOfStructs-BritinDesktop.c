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

  total = countLines("file.csv");
  Student *file_data;

  file_data = read_data("file.csv", &total);
  if (file_data == NULL) {
    printf("Error reading from CSV file.\n");
    return 1;
  }

  for (int i = 0; i < total; i++) {
    printf("%c, %s, %hi, %f\n", file_data[i].type, file_data[i].name,
           file_data[i].age, file_data[i].average);
  }
}

Student *read_from_csv(char *fileName, int *total) {
  FILE *inputCSV;
  inputCSV = fopen(fileName, "r");

  if (inputCSV == NULL)
    return NULL;

  Student *output = malloc(sizeof(Student) * (*total));

  for (int i = 0; i < *total; i++) {
    if (fscanf(inputCSV, "%c, %s, %hi, %f\n", output[i].type, output[i].name,
               output[i].age, output[i].average) == EOF) {
      free(output);
      return NULL;
    }
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
