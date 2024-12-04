#include <stdio.h>

int main() {
  int firstInput, secondInput;
  int interval = 0;

  printf("Please input first number\n");
  scanf("%d", &firstInput);
  getchar();

  printf("Please input the second number\n");
  scanf("%d", &secondInput);
  getchar();

  if (firstInput < secondInput) {
    for (int i = firstInput; i < secondInput; i++) {
      interval++;
    }
  }
  printf("The interval is %d", interval);
}
