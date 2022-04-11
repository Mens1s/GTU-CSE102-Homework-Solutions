#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2; 
    /* Basic Math algorithm aproach */
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2; 
    /* Basic Math algorithm aproach */
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = d1*n2;
    /* Basic Math algorithm aproach */
    if(*d3==0)printf("\033[1;31m |undefined| \033[0m"); /*If numerator is zero, the result will be undefined. Math rule*/
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int gcd = 1;
    int minus = 1;
    
    if((*n)<0 || (*d)<0){/* Controlling of minus number or numbers */
        if((*d)<0 && (*n)<0){ /* If both of numbers are under zero */
            minus = 1; /* Control multiplier set 1 because of => -(num)*-(num)=+(num)*/
            *d = (*d)*(-1); 
            *n = (*n)*(-1);
        }
        else if((*d)<0){/* If only one number is under zero */
            *d = (*d)*(-1); /* Denimator set positive and control multiplier set minus */
            minus = -1;/* Control multiplier set -1 because of => -(num)*+(num)=-(num)*/
        }
        else{ /* If only one number is under zero */
            *n = (*n)*(-1);/* Denimator set positive and control multiplier set minus */
            minus = -1;/* Control multiplier set -1 because of => -(num)*+(num)=-(num)*/
        }
    }
    for(int num = 1; num <= (*n) && num <= (*d) ; num++ ){
        if((*n)%num==0 && (*d)%num==0){
            gcd = num; /* I found gcd */ 
        }
    }
    *n = (*n)*minus/gcd;/* For beautiful output I set minus sign before of the first number and I divide numerator to gcd */
    *d = (*d)/gcd; /* I divide numerator to gcd */
} /* end fraction_div */
