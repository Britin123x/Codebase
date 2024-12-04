#include <stdio.h>

int main()
{
    int lowerBound;
    int upperBound;
    int intervalSize = 0;

    printf("Please input your first number:");
    scanf("%d", &lowerBound);

    printf("Please input your second number:");
    scanf("%d", &upperBound);

    if (lowerBound < upperBound)
    {
        for(int i = lowerBound; i < upperBound; i++)
        {
            intervalSize++;
        }
    }

    printf("Interval %d -> %d size is: %d", lowerBound, upperBound, intervalSize);

    return 0;
}