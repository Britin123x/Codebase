#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ELEMENTS 3

typedef struct {
  char type;
  char name[MAX_NAME_LENGTH];
  short age;
  double average;
} Student;

int main(void) {
  FILE *file;

  file = fopen("file.csv", "w");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  Student students[MAX_ELEMENTS];

  // Initialize the members of the first Student struct in the array
  students[0].type = 'U';
  strcpy(students[0].name, "Nageeb");
  students[0].age = 20;
  students[0].average = 90;

  // Initialize the members of the second Student struct in the array
  students[1].type = 'U';
  strcpy(students[1].name, "Mary");
  students[1].age = 19;
  students[1].average = 95;

  // Initialize the members of the third Student struct in the array
  students[2].type = 'G';
  strcpy(students[2].name, "Kulvinder");
  students[2].age = 21;
  students[2].average = 85;

  for (int i = 0; i < MAX_ELEMENTS; i++) {
    fprintf(file, "%c, %s, %d, %.2f\n", students[i].type, students[i].name,
            students[i].age, students[i].average);
  }

  fclose(file);

  printf("\n%d records written. \n \n", MAX_ELEMENTS);
}
