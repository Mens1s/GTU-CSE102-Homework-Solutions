#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_BLOCK_SIZE 10

typedef struct {
    int * array;
    int currentsize; 
    int maxsize;
} stack;

stack * init_return(); 
int init(stack * s);
int push(stack * s, int d);
int pop(stack * s);
void move(stack *sStack, stack *eStack, int start, int finish);

int main(){

    int tower_size;

    /*Taking tower size from user*/
    printf("Enter Tower size : ");
    scanf("%d",&tower_size);

    /* Tower size has to be pozitive number */
    while(tower_size < 1){
        printf("Enter POZITIVE Tower Size: ");
        scanf("%d",&tower_size);
    }

    /* initializing first/left stack */
    stack *left = init_return();

    /* control of left stack */
    if( init(left) != 1 ){ 
        printf("Please reSTART program!");return 0;
    }

    /* filling left array with poles */
    for(int a = tower_size; a > 0; a--)
        push(left, a);

    /* creating middle and right stacks */
    stack *middle = init_return();
    stack *right = init_return();

    /* control of stacks */
    if( init(middle) != 1 || init(right) != 1){
        printf("Please reSTART program!");return 0;
    }

    /* START GAME */
    int moves = pow(2, tower_size) - 1;
    int leftStack = 1, middleStack = 2, rightStack = 3;

    /* starts game with basic towers of honoi algorith which is defined in class by Prof. YAKUP GENC */
    if(tower_size % 2 == 0){
        int t = rightStack;
        rightStack = middleStack;
        middleStack = t;
    }
    for(int a = 1; a <= moves; a++){
        if(a % 3 == 1)
            move(left, right, leftStack, rightStack);
        if(a % 3 == 2)
            move(left, middle, leftStack, middleStack);
        else if(a % 3 == 0)
            move(middle, right, middleStack, rightStack);
    }

    return 0;
}
/* initiazling stacks with dynamic memory alocation and struct */
stack * init_return(){
    stack *s = (stack * ) malloc(sizeof(stack));
    
    s->currentsize = 0;
    s->maxsize = STACK_BLOCK_SIZE;
    s->array = (int *) calloc(STACK_BLOCK_SIZE, sizeof(int) );

    return s;
}
/* controlling of stack's number are correct or not */
int init(stack * s){
    if( s->currentsize != 0 ) return 0;
    if ( s->maxsize != STACK_BLOCK_SIZE )  return 0;
    return 1;   
} 
/* adding element to last on a array */
int push(stack * s, int d){
    /* controlling stack is full or not */
    if (s->currentsize == s->maxsize){
        
        int * t = (int *) malloc( s->currentsize * sizeof(int) );
        /* copying element to temp array*/
        for(int a = 0; a < s->currentsize; a++)
            t[a] = s->array[a];
        /* growing up original stack size adding of STACK_BLOCK_SIZE*/
        s->array = (int *) calloc( (s->currentsize+STACK_BLOCK_SIZE), sizeof(int) ); 

        /* copying old elements to growed stack */
        for(int a = 0; a < s->currentsize; a++)
            s->array[a]  = t[a];
        
        s->maxsize += STACK_BLOCK_SIZE;
    }
    /* add element to last field in the array */
    s->array[s->currentsize] = d;
    /* Growing current size */
    s->currentsize++;
    
    return 0;
}
/* removing element from last on a array */
int pop(stack * s){
    if (s->currentsize == 0)
        return 0;
    /* Removing last element from array actualy we don't remove and calloc it we trick only numbers */
    s->currentsize--;
    return s->array[s->currentsize];
}
/* moving elements on a game with basic towers of honoi algorith which is defined in class by Prof. YAKUP GENC */
void move(stack *sStack, stack *eStack, int start, int finish)
{
    int p1current = pop(sStack);
    int p2current = pop(eStack);
    /* if startStack is empty so we can/have to fill it by disks in the endStack */
    if (p1current == 0){
        push(sStack, p2current);
        printf("Move the disk %d from '%d' to '%d' \n", p2current, finish, start);
    }
    /* if endStack is empty so we can/have to fill it by disks in the startStack */
    else if (p2current == 0){
        push(eStack, p1current);
        printf("Move the disk %d from '%d' to '%d' \n", p1current, start, finish);
    }
    /* if the startStack's topmost disk is bigger than endStak we can push all disks to endStack*/
    else if (p1current > p2current){
        push(sStack, p1current);
        push(sStack, p2current);
        printf("Move the disk %d from '%d' to '%d' \n", p2current, finish, start);
    }
    /* if the endStack's topmost disk is bigger than endStak we can push all disks to startStack*/
    else{
        push(eStack, p2current);
        push(eStack, p1current);
        printf("Move the disk %d from '%d' to '%d' \n", p1current, start, finish);
    }
}

