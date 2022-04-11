#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z){
    if(z==0) return 0; // if division is zero, it is impossible to divide
    for(x+=1;x<y;x++) if (x%z==0) return x; // x is our start number to y and we have to find first 
    return 0;                            // divisible number by 'z' variable
}

int find_nth_divisible(int n, int f_I, int z){
    if(z<=n+f_I) return -999; // z is end number so if z smaller than addition we have to return error code
    return n+f_I; // returned one step ahead number
}

int validate_identity_number(char identity_number [ ]){
    int len = 0;
    int odd = 0, even = 0;
    int sum_of_tc = 0;

	if(identity_number[0]=='0') return 0; // control of first number can not be '0'
    while(identity_number[len] != '\0') { // get all number
        if((int)identity_number[len]<=48 && (int)identity_number[len]>57) return 0; // checking all values are digit

        if(len%2==0 && len<9) odd += (int)identity_number[len]-48; // getting odd index numbers and add to odd variable until to 9. index
        else if(len<9) even += (int)identity_number[len]-48;    // getting even index numbers and add to even variable until to 9. index
        if(len!=10) sum_of_tc += (int)identity_number[len]-48; // getting addition of first 10 digit

        len++;
    }
    if(len!=11) return 0; // control of len is 11
    if( (odd*7-even) %10 != (int)identity_number[9]-48) return 0; // control of 4th number
    if( (sum_of_tc) %10 != (int)identity_number[10]-48) return 0; // checking of sum of 10 digit mods 10 gives last digit
    return 1;// returning True 
}

int create_customer(char identity_number [ ], int password){
    FILE *acc;
    acc = fopen("customeraccount.txt","w"); // opening file which is named customeraccount.txt

    if(acc == NULL) printf("Error! File can not created! Please check your permissions!\n");//if any error this line gives a input to user              
    else fprintf(acc,"%s,%d",identity_number,password);// writing identity number and password to file

    fclose(acc); // closing file
}
int check_login(char identity_number [ ], int password){
	FILE *acc;
    char id[20], temp;
    int paswd;
	if((acc=fopen("customeraccount.txt","r"))== NULL) { // opening file
		printf("Error, file couldn't open!"); 
		return 2;	//return error code
	}
	for(int i=0;i<11;i++) fscanf(acc,"%c",&id[i]);
		
    fscanf(acc,"%c",&temp);//this fscanf for ','
	fscanf(acc,"%d",&paswd);

    for(int a = 0;a<11;a++) if(identity_number[a]!=id[a]) return(0);
    if(paswd!=password) return 0;

    fclose(acc);
    return 1;	// retutning True	
}


int withdrawable_amount(float cash_amount){
    float first_money = cash_amount;
    while(cash_amount>=50) cash_amount -= 50; // giving 50 liras until it is imposible
    while(cash_amount>=20) cash_amount -= 20; // giving 20 liras until it is imposible
    while(cash_amount>=10) cash_amount -= 10; // giving 10 liras until it is imposible
    return first_money-cash_amount; // returning available money 
}   
