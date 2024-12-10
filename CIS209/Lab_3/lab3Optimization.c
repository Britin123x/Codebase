/*
BRITIN HANNA
CIS-209
TUESDAY 11:30
*/
#include <stdio.h>
#include <string.h>

int main()
{

   int operator1, operator2, operationVal; // Used for add and subtract
   double complexOperator1, complexOperator2; // used for Multiplication, Division and Modulus

    int i = 0;
    int j = 0;
    int k = 0;

    // This is used for a dynamic number input
    char mathOperation[5][30];
    strcpy(mathOperation[0], "Addition");
    strcpy(mathOperation[1], "Subtraction");
    strcpy(mathOperation[2], "Multiplication");
    strcpy(mathOperation[3], "Division");
    strcpy(mathOperation[4], "Modulus (Remainder)");
    // Start

    printf("\tWelcome to My calculator! \n");

    // Start of User Selection Verification
    while(i != 1)
    {
        printf("Please input 1-5 to select an operation: \n");
        printf("1. %s\n", mathOperation[0]);
        printf("2. %s\n", mathOperation[1]);
        printf("3. %s\n", mathOperation[2]);
        printf("4. %s\n", mathOperation[3]);
        printf("5. %s\n", mathOperation[4]);
        
        
        scanf("%d", &operationVal);

        switch(operationVal) // Confirmation switch
        {
            case 1: 
                printf("You have selected %s as your operation. Please input 1 to confirm your selection, or press any number to review the options:\n", mathOperation[0]);
                scanf("%d", &i);
                break;
            case 2:
                printf("You have selected %s as your operation. Please input 1 to confirm your selection, or press any number to review the options:\n", mathOperation[1]);
                scanf("%d", &i);
                break;
            case 3:
                printf("You have selected %s as your operation. Please input 1 to confirm your selection, or press any number to review the options:\n", mathOperation[2]);
                scanf("%d", &i);
                break;
            case 4:
                printf("You have selected %s as your operation. Please input 1 to confirm your selection, or press any number to review the options:\n", mathOperation[3]);
                scanf("%d", &i);
                break;
            case 5:
                printf("You have selected %s as your operation. Please input 1 to confirm your selection, or press any number to review the options:\n", mathOperation[4]);
                scanf("%d", &i);
                break;
            default:
                printf("The requested operation does not exist, please try again \n");
                break;
        }
    } // End of User Selection Verification
    
    // User Input
    if(operationVal == 3 || operationVal == 4) // Double is needed
    {
        printf("Enter a number for %s: \n", mathOperation[operationVal - 1]);
        scanf("%lf", &complexOperator1);
        
        while (k = 0) // Cannot be zero
        {
            printf("Enter a second number for %s: \n", mathOperation[operationVal - 1]);
            scanf("%lf", &complexOperator2);
            if (complexOperator2 == 0)
            {
                printf("Sorry, zero is not an accepted value for this operation. \n");
            } 
            else
            {
                k = 1;
            }

        }       
       
    }
    else // Double not needed
    {
        printf("Enter a number for %s \n", mathOperation[operationVal - 1]);
        scanf("%d", &operator1);
        
        if( operationVal == 5 ) // If Modulus
        {
            while (j = 0) // Zero Checker
            {
                printf("Enter a second number for %s: \n", mathOperation[operationVal - 1]);
                scanf("%d", &operator2);
                
                if(operator2 == 0)
                {
                    printf("Sorry, zero is not an accepted value for this operation. \n");
                }
                else
                {
                    j = 1;
                }
            }
        }
        else
        {
            printf("Enter a second number for %s: \n", mathOperation[operationVal - 1]);
            scanf("%d", &operator2);
        }

    }
    


   switch(operationVal)
   {
    case 1: // Addition
        printf("%d + %d = %d\n", operator1, operator2, operator1 + operator2); //Prints the entire addition operation and the output.
        break;
    case 2: // Subtraction
        printf("%d - %d = %d\n", operator1, operator2, operator1 - operator2); //Prints the entire subtraction operation and the output.
        break;
    case 3: // Multiplication        
        printf("%.2lf * %.2lf = %.2lf\n", complexOperator1, complexOperator2, complexOperator1 * complexOperator2); // Prints the entire multiplication operation and the output.
        break;
    case 4: // Division
        printf("%.2lf / %.2lf = %.2lf\n", complexOperator1, complexOperator2, complexOperator1 / complexOperator2); // Prints division operation and output
        break;
    case 5: // Modulus (Remainder)
        printf("%d MOD %d = %d\n", operator1, operator2, operator1 % operator2); // Prints modulus operation and output.
        break;
    default: // With checks above, should never trigger. 
        printf("Sorry, this is not an accepted operation. Please restart and try again. \n");
        break;
   }
    
    return 0;
        
}