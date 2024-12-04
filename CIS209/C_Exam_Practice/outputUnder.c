#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS 20

int main(void) {
   int userValues[NUM_ELEMENTS];    // Set of data specified by the user

   int totalAmount, threshold;

   scanf("%d", &totalAmount);

   for(int i = 0; i < totalAmount; i++)
   {
    scanf("%d", &userValues[i]);
   }

   scanf("%d", &threshold);

   for(int i = 0; i < totalAmount; i++)
   {
    if (userValues[i] <= threshold)
    {
        printf("%d,", userValues[i]);
    }
   }
    printf("\n");

   return 0;
}
