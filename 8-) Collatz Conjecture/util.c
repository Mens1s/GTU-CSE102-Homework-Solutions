#include <stdio.h>
#include <stdlib.h>
#include "util.h"
/*
    function name : generate_sequence
    function generates sequence recursivly

    return none
*/
void generate_sequence (int xs, int currentlen, int seqlen, int *seq){
    
    if ( currentlen == seqlen ) return; 

    *seq = xs;

    if( xs % 2 == 0 )
        xs /= 2;
    else
        xs = 3*xs+1;
    
    generate_sequence(xs,currentlen+1,seqlen,++seq);
}
/*
    function name : check_loop_iterative
    function and a starting integer check if the sequence ends up in a loop. 

    it calls also has_loop function to find start and end indexies of loop 

    return none
*/
void check_loop_iterative(void (*f)(int ,int ,int ,int * ), int xs, int seqlen, int *loop, int *looplen){
    
    int *originalLoop = (int *) malloc( (seqlen) * sizeof(int));

    (*f)(xs, 0, seqlen, originalLoop);

    if(seqlen/2 == *looplen){
        int *seq = (int *) malloc( seqlen * sizeof(int) );
            if(seq == NULL)
                printf("Memory cannot seperated!\n");
            /* First task start */
            else{
                generate_sequence(xs, 0, seqlen, seq);
            }

            printf("\nSequence: {");
            for(int a = 0; a < seqlen; a++){
                printf("%d, ",seq[a]);
            }
            printf("\b\b}\n\n");
            /* End of first task */
    }

    printf("Checking if there is a loop of length %d..\n",*looplen);

    (*looplen)--;
    
    if((*looplen) == 1){
        printf("\nNo loop FOUND!");
        return;
    }

    int ls = 0,le = (*looplen) + 1;
    (*looplen)++;
    int hasLoop = has_loop(originalLoop, seqlen, *looplen, &ls, &le);

    (*looplen)--;

    if (hasLoop == 0) {
            printf("\nLoop detected with a length of %d.\n",(*looplen)+1);
            if(hasLoop == 0){
                ls--;le--;
                printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)", ls, le);
            }
            int c = 0;
            for(int t = ls ; t < le; t++){
                loop[c] = originalLoop[t];
                c++;
            }
            free(originalLoop);
        return;
        /* end of third task */
    }
    else check_loop_iterative(f, xs, seqlen, loop, looplen);
}
/*
    function name : has_loop
    function finds starting index of loop and end index of loop

    return none
*/
int has_loop(int *arr, int n, int looplen, int *ls, int *le){
    int control = 1;    

    for(int a = 0; a < looplen && control == 1; a++){
        if( arr[n-1-a-(looplen)] != arr[(n)-1-a] ) control = 0;
    }
    if(control == 1){
        int flag = 1;
        int *loop = (int *) malloc( (looplen) * sizeof(int));

        int c = 0;
        for(int idx = n-looplen ; idx < n ;idx++){
            loop[c] = arr[idx];
            c++;
        }

        while(flag == 1){
            int counter = 0;

            for(int idx = *ls, c = 0; c < looplen; idx++,c++){
                if(arr[idx] != loop[c]) {
                    flag = 1;
                    counter = 0;
                }
                else counter++;
            }
            if(counter == looplen) {
                flag = 0;
                int end = (*le) ;
                int control = 1;
                while( end < n ){
                    if( end + looplen == n ){
                        control = 0; 
                    }
                    end += looplen;
                }
                if(control == 1) flag = 1;
            }
            (*ls)++;
            (*le)++;

        }
        free(loop);
        return 0;
    }
    else return 1;
}
/*
    function name : hist_of_firstdigits
    function counts histogram of digits in a sequence
    
    return none
*/
void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit){
    
    if(seqlen == 0) return;

    int *loop = (int *) malloc( (seqlen) * sizeof(int));
    (*f)(xs, 0, seqlen, loop);
    while(loop[0] >= 10) loop[0] /= 10;

    h[loop[0]] += 1;
    hist_of_firstdigits(f, loop[1], seqlen-1,h,digit+1);

}
