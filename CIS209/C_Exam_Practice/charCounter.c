#include<stdio.h>
#include <string.h>

int main()
{
    char letter;
    char str[50];
    int counter = 0;
    
    scanf("%c", &letter);
    getchar();
    scanf("%s", str);
   
    char *ptr = &str[0];

    while (*ptr != '\0')
    {
        if(*ptr == letter)
        {
            *ptr++;
            counter++;
        } else
        {
            *ptr++;
        }
    }

    printf("%.0f %c's", counter, letter);
    
}