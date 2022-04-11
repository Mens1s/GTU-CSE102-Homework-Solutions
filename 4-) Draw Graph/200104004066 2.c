#include <stdio.h>
#include <stdlib.h>

void part1();
void part2();
void part3();
int drawGraph(int a, int b, int c);
int drawGraph_txt(int a, int b, int c);

int main() {
    int choice;
    do
    {
        printf("Select an operation...\n1 -> Enter the coefficients.\n2 -> Draw the graph.\n3 -> Print the graph into a .txt file.\n4 -> Exit.\n\nChoice : ");
        scanf("%d",&choice);
        //Taking user choice as a input
        if(choice == 1) part1();
        else if(choice == 2) part2();
        else if(choice == 3) part3();
        else if(choice == 4) printf("Thanks for using program. Exitting.\n");
        else printf("You are selecting wrong number please select from list.\n");

    } while (choice!=4);
    
    return 0;
}

void part1(){
    //User enters inputs
    int a, b, c;
    char tChar = '\n';
    printf("Please enter the coefficient for the following equation: x = (a)*(y*y) + b*y +c \n");

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    FILE *file = fopen("coefficients.txt","w");
    
    if(file == NULL) printf("File cannot be created please check your permissions!\n\n"); /* if file can not created print a error message*/
    else{
        fprintf(file,"%d%c%d%c%d",a,tChar,b,tChar,c); /* writing user inputs to coefficients.txt */
        printf("\ncoefficients.txt file has been created.\n\n");
        fclose(file);    
    }
    
}

void part2(){
    FILE *file = fopen("coefficients.txt","r");
    int a, b, c;
    int counter = 0;

    if(file == NULL) printf("Your coefficients.txt has not created please do part1 after that do part2.\nWe direct you main choice menu\n\n"); /* if file can not created print a error message*/
    else{
        /* Checking parameters and number of parameters are correct or not */
        while(fscanf(file, "%d", &a) == 1)counter++;
        fclose(file);
        if(counter == 3){
            file = fopen("coefficients.txt","r");
            fscanf(file, "%d", &a);
            fscanf(file, "%d", &b); 
            fscanf(file, "%d", &c);

            drawGraph(a, b, c);    

        }
        else{
            printf("Your coefficients.txt has not include 3 numbers so do part1 firstly or enter 3 number line by line by your hand!\n\n");
        }
        fclose(file);
    }

    
}

void part3(){
    FILE *file = fopen("coefficients.txt","r");
    int a, b, c;
    int counter = 0;

    if(file == NULL) printf("Your coefficients.txt has not created please do part1 after that do part3.\nWe direct you main choice menu\n\n"); /* if file can not created print a error message */
    else{
        /* Checking parameters are correct or not */
        while(fscanf(file, "%d", &a) == 1)counter++;
        fclose(file);
        if(counter == 3){
            /* Taking a b c values from .txt */
            file = fopen("coefficients.txt","r");
            fscanf(file, "%d", &a);
            fscanf(file, "%d", &b); 
            fscanf(file, "%d", &c);

            printf("\nCoefficients has been read from the coefficient file.\n");

            int result = drawGraph_txt(a, b, c);    
            if(result == 1) printf("The graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt file.\n\n",a,b,c);
            else printf("File cannot be created please check your permissions!\n");
        }
        else{
            printf("Your coefficients.txt has not include 3 numbers so do part1 firstly or enter 3 number line by line by your hand!\n\n");
        }
        fclose(file);
    }

    
}
/* Graph is draw in terminal */
int drawGraph(int a, int b, int c){
    printf("\nCoefficients has been read from the coefficient.txt file.\n");
    printf("Printing the graph of x=%d(y*y) + %d*y + %d\n\n",a,b,c);
    for(int y = 16; y >=-16; y--){ /* Y Line loop */
        int control = 0;
        int counter = 0;
        int control_x = 0;
        for(int x = -56; x <= 56; x++){ /* X line loop */
            
            if(y==16 && x == 0) printf("^");

            else if( (a*(y*y) + b*y + c) == x && y != 16){
                printf("\033[1;34m#\033[0m");
                if(y == -1){ /* control of y values and take an action for preventing of deleting '#' */
                    if(x%10 == -1 ) { 
                        control = 1;
                        counter = -2;
                    }
                    else if(x%10 == -2 && x != -2 ) {
                        control = 2;
                        counter = -2;
                    }
                    else if(x%10 == 9){
                        control = 2;
                        counter = -1;
                    }
                } 
                if( x==-2 || x==-3) control_x = 3;
                    
                
            }

            else if(x == -56 && y == 0) printf("<");
            else if(x == 56 && y== 0) printf(">");
            else if(x == 0) printf("|");  

            else if(y == 0)  printf("-");
            /* Printing Y values on the default graph */
            else if((y%5 == 0  && x == -1) && control_x != 3) {
                if(y<-5) printf("\033[1;32m\b\b%d\033[0m",y);
                else if(y < 0)  printf("\033[1;32m\b%d\033[0m",y);
                else if(y < 10) printf("\033[1;32m%d\033[0m",y);
                else printf("\033[1;32m\b%d\033[0m",y);
            }

            else if(y == -1 && x == -1){
                printf("\033[1;32m0\033[0m");
            }
            /* Printing X values on the default graph */
            else if(y == -1){
                if(x%10 == 0){
                    if(x <= 0 ){ /* control of y values and take an action for preventing of deleting '#' */
                        
                        if(control == 0) printf("\033[1;32m\b\b%d\033[0m",x);   
                        else if(control == 1) printf("\033[1;32m%d\033[0m",x);
                        else printf("\033[1;32m%d\033[0m",x); 
                    }
                    else {
                        if(control == 0) printf("\033[1;32m\b%d\033[0m",x);   
                        else printf("\033[1;32m%d\033[0m",x);
                    }
                }                    
                else {
                    if(control != 0){
                        counter++;
                        if(counter == 0) control = 0;
                    }
                    else printf(" ");
                
                }
            }
            /* End of Printing X values */
            else printf(" ");

            
        }printf("\n");

    }
    return 1;
}
/* Draw graph to txt file */
int drawGraph_txt(int a, int b, int c){
    FILE *file = fopen("graph.txt","w");
    if(file == NULL) return 0;
    for(int y = 16; y >=-16; y--){
        for(int x = -56; x <= 56; x++){

            if(y==16 && x == 0) fputc('^',file);

            else if( (a*(y*y) + b*y + c) == x && (y!=16)) fputc('#',file);
            else if(x == -56 && y == 0) fputc('<',file);
            else if(x == 56 && y== 0) fputc('>',file);
            else if(x == 0) fputc('|',file);  
            else if(y == 0)  fputc('-',file);

            else fputc(' ',file);
        }fputc('\n',file);
	  
    }
    fclose(file);
    return 1;
}
