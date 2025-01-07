#include <stdbool.h>
#include <stdio.h>

void swap(int *xp, int *yp);
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);

int main() {
  int size = 10;
  int array[10] = {32, 12, 94, 85, 60, 100, 46, 30, 2, 9};
  printArray(array, size);
  bubbleSort(array, size);
  printArray(array, size);
  return 0;
}

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Element %d: %d\n", i + 1, arr[i]);
  }
  printf("----------------------------------------------\n");
}

void bubbleSort(int arr[], int n) {
  bool swapped;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
}
