#include <stdio.h>
#include "util.h"

int main() {
    /* PART 1 */
    int fint, sint, div, next;
    printf("Please enter first integer : ");
    scanf("%d",&fint); 

    printf("Please enter second integer : ");
    scanf("%d",&sint);

    printf("Please enter divisor : ");
    scanf("%d",&div);

    int result = find_divisible(fint,sint,div);//Get result from find_divisible() function

    if(result == 0) printf("There is not any integer between %d and %d can be divided by %d\n",fint,sint,div); // if result equals 0 it is a empty error!

    else{
        printf("The first integer between %d and %d divided by %d is %d\n",fint,sint,div,result);
        printf("Enter the number how many next: ");
        scanf("%d",&next);//Get next number from user
        if(next<0) printf("No possible to find %d. divisible between %d and %d divided by %d.\n",next+1,fint,sint,div);//if user enters minus number we let error message
        else{
            int resNth = result; // I use resNth because of variable name of result can be understand wrong
            for(int a = 0;a<next;a++) {
                resNth = find_nth_divisible(div,resNth,sint);
                if (resNth == -999) break; // -999 is a error code for this homework which is defined by tutor so we have to ignore -999 case
            }
            if(resNth == -999) printf("No possible to find %d. divisible between %d and %d divided by %d.\n",next+1,fint,sint,div);
            else printf("The %d. integer between %d and %d divided by %d is %d",next+1,fint,sint,div,resNth);
        }
    }
    /* PART 2 */

    char tc[11];
    printf("\nPART 2\n\nPlease enter your TC : ");
    scanf("%s", tc);
    int tcResult = validate_identity_number(tc); // Get validate result from function
    while(tcResult == 0){ // if ID is wrong, we get true id from user in a while loop
    	printf("Your TC number is invalid!\n");
    	printf("Please enter your TC again : ");
    	scanf("%s", tc);
    	tcResult = validate_identity_number(tc);
    }
    int paswd = 0, len = 0, control = 0, toBig = 1;
    char tempPas[10];
    printf("Please enter password : ");//0101 problem
    
    while(control == 0){ // get user input for password until the correct type of password
        len = 0;
        scanf("%s",tempPas); // User can use 0___ Password so I get it in char array form 
        for(;tempPas[len]!='\0';len++);
        if(len==4) control = 1;
        else printf("Please enter 4 digit: ");
    }
    
    for(int a = 3;a>=0;a--){
        paswd += ((int)tempPas[a]-48)*toBig; // Char array converted to integer value  
        toBig *= 10;
    }
    create_customer(tc,paswd);
    
    /* PART 3 */
    
    char id[11];
    int pasword;

    printf("\nPART 3\n\nPlease enter your id : ");
    scanf("%s",id);

    printf("Please enter your password : ");
    scanf("%d",&pasword);

    int logStatus = check_login(id, pasword); // Get login result from check_login function
    
    if(logStatus == 0) printf("Invalid identity number or password\n"); // Error result is zero
    else if(logStatus == 1){
        float withMoney;
        printf("Login Successful!\n");
        printf("Enter your withdraw amount: ");
        scanf("%f",&withMoney);
        int money = withdrawable_amount(withMoney); // Get withdrawable_amount of money from function
        printf("Withdrawable amount is: %d\n",money);
    }
    return(0);
}
