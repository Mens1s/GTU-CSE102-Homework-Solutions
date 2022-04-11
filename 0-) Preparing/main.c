#include <stdio.h>
#include "util.h"


int main() {

    
    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */
    // printf("TODO: Remove this printf and add the code to read two fractional numbers and .....\n");
    printf("Enter first number numerator : ");
    scanf("%d",&num1); /* Taking first number numerator from user */

    printf("Enter first number denominator : ");
    do{
        scanf(" %d",&den1);
        if(den1==0) printf("Please enter \033[1;31m |nonzero| \033[0m number! : ");/*Homework does not include that denomonitor can not be zero so I don't accept to zero inputs bcs of math rules.*/
    }while(den1==0);
    

    printf("Enter second number numerator : ");
    scanf("%d",&num2);/* Taking second number numerator from user */

    printf("Enter second number denominator : ");
    do{
        scanf(" %d",&den2);
        if(den2==0) printf("Please enter \033[1;31m |nonzero| \033[0m number! : ");/*Homework does not include that denomonitor can not be zero so I don't accept to zero inputs bcs of math rules.*/
    }while(den2==0);

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);/*Used fraction_mul function which is defined in util.h to do multiplying process */
    fraction_print(num3, den3);/* Used fraction_print function which is defined in util.h to print output to terminal/screen */
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);/*Used fraction_div function which is defined in util.h to do dividing process */
    fraction_print(num3, den3);/* Used fraction_print function which is defined in util.h to print output to terminal/screen*/
    printf("\n");

    return(0);
}
