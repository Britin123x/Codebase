#include <stdbool.h>
#include <stdio.h>

void getArrayInput(int inputArray[], int numVals) {
  for (int i = 0; i < numVals; i++) {
    scanf("%d", &inputArray[i]);
  }
}

void printArray(int arr[], int numVals) {
  int i;
  for (i = 0; i < numVals; i++) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}

void SortArray(int sortingList[], int numVals) {
  int tempValue;
  int i = 0;
  int j = 0;
  bool swapped; // I borrowed this idea; it's the only reason stdbool exists but
                // *should* help with runtimes once an input has been completed.

  for (i = 0; i < numVals - 1; i++) {
    swapped = false; // Sets the bool to false to check the inside loop.
    for (j = 0; j < numVals - i - 1; j++) {
      if (sortingList[j] > sortingList[j + 1]) {
        tempValue = sortingList[j];
        sortingList[j] = sortingList[j + 1];
        sortingList[j + 1] = tempValue;
        swapped = true;
      }
    }
    if (swapped == false) // This means the internal for-loop did nothing.
    {
      break; // If the internal for-loop did nothing, then the array is fully
             // sorted.
    }
  }
}

void reverseArray(int arr[], int numVals) {
  for (int i = 0; i < numVals / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[numVals - i - 1];
    arr[numVals - i - 1] = temp;
  }
}

int main(void) {
  int arraySize;
  scanf("%d", &arraySize);

  int userArray[arraySize];

  getArrayInput(userArray, arraySize);

  SortArray(
      userArray,
      arraySize); // Sorts the array, lowest to highest. Since the problem is
                  // arbitrary, I opted to do this then swap.
  reverseArray(userArray, arraySize);
  printArray(userArray, arraySize);
  return 0;
}
