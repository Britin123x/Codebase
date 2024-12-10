#include <stdio.h>

int calcFactorial(int n); // Function Prototype

int main() {

  int num = 0;
  int result = -1;

  printf("Enter a number: ");
  scanf("%d", &num);
  result = calcFactorial(num);
  printf("The factorial of %d is %d.\n", num, result);

  return 0;
}

/*
f(n) is 1 if n is zero ----> Base Case
f(n) is n * f(n-1) is n > zero ----> Recursive case
*/

int calcFactorial(int n) {
  if (n == 0) {
    return 1; // Base Case, this is when it stops.
  } else {
    return n * calcFactorial(n - 1); // Recursive Case
  }
}
