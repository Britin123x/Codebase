/*
BRITIN HANNA
CIS-209
TUESDAY 11:30
*/
#include <stdio.h>

int main()
{
    int add1, add2;
    int sub1, sub2;
    double multiply1, multiply2;
    double divide1, divide2;
    int mod1, mod2;
    
    
    printf("Enter a number for addition: \n");
    scanf("%d", &add1);
    printf("Enter a second number for addition: \n");
    scanf("%d", &add2);
    printf("%d + %d = %d\n", add1, add2, add1 + add2);

    printf("Enter a number for subtraction: \n");
    scanf("%d", &sub1);
    printf("Enter a second number for subtraction: \n");
    scanf("%d", &sub2);
    printf("%d - %d = %d\n", sub1, sub2, sub1 - sub2);

    printf("Enter a number for multiplication: \n");
    scanf("%lf", &multiply1);
    printf("Enter a second number for multiplication: \n");
    scanf("%lf", &multiply2);
    printf("%.2lf * %.2lf = %.2lf\n", multiply1, multiply2, multiply1 * multiply2);

    printf("Enter a number for division: \n");
    scanf("%lf", &divide1);
    printf("Enter a second number for division: \n");
    scanf("%lf", &divide2);
    printf("%.2lf / %.2lf = %.2lf\n", divide1, divide2, divide1 / divide2);

    printf("Enter a number for modulus: \n");
    scanf("%d", &mod1);
    printf("Enter a second number for modulus: \n");
    scanf("%d", &mod2);
    printf("%d MOD %d = %d\n", mod1, mod2, mod1 % mod2);
    
    for(int i = 0; i < 30; i++){
        printf("*");
    }
    printf("\n");

    int out = -1;
    // This expression should print the value of 33
    out = 1 + ((4 * 15) / 2) + 2;
    printf("1 + ((4 * 15) / 2) + 2 = %d\n", out);
    // This expression should print the value of 16
    out = 1 + (4 * 15) / (2 + 2);
    printf("1 + (4 * 15) / (2 + 2) = %d\n", out);
    // This expression should print the value of 39
    out = (((1 + 4) * 15) / 2) + 2;
    printf("(((1 + 4) * 15) / 2) + 2 = %d\n", out);
    // This expression should print the value of 18
    out = (1 + 4) * 15 / (2 + 2);
    printf("(1 + 4) * 15 / (2 + 2) = %d\n", out);


    return 0;
        
}