#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    int seqlen, xs;
    
    printf("Please enter the sequence lenght : ");
    scanf("%d",&seqlen);

    printf("Please enter the first element: ");
    scanf("%d",&xs);

    /* Start of second task */
    int loopLen = seqlen/2;
    int *arr = (int *) malloc( seqlen * sizeof(int) );
    /* Calling the check_loop_iterative function */
    check_loop_iterative( generate_sequence, xs, seqlen, arr, &loopLen);

    if(loopLen >= 2){
        printf("\nLoop: {");
        for(int a = 0; a < loopLen+1; a++){
            printf("%d, ", arr[a]);
        }
        printf("\b\b}\n\n");
    }
    /* End of second task */

    /* start of fourth task */
    int h[10] = {0};
    int digit = 0;
    hist_of_firstdigits(generate_sequence ,xs ,seqlen ,h , digit);

    printf("\nHistogram of the sequence: {");

    for(int a = 1 ; a <= 9 ; a++){
        printf("%d, ", h[a]);
    }

    printf("\b\b}\n\n");
    free(arr);
    return 0;
}

