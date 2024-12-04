#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS 20 // Number of input integers

int main(void) {
   
   int userVals[NUM_ELEMENTS];          // Array to hold the user's input integers
   int i;
   
   scanf("%d", &userVals[0]);

   for(int i = userVals[0]; i > 0;)
   {
      scanf("%d", &userVals[i]);
      i--;
   }

   for(int i = 1; i <= userVals[0];)
   {
      printf("%d,", userVals[i]);
      i++;
   }
   
   printf("\n");

   return 0;
}
