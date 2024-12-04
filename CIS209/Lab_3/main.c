/*
BRITIN HANNA
CIS-209
TUESDAY 11:30
*/
#include <stdio.h>

int main()
{

   int operator1, operator2, operationVal; // Used for add and subtract
   double complexOperator1, complexOperator2; // used for Multiplication, Division and Modulus

    printf("\tWelcome to my calculator \n");
    printf("Please look at the menu below for your calculations \n");

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus (remainder)\n");
    printf("Select from 1-5: \n");
    
    scanf("%d", &operationVal);

   switch(operationVal)
   {
    case 1: // Addition
        printf("Enter a number for addition: \n");
        scanf("%d", &operator1);
        
        printf("Enter a second number for addition: \n");
        scanf("%d", &operator2);
        
        printf("%d + %d = %d\n", operator1, operator2, operator1 + operator2); //Prints the entire addition operation and the output.
        break;
    case 2: // Subtraction
        printf("Enter a number for subtraction: \n");
        scanf("%d", &operator1);
        
        printf("Enter a second number for subtraction: \n");
        scanf("%d", &operator2);
        
        printf("%d - %d = %d\n", operator1, operator2, operator1 - operator2); //Prints the entire subtraction operation and the output.
        break;
    case 3: // Multiplication
        printf("Enter a number for multiplication: \n");
        scanf("%lf", &complexOperator1); //Accepts doubles
        
        printf("Enter a second number for multiplication: \n");
        scanf("%lf", &complexOperator2); //Accepts doubles
        
        printf("%.2lf * %.2lf = %.2lf\n", complexOperator1, complexOperator2, complexOperator1 * complexOperator2); // Prints the entire multiplication operation and the output.
        break;
    case 4: // Division
        
        printf("Enter a number for division: \n");
        scanf("%lf", &complexOperator1); // Accepts doubles
        
        printf("Enter a second number for division: \n");
        scanf("%lf", &complexOperator2); // Accepts doubles
        
        if(complexOperator2 == 0)
        {
            printf("Division by zero is not allowed, please restart and try again. \n"); // Error Case
        } else
        {
            printf("%.2lf / %.2lf = %.2lf\n", complexOperator1, complexOperator2, complexOperator1 / complexOperator2); // Prints division operation and output
        }
        
        break;
    case 5: // Modulus
        printf("Enter a number for modulus: \n");
        scanf("%d", &operator1); //Integer only
        
        printf("Enter a second number for modulus: \n");
        scanf("%d", &operator2); //Integer only
        
        if(complexOperator2 == 0)
        {
            printf("Modulus by Zero is not allowed, please restart and try again. \n"); // Error Case
        } else
        {
            printf("%d MOD %d = %d\n", operator1, operator2, operator1 % operator2); // Prints modulus operation and output.
        }
        
        break;
    default: // if an invalid operator is selected
        printf("Sorry, this is not an accepted operation. Please restart and try again. \n");
        break;
   }
    
    return 0;
        
}