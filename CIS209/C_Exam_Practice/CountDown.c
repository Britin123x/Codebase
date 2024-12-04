#include<stdio.h>

int main()
{
    int first, second;

    scanf("%d %d", &first, &second);
    getchar();


    if( second > first)
    {
        printf("%d ", first);
        for ( int i = first; i < second; )
        {
            if ((second - i) > 5 )
            {
                i+=5;
                printf("%d ", i);
                
            } else if ((second - i) < 5)
            {
                
                i+=5;
                printf("\n");
                
                
            } else 
            {
                i+=5;
                printf("%d \n", i);
                 
            }
        }
    }
    else if (second < first)
    {
        printf("Second integer can't be less than the first.\n");
    } 
    else 
    {
        printf("%d \n", first);
    }
}