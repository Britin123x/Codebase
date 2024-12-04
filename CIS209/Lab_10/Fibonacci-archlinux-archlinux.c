#include <stdio.h>

int fibonacci(int n); // Functino Prototype

int main() {

  int num = 0;
  int result = -1;

  printf("Enter a number to see it's fibonacci value:");
  scanf("%d", &num);
  result = fibonacci(num);

  printf("The fibonacci value of %d is %d.\n", num, result);
  return 0;
}

int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
