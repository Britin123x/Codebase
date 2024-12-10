#include <stdio.h>
int count = 0;
int numOfDigits(int n);

int main() {
  int digits;
  int nums = 0;
  printf("count the digits of a given number : \n");
  printf("-----------------------------------------\n");
  printf("Input a number:");
  scanf("%d", &nums);
  digits = numOfDigits(nums);

  printf("The number of digits in the number is : %d.\n", digits);

  return 0;
}

int numOfDigits(int n) {
  if (n < 10) {
    count++;
    return count;
  } else {
    count++;
    n = n / 10;
    numOfDigits(n);
  }
}
