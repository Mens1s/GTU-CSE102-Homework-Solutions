#include <stdio.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;/* We take char in here because of funtion prototype what teacher said in class so it can be produce an error! */
    return r;
}


/* Provide your implementations for all the requested functions here */

char dt1a(float pl,float pw, float sl, float sw){
    if(pl < 2.45) return 's';//setosa
    else if(pw < 1.65 && pl < 4.95) return 'v';//versicolor
    return 'i';//virginica
}

char dt1b(float pl, float pw, float sl, float sw){
    if(pl<2.55) return 's'; // setosa
    else if(pw<1.69 && pl<4.85) return 'v';//versicolor
    return 'i';//virginica
}

double dt2a(float x1, float x2, float x3, int x4, int x5){
    if(x1<31.5){
        if(x2>(-2.5)) return 5.0;
        else if(x2 - 0.1 <= x1 && x1 <= 0.1 + x2) return 2.1;
        return -1.1;
    }
    else{
        if(-1 <= x3 && x3 <= 2) return 1.4;
        else if(x4 == 1 && x5 == 1) return -2.23;
        else return 11.0;
    }
}

double dt2b(float x1, float x2, float x3, int x4, int x5){
    if(12<x1 && x1<22){
        if(x3>(5.0/3.0)) return -2.0;
        else if((x1 - 0.1 ) <= x3 && x3 <= (x1+0.1)) return 1.01;
        return -8;
    }
    else{
        if(x4==1 && x5==1) return -1;
        else if(-1<=x2 && x2<=2) return (-1.0/7.0);
        return  (0.47140452079);
    }
}

int dt3a(float rate, float pRate, float demand, int fearChoice, int buyerChoice){
    /*  
        1 => Strong Sell
        2 => Sell
        3 => Wait
        4 => Buy
        5 => Strong Buy
    */
    /*
    	rate => real number |The Rate of increase of money in the last week|
    	pRate => real number |PROJECT RATE|
    	demand => binary |ANY COMMUNITY support ?|
    	fearChoice => categorical number
    	buyerChoice => categorical number
    */
    if(rate>15){
        if(demand == 1){
            if(pRate < 6.8){
                if(buyerChoice == 1) return 1;
                else if(buyerChoice == 2) return 2;
                else if(buyerChoice == 3 || buyerChoice == 4) return 3;
                else if(buyerChoice == 5 || buyerChoice == 6) return 4;
                else return 5;
            }
            else{
                if(buyerChoice == 1) return 3;
                else if(buyerChoice == 2 || buyerChoice == 3 || buyerChoice == 4) return 4;
                else return 5;
            }
        }
        else {
            if(fearChoice == 1) return 1;
            else if(fearChoice == 2 || fearChoice == 4) return 4;
            else if(fearChoice == 3) return 3;
            else return 2;
        }
    }
    else{
        if(pRate < 5.15){
            if(demand == 1){
                if(buyerChoice == 1) return 1;
                else if(buyerChoice == 2 || buyerChoice == 3 || buyerChoice == 4) return 2;
                else if(buyerChoice == 5 || buyerChoice == 6) return 3;
                else return 4;
            }
            else return 1;
        }
        else if(pRate < 7.8){
            if(buyerChoice == 1) return 2;
            else if(buyerChoice == 2) return 4;
            else if(buyerChoice == 3 || buyerChoice == 4) return 4;
            else if(buyerChoice == 5 || buyerChoice == 6) return 5;
            else return 5;
        }
        else{
            if(fearChoice == 1) return 2;
            else if(fearChoice == 2 || fearChoice == 5) return 4;
            else if(fearChoice == 4) return 5;
            else{
                if(buyerChoice == 1 || buyerChoice == 2 || buyerChoice == 4 || buyerChoice == 7) return 3;
                else if(buyerChoice == 3 ||buyerChoice == 6) return 4;
                else return 5;
            }
        } 
    }
}
int dt3b(float rate, float pRate, float demand, int fearChoice, int buyerChoice){
    /*  
        1 => Strong Sell
        2 => Sell
        3 => Wait
        4 => Buy
        5 => Strong Buy
    */
    /*
    	rate => real number |The Rate of increase of money in the last week|
    	pRate => real number |PROJECT RATE|
    	demand => binary |ANY COMMUNITY support ?|
    	fearChoice => categorical number
    	buyerChoice => categorical number
    */
    if(pRate < 5.5){
        if(rate > 12){
            if(demand==1){
                if(buyerChoice == 1) return 1;
                else if(buyerChoice == 2) return 2;
                else if(buyerChoice == 3 || buyerChoice == 4) return 3;
                else if(buyerChoice == 5 || buyerChoice == 6) return 4;
                else return 5;
            }
            else return 1;
        }
        else {
            if(demand == 1){
                if(buyerChoice == 1) return 1;
                else if(buyerChoice == 2 || buyerChoice == 3 || buyerChoice == 4) return 2;
                else if(buyerChoice == 5 || buyerChoice == 6) return 3;
                else return 4;
            }
            else return 1;
        }
    }
    else if( pRate < 8.15){
        if(demand == 1){
            if(buyerChoice == 1) return 2;
            else if(buyerChoice == 2 ||buyerChoice == 3) return 3;
            else if(buyerChoice == 4 || buyerChoice == 5 || buyerChoice == 6) return 4;
            else return 5;
        }
        else{
            if(fearChoice == 1 || fearChoice == 2) return 2;
            else if(fearChoice == 3) return 3;
            else {
                if(buyerChoice == 1) return 2;
                else if(buyerChoice == 2 ||buyerChoice == 3) return 3;
                else if(buyerChoice == 4 || buyerChoice == 5 || buyerChoice == 6) return 4;
                else return 5;
            }
        }

    }
    else{
        if(fearChoice == 1) return 2;
        else if(fearChoice == 2 || fearChoice == 5) return 4;
        else if(fearChoice == 4) return 5;
        else{
            if(buyerChoice == 1 || buyerChoice == 2 || buyerChoice == 4) return 3;
            else if(buyerChoice == 3 ||buyerChoice == 6) return 4;
            else return 5;
        }
    }
}
