#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 2147483647

void part1();
int sum(int num1, int num2, int flag);
int multi(int num1, int num2, int flag);
int isprime(int i);
void print_file();
void sort_file();

int main() {

    /* Variable declartation */
    int choice = 0;

    while(choice!=5){

        printf("Select operation \n 1. Calculate sum/multiplication between two numbers\n 2. Calculate prime numbers\n 3. Show number sequence in file\n 4. Sort number sequence in file \n 5. Exit\n---------------------------------------\n");
        scanf("%d",&choice);
        
        if(choice == 1) part1();
        else if(choice == 2){
            int num;
            printf("Please enter an integer : ");
            scanf("%d",&num);

            while(num<=2){
                printf("Please enter a number which is bigger than 2 : ");
                scanf("%d",&num);
            }
            for(int i = 2; i < num ; i++){
                if(isprime(i)==(-1)) printf("%d is a prime number.\n",i); 
                else printf("%d is not a prime number, it is dividible by %d.\n",i,isprime(i));
            }printf("\n");
        }
        else if(choice == 3) print_file();
        else if(choice == 4) sort_file();
        else if(choice == 5);
        else printf("Wrong number selection please try again!\n");

    }

    return 0;
}

void part1(){
    /* Variable declartation */
    int op1Result = 1;
    int op2Result = 1;
    int opFlag = 2;
    int flag = 2;
    int num1 = 2, num2 = 2;
    int control = 0;

    printf("Select operation \nPlease enter '0' for sum, '1' for multiplication. \n");
    scanf("%d",&opFlag); // control of opFlag is in 88. line.
    do{
        switch (opFlag){
        case 0:
            control = 0;
            break;
        case 1:
            control = 0;
            break;
        default:
            printf("Wrong operation type please enter CORRECT type.\n0 for sum 1 for multiplication : \n");
            scanf("%d",&opFlag);  // Checking to input a correct FLAG
            control = 1;
            break;
        }
    }while(control != 0) ;


    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
    do{
        scanf("%d",&flag);
        switch (flag){
        case 0:
            control = 0;
            break;
        case 1:
            control = 0;
            break;
        default:
            printf("Wrong operation type please enter CORRECT type.\n0 for even numbers 1 for odd numbers : \n");
            control = 1;
            break;
        }
    }while(control != 0) ;

    printf("Please enter two different number:\n");

    while(num1 == num2){
        printf("Number 1 : ");
        scanf("%d",&num1);
        printf("Number 2 : ");
        scanf("%d",&num2);
        if(num1 == num2) printf("Please enter two different numbers\n");
    }
    if(num1 > num2){
        printf("Your N1 is bigger than N2 so we change them...\n");
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    do{
        switch (opFlag){
        case 0:
            op1Result = sum(num1+1, num2, flag); 
            control = 0;
            break;
        case 1:
            op2Result = multi(num1+1, num2 , flag);
            control = 0;
            break;
        default:
            printf("Wrong operation type please enter CORRECT type.\n0 for sum 1 for multiplication : \n");
            scanf("%d",&opFlag);  // Checking to input a correct FLAG
            control = 1;
            break;
        }
    }while(control != 0) ;
    
    if(op1Result == 0 || op2Result == 0) printf("\nThe result is written to the result.txt file.\n");

}

void write_file(int number){
    FILE *file  = fopen("results.txt","a+");

    if(file == NULL) printf("File does not created or find please check your permisions!\n");
    
    else {
        fprintf(file,"%d ",number);
        fclose(file);
    }
    
}

void print_file(){
    FILE *file  = fopen("results.txt","r");
    int number;

    if(file==NULL) printf("File does not created or find please check your permisions!\n");
    else{
        printf("Result :\n");
        while(fscanf(file, "%d", &number) == 1){
            printf("%d ",number);
        }
        printf("\n");
        fclose(file);
    }

    
}

int isIn(int num){/*This function controls our current number is inside of our temp file */
    FILE *file = fopen("temp.txt","r");
    
    int number;
    if(file==NULL) printf("File does not created or find please check your permisions!\n");

    else{
        while(fscanf(file, "%d", &number) == 1){
            if(num == number) {
                fclose(file);
                return 1;
            }
        } fclose(file);
    }

    return 0;
}

int countNumber(){ /* This function checks our results file how many numbers includes */
    FILE *file = fopen("results.txt","r"); 
    int number;
    int counter = 0;
    if(file==NULL) printf("File does not created or find please check your permisions!1\n");
         
    else{
        while(fscanf(file, "%d", &number) == 1) counter++;
        fclose(file);
    }
    
    return counter; /* Returning count of number in results file */
}

int countExactNumber(int num, int flag){/* This function counts exact number how many repeats in our results.txt or temp.txt */
    if(flag == 1){
        FILE *file = fopen("results.txt","r"); 
        int number;
        int counter = 0;
        if(file==NULL) printf("File does not created or find please check your permisions!\n");
        else{
            while(fscanf(file, "%d", &number) == 1){
                if(number == num) counter++;
            }
            fclose(file);
        }
        
        return counter; /* Returning count of number in results file */    
    }
    else{
        FILE *file = fopen("temp.txt","r"); 
        int number;
        int counter = 0;
        if(file==NULL) printf("File does not created or find please check your permisions!\n");
        else{
            while(fscanf(file, "%d", &number) == 1){
                if(number == num) counter++;
            }
            fclose(file);
        }
        
        return counter; /* Returning count of number in temp file */   
    }
    
}

void sort_file(){
    int cn = countNumber();
    if(cn == 0){
        printf("Please firstly work with part-1 or create 'result.txt' and after work it!\n");
    }
    else{
        int number, cTemp = 0;

        FILE *temp_file = fopen("temp.txt","w");
        fclose(temp_file);

        while(cTemp < cn){ /* checking our resuls.txt and temp.txt has a same amount of value */
            FILE *file = fopen("results.txt","r");
            int first = MAX, second = MAX, third = MAX; /* Because int maks value! */
            int counter = 0;
            
            while(fscanf(file, "%d", &number) == 1){
                
                if(isIn(number) == 1){ /* if number is in our results txt also our counter is less than temp.txt values */
                    int exact = countExactNumber(number, 1);
                    int inTemp = countExactNumber(number, 2);
                    if(exact > inTemp+counter){
                        if(number < first){
                            third = second;
                            second = first;
                            first = number;
                        }
                        else if(number < second){
                            third = second;
                            second = number;
                        }
                        else if(number < third){
                            third = number;
                        }counter++;
                    }
                }
                else{
                    /* SORTING NUMBERS */
                    if(number < first){
                        third = second;
                        second = first;
                        first = number;
                    }
                    else if(number < second){
                        third = second;
                        second = number;
                    }
                    else if(number < third){
                        third = number;
                    }
                }
            }
            /* Checking our numbers is changed or not and add the temp.txt */
            FILE *temp = fopen("temp.txt","a+"); /* I dont use write_file because we don't send any flag to which file which time so I did it in here */
            if(third==MAX){
                if(second == MAX){
                    if(first == MAX) break;
                    else fprintf(temp,"%d ",first);
                    cTemp++;
                }
                else{
                    fprintf(temp,"%d %d ",first,second);
                    cTemp += 2;
                } 
            }
            else if(second == MAX){
                if(first == MAX) break;
                else fprintf(temp,"%d ",first);
                cTemp += 1;
            }
            else{
                fprintf(temp,"%d %d %d ",first, second, third);
                cTemp += 3;
            }
            fclose(temp);
            fclose(file);
            /* TEST for 3 by 3 */
            /*
            printf("waiting... %d : ",first);
            scanf("%d",&first);
            */
            /* End of sorting */
        }
        FILE *orderedFile = fopen("temp.txt","r");
        FILE *results  = fopen("results.txt","w");/* Clear results.txt */
        fclose(results);
        while(fscanf(orderedFile, "%d", &number) == 1){
            write_file(number);/* Writing sorting numbers to result.txt */
        }
        fclose(orderedFile);
	    printf("Result is :\n");
	    print_file();
    }
    
}

int sum(int n1, int n2, int flag){
    /* Variable declaration */
    int sum = 0;

    printf("Result\n");
    if(flag==0){


        if(n1 % 2 != 0) n1++; /* If user wants to work with even numbers so we add 1 to n1 which is odd and turns it to even! */
        
        if(n1==n2){
            printf("NO RESULT!\n");
        }
        else{
            printf("%d ",n1);  
            sum += n1;
            n1 += 2;         
            for(int i = n1 ; i < n2; i += 2){
                printf("+ %d ",i);
                sum += i;
            }

            printf(" = %d",sum);            
        }
        
    }
    else{
        if(n1 % 2 == 0) n1++; /* If user wants to work with odd numbers so we add 1 to n1 which is even and turns it to odd! */
        
        if(n1 == n2){
            printf("NO RESULT!\n");
        }
        else{
            printf("%d ",n1); 
            sum += n1; 
            n1 += 2;    
            for(int i = n1 ; i < n2; i += 2){
                printf("+ %d ",i);
                sum += i;
            }

            printf(" = %d\n",sum);
        }
        
    }
    /* We can return sum and also write results in main function too but this is not specified in homework PDF */
    write_file(sum);
    return 0;
}

int multi(int n1, int n2, int flag){
    /* Variable declaration */
    int multi = 1;

    printf("Result\n");
    if(flag == 0){

        if(n1 %2 != 0) n1++; /* If user wants to work with even numbers so we add 1 to n1 and turns it to even! */
        
        if(n1==n2){
            printf("NO RESULT!\n");
        }
        else{
            printf("%d ",n1);
            multi *= n1;  
            n1+=2;                 
            for(int i = n1 ; i < n2; i += 2){
                printf("* %d ",i);
                multi*=i;
            }

            printf(" = %d",multi);
        }
        
    }
    else{
        if(n1 % 2 == 0) n1++; /* If user wants to work with odd numbers so we add 1 to n1 and turns it to odd! */
        
        if(n1==n2){
            printf("NO RESULT!\n");
        }
        else{
            printf("%d ",n1);  
            multi *= n1; 
            n1 += 2;       
            for(int i = n1 ; i < n2; i += 2){
                printf("* %d ",i);
                multi*=i;
            }

            printf(" = %d\n",multi);
        }

    }
    /* We can return sum and also write results in main function too but this is not specified in homework PDF */
    write_file(multi);
    return 0;
}

int isprime(int a){
    for(int i = 2; i <= sqrt(a) ; i++){
        if(a % i == 0) return i; /* if there is any number divide the number, we return it instantly */
    }
    return -1; /* that is flag number of any number can divide so it is prime ! */
}
