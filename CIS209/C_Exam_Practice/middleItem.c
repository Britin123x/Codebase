#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS 9

int main(void) {
   int userValues[NUM_ELEMENTS];    // Set of data specified by the user
   int negativeCheck = 0;
   int floater;
   int totalInArray = 0;
   int middleNumber;
    int i;

   for( int i = 0 ; i < 9; i++ )
   {
    scanf("%d", &floater);
       if (floater > 0)
        {
        userValues[i] = floater;
        }
       else
        {
        i = 11;
        }
   }

   return 0;
}
