#include <stdlib.h>
#include <stdio.h>
#include <string.h>

union Person{
    int id;
    char name[100];
    char address[100];
    int phone;
    int loanCount;
};

union Loan{
    float amount;
    float interestRate;
    int period;
    float total;
};

struct BankAccount{
    union Person Customer[5];
    union Loan Loans[3][4];
};

void listCustomers();
void addCustomer ();
void newLoan ();
double calculateLoan(float amount, int period, float interestRate);
void getReport();
int remain_in_stdin();
void clean_stdin();
int intControl();
float floatControl();
void updateFromDatabase();

/* GLOBAL VARIABLES to reach anywhere we want || we don't use function aarguments because of homework description so we have to choice this way */
int customersID[50] = {0};
int customerCount = 0;
struct BankAccount customers[50];

int main(){
    /*
    struct BankAccount ahmet;
    strcpy(ahmet.Customer[0].name , "ahmet");
    strcpy(ahmet.Customer[1].address , "evadresi");
    ahmet.Customer[2].phone = 1;
    printf("%s %s %d",ahmet.Customer[0].name,ahmet.Customer[1].address,ahmet.Customer[2].phone);
    */
    int choice;
    updateFromDatabase();
    do{ 
        printf("=====================================\n");
        printf("Welcome to the Bank Management System\n");
        printf("=====================================\n");
        printf("\t1. List All Customers\n");
        printf("\t2. Add New Customers\n");
        printf("\t3. New Loan Application\n");
        printf("\t4. Report Menu\n");
        printf("\t5. Exit System\n");
        printf("Choice : ");

        choice = intControl();

        if(choice == 1) listCustomers();
        else if(choice == 2) addCustomer();
        else if(choice == 3) newLoan();
        else if(choice == 4) getReport();
        else if(choice == 5);
        else printf("Please enter [1-5] numbers!\n");

    }while(choice != 5);
    

}

int remain_in_stdin(){
    /*
        With this function I control of users last input which can includes non numeric char or not
        example input = 13'd'
        scanf cannot control of last digit or char in a input 
        -1 mean == it include
         0 mean == don't include
         10 mean == 'ENTER'
    */
    int x;
    do {
        x = getchar();
        if(x != 10) return -1;
        return 0;
    } while (x != '\n' && x != EOF );
}

void clean_stdin()
{   /*
        With this function I clean buffer for next scanf work perfectly.
    */
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int intControl(){
    int choice;
    int control = scanf("%d",&choice);
    int control_buffer = remain_in_stdin();
        /*
            With this while loop Code is controlling of:
                User entered right type of input
                User entered right number of input
                User entered right number without char
            control Variable == control of inputs number
            control_buffer   == control of last digit includes char or not
        */
    while( control_buffer == -1 || control == 0 ){
        printf("Please enter again correctly : ");

        if(control_buffer == -1) clean_stdin(); /* If last char doen't include char we don't need to clean buffer again */

        control = scanf("%d",&choice);
        control_buffer = remain_in_stdin();
    }
    return choice;
}

float floatControl(){
    float choice;
    int control = scanf("%f",&choice);
    int control_buffer = remain_in_stdin();
        /*
            With this while loop Code is controlling of:
                User entered right type of input
                User entered right number of input
                User entered right number without char
            control Variable == control of inputs number
            control_buffer   == control of last digit includes char or not
        */
    while( control_buffer == -1 || control == 0 ){
        printf("Please enter again correctly : ");

        if(control_buffer == -1) clean_stdin(); /* If last char doen't include char we don't need to clean buffer again */

        control = scanf("%f",&choice);
        control_buffer = remain_in_stdin();
    }
    return choice;
}
/*
    function name : listCustomers
    function lists all customers in struct and unions
        function has a loop algorithm to reach and print all of them one by one
    return none
*/
void listCustomers(){
    int control = 0;
    int flag = 0;
    for(int customerIDX = 0; customerIDX < customerCount  ; customerIDX++){
        control = 0;
        flag = 1;
        float sum = 0;
        printf("Customer ID : %d\n",customers[customerIDX].Customer[0].id);
        printf("Customer Name : %s\n",customers[customerIDX].Customer[1].name);
        printf("Customer Phone = %d\n",customers[customerIDX].Customer[2].phone);
        printf("Customer Address = %s\n",customers[customerIDX].Customer[3].address);

        printf("Loans = [");
        for(int a = 0; a < customers[customerIDX].Customer[4].loanCount ; a++){
            sum += customers[customerIDX].Loans[a][3].total;
            printf("%f + ",customers[customerIDX].Loans[a][3].total);
            control = 1;
        }
        if(control == 1)printf("\b\b] => %f\n\n",sum);
        else  printf("\b\b\b\b\b\b\b\b\bNo Loan Found!\n\n");
    }
    if(flag == 0) printf("No Customer Found!\n\n");
}
/*
    function name : addCustomer
    function creates new customer 
        new customer's information stores in 5 different union by using struct
        also
        new customer's information writen to file which is called customers.txt
    return none
*/
void addCustomer(){
    if(customerCount >= 50 ){
        printf("You Reached Maximum Customer Count!\n\n");
        return;
    }
    int id, phone, loanCount, period[3];
    float loan[3], interestRate[3];
    char name[100] = {0}, address[100] = {0};

    printf("Customer ID : ");
    id = intControl();

    for(int a = 0; a < customerCount; a++){
        if(customersID[a] == id) {
            printf("This ID is already using please enter different ID : ");
            id = intControl();
            a = -1;
        }
    }
    
    customersID[customerCount] = id;
    
    customers[customerCount].Customer[0].id = id;

    printf("Customer Name : ");
    scanf(" %[^\n]%*c", customers[customerCount].Customer[1].name);
    
    int a = 0;
    
    while(customers[customerCount].Customer[1].name[a] != 0){

        if( (int) customers[customerCount].Customer[1].name[a] >= 65 && (int) customers[customerCount].Customer[1].name[a] <= 90);
        else if( (int) customers[customerCount].Customer[1].name[a] >= 97 && (int) customers[customerCount].Customer[1].name[a] <= 122);
        else if( (int) customers[customerCount].Customer[1].name[a] == ' ' );
        else{
            printf("Wrong Typing Please enter name again (only character) : ");
            scanf(" %[^\n]%*c", customers[customerCount].Customer[1].name);
            a = -1;
        }
        a++;
    }

    printf("Customer Phone = ");
    customers[customerCount].Customer[2].phone = intControl();

    printf("Customer Address = ");
    scanf("%24[^\n]", customers[customerCount].Customer[3].address);

    FILE *data  = fopen("customers.txt","a+");

        if(data == NULL) printf("File does not created or find please check your permisions!\n");
        
        else {

            fprintf(data,"%d NAME= %s PHONE= %d  ADDRESS= %s ENDUSER\n", customers[customerCount].Customer[0].id,
                                            customers[customerCount].Customer[1].name, 
                                            customers[customerCount].Customer[2].phone,
                                            customers[customerCount].Customer[3].address);
            
            fclose(data);
        }
    printf("\nOperation has done succesfully. New Customer Added!\n\n");
    customerCount++;
}
/*
    function name : newLoan
    function creates new loana
        new loan's information stores in 4 different union by using struct
        also
        new loan's information writen to file which is called loan.txt
    return none
*/
void newLoan(){
    
    printf("Customer ID to open LOAN : ");
    int id = intControl();
    int idCheck  = 0;
    int idx;

    for(idx = 0; idx < customerCount && idCheck == 0; idx++){
        if(customers[idx].Customer[0].id == id) {
            idCheck = 1;
        }
    }
    idx--;
    if(idCheck == 0) printf("This Customer Id doesn't blong to any customer, we redirect you to main page!\n");
    else{
        int a = customers[idx].Customer[4].loanCount;
        while(customers[idx].Customer[4].loanCount >= 3) {
            printf("Customers have only 3 amount of loan we redirect you to main page \n");
            return;
        }
        printf("Customer %d. loan amount = ",a+1);
        customers[idx].Loans[a][0].amount = floatControl();
        while(customers[idx].Loans[a][0].amount <= 0){
            printf("Enter bigger than zero numbers : ");
            customers[idx].Loans[a][0].amount = floatControl();
        }   
        printf("Enter interest rate = ");
        customers[idx].Loans[a][1].interestRate = floatControl();
        while(customers[idx].Loans[a][1].interestRate <= 0){
            printf("Enter bigger than zero numbers : ");
            customers[idx].Loans[a][1].interestRate = floatControl();
        }
        printf("Enter period : ");
        customers[idx].Loans[a][2].period = intControl();
        while(customers[idx].Loans[a][2].period <= 0){
            printf("Enter bigger than zero numbers : ");
            customers[idx].Loans[a][2].period = floatControl();
        }
        /* Writing customers information to txt file */
        FILE *data  = fopen("loan.txt","a+");

        if(data == NULL) printf("File does not created or find please check your permisions!\n");
        
        else {
            
            customers[idx].Loans[a][3].total = calculateLoan( customers[idx].Loans[a][0].amount,
                                               customers[idx].Loans[a][2].period,
                                               customers[idx].Loans[a][1].interestRate);

            fprintf(data,"%d %f %f %d %f\n", 
                                            customers[idx].Customer[0].id,
                                            customers[idx].Loans[a][0].amount, 
                                            customers[idx].Loans[a][1].interestRate,
                                            customers[idx].Loans[a][2].period,
                                            customers[idx].Loans[a][3].total);

            int period = customers[idx].Loans[a][2].period;
            float monthlyPayment =  customers[idx].Loans[a][3].total / (float) customers[idx].Loans[a][2].period;    

            for(int a = 0; a < period ; a++){
                fprintf(data,"%d. => Monthly Installemnt = %f\n", 
                                            a+1,
                                            monthlyPayment);
            }
            fclose(data);

        }
        (customers[idx].Customer[4].loanCount)++;
    }
    
    return;
}
/*
    function name : calculateLoan
    function calculates amount of money by recursive
    return double
*/
double calculateLoan(float amount, int period, float interestRate){
    if(period == 0) return amount;
    return  (1.00 + interestRate) * calculateLoan(amount, period - 1, interestRate) ;
}
/*
    function name : getReport
    function gets all information report by using .txt files
        this function can report
            1- all PERSONAL INFORMATION
            or
            2- all Loan Information
                1- Get Loan by Customer ID 
                    Function reports only ID' loans

                2- Get All Customers 
                    Function reports all loan's 

                3- Get All Monthly Payment
                    Function calculates all monthly payment of all customers and print it mounth by mounth
    return none
*/
void getReport(){
    int choice;
    printf("===========\n");
    printf("REPORT MENU\n");
    printf("1. Personal Information\n");
    printf("2. Loan Information\n");
    printf("===========\n");
    choice = intControl();

    while((choice <= 0|| choice > 2)){
        printf("Please enter 1 or 2 : ");
        choice = intControl();
    }

    if(choice == 1){
        FILE *data  = fopen("customers.txt","r");
        char word[100] = {0};
        /*"%d NAME= %s PHONE= %d  ADDRESS= %s 0*/
        if(data == NULL) printf("File does not created please add customers!\n");
        else{
            while(fscanf(data, "%s", word) == 1){
                printf("Customer ID : %s\n",word);
                fscanf(data, "%s", word);
                printf("Customer Name : ");
                fscanf(data, "%s", word);
                while(strcmp("PHONE=", word) != 0){
                    printf("%s ",word);
                    fscanf(data, "%s", word);
                }

                fscanf(data, "%s", word);
                printf("\nCustomer Phone : %s\n",word);

                fscanf(data, "%s", word);
                printf("Customer Address : ");
                fscanf(data, "%s", word);
                while(strcmp("ENDUSER", word) != 0){
                    printf("%s ",word);
                    fscanf(data, "%s", word);
                }
                printf("\n\n");
                
            }
            fclose(data);
        }
    }
    else{
        printf("===========================\n");
        printf("1-) Get by Customer ID\n");
        printf("2-) Get All Customers \n");
        printf("3-) Get All Monthly Payment\n");
        printf("===========================\n");
        choice = intControl();

        while((choice <= 0|| choice > 3)){
            printf("Please enter 1, 2 or 3 : ");
            choice = intControl();
        }

        FILE *data  = fopen("loan.txt","r");

        int control = 0, period;
        char word[100] = {0}, t1[20] = {0}, t2[20] = {0}, t3[20] = {0}, t4[20] = {0}, t5[20] = {0}, t0[20] = {0};
        if(choice == 1){
            char id[20] = {0};
            int sLoan = 0;

            printf("Enter ID : ");
            scanf("%24[^\n]", id);

            printf("Enter Loan Count (1 or 2 or 3) : ");
            sLoan = intControl();
            int counter = 1;

            if(data == NULL) printf("File does not found please add customers!\n");
            else{
                while(fscanf(data, "%s", word) == 1){
                    if(strcmp(word,id) == 0){
                        if(counter == sLoan){
                            fscanf(data, "%s %s %d %s",t1,t2,&period,t3);
                            printf("Total Credit Value : %s\n",t3);

                            for(int a = 0; a < period; a++){
                                fscanf(data, "%s %s %s %s %s %s",t0,t1,t2,t3,t4,t5);
                                printf("%s %s %s %s %s %s\n",t0,t1,t2,t3,t4,t5);
                            }
                            control = 1;
                        }
                        counter++;
                    }
                }
                fclose(data);
                if(control == 0) printf("No loan request found!\n");
            }
        }
        else if(choice == 2){
            if(data == NULL) printf("File does not found please add customers!\n");
            else{
                while(fscanf(data, "%s", word) == 1){
                    int contDOT = 0;
                    for(int a = 0 ; a < strlen(word); a++)
                        if(word[a] == '.') contDOT = 1;
                    
                    if(contDOT == 0){
                        printf("CUSTOMER ID : %s\n",word);
                        fscanf(data, "%s %s %d %s", word,word,&period,word);
                        printf("Total Credit Value = %s\n",word);
                        for(int a = 0; a < period; a++){
                            fscanf(data, "%s %s %s %s %s %s",t0,t1,t2,t3,t4,t5);
                            printf("%s %s %s %s %s %s\n",t0,t1,t2,t3,t4,t5);
                        }
                        control = 1;
                    }
                }
                fclose(data);
                if(control == 0) printf("No loan request found!\n");
            }
        }
        else{
            int max = 0;
            if(data == NULL) printf("File does not found please add customers!\n");
            else{
                while(fscanf(data, "%s", word) == 1){
                    int contDOT = 0;
                    for(int a = 0 ; a < strlen(word); a++)
                        if(word[a] == '.') contDOT = 1;
                    
                    if(contDOT == 0){
                        fscanf(data, "%s %s %d %s", word,word,&period,word);
                        for(int a = 0; a < period; a++){
                            fscanf(data, "%s %s %s %s %s %s",t0,t1,t2,t3,t4,t5);
                        }
                        control = 1;
                    }
                    if(period > max) max = period;
                }
                fclose(data);

                if(control == 0) printf("No loan request found!\n");
                else{
                    double *monthlyPayment = (double *) malloc(max * sizeof(double) );
                    int per = 0;
                    float sum = 0;            
                    float temp = 0;        
                    data = fopen("loan.txt","r");

                    for(int a = 0; a < max ; a++)monthlyPayment[a] = 0;

                    while(fscanf(data, "%s", word) == 1){
                        int contDOT = 0;
                        for(int a = 0 ; a < strlen(word); a++)
                            if(word[a] == '.') contDOT = 1;
                        
                        if(contDOT == 0){
                            fscanf(data, "%s %s %d %f", word,word,&period,&temp);
                            sum += temp;
                            for(int a = 0; a < period; a++){
                                fscanf(data, "%s %s %s %s %s %f",t0,t1,t2,t3,t4,&temp);
                                monthlyPayment[a] += temp;
                            }
                        }
                    }
                    printf("Total Credit Value = %f\n",sum);
                    for(int a = 0; a < max; a++){
                        printf("%d. Month Installment = %lf\n",a+1,monthlyPayment[a]);
                    }
                }   
            }
        }  
    }
}
/*
    function name : updateFromDatabases
        function updates unions and structs. 
        If program worked once earlier this function takes all values and updates struct and unions correctyl for using more time than before
    return none
*/
void updateFromDatabase(){
    FILE *data  = fopen("customers.txt","r");
    char word[100] = {0};
    /*"%d NAME= %s PHONE= %d  ADDRESS= %s 0*/
    if(data == NULL);
    else{
        printf("Wait.. We are checking and updating your program from databases..\n\n");
        while(fscanf(data, "%s", word) == 1){
            /* LOAN COUNT UPDATE */
            FILE *datafromloan  = fopen("loan.txt","r");
            char wordfromloan[100];
            int tempID = atoi(word);
            int period = 0;
            if(datafromloan == NULL);
            else{
                int cLOAN = 0;
                while(fscanf(datafromloan, "%s", wordfromloan) == 1){
                    int contDOT = 0;
                    for(int a = 0 ; a < strlen(wordfromloan); a++)
                        if(wordfromloan[a] == '.') contDOT = 1;
                    if(contDOT == 0){
                        if(strcmp(word, wordfromloan) == 0){
                            fscanf(datafromloan, "%s %s %d %s", wordfromloan,wordfromloan,&period,wordfromloan);
                            customers[customerCount].Loans[cLOAN][3].total = atof(wordfromloan);
                            for(int a = 0; a < period; a++){
                                fscanf(datafromloan, "%s %s %s %s %s %s",wordfromloan,wordfromloan,wordfromloan,wordfromloan,wordfromloan,wordfromloan);
                            }
                            (customers[customerCount].Customer[4].loanCount)++;
                            
                            cLOAN++;
                        }
                        
                    }
                }
                fclose(datafromloan);
            }
            /*LOAN COUNT UPDATE END*/
            int id = atoi(word);
            customersID[customerCount] = id;
            customers[customerCount].Customer[0].id = id;

            fscanf(data, "%s", word);
            char tempName[100] = {0};
            fscanf(data, "%s", word);
            while(strcmp("PHONE=", word) != 0){
                strcat(word," ");
                strcat(tempName,word);
                fscanf(data, "%s", word);
                
            }
            strcpy(customers[customerCount].Customer[1].name, tempName);

            fscanf(data, "%s", word);
            int phone = atoi(word);
            customers[customerCount].Customer[2].phone = phone;

            fscanf(data, "%s", word);
            char tempAddres[100] = {0};
            fscanf(data, "%s", word);
            while(strcmp("ENDUSER", word) != 0){
                strcat(word," ");
                strcat(tempAddres,word);
                fscanf(data, "%s", word);
            }
            strcpy(customers[customerCount].Customer[3].address, tempAddres);
            customerCount++;
        }
        fclose(data);
    }
    
}
