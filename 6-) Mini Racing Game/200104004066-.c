#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void cyan () {
  printf("\033[0;36m");
}

void yellow () {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void printMap(char arr[15][30], int p1[2], int p2[2]);

void createMap(char arr[15][30]);
/*
    Funtion : dice
    
    it does 
        getting random numbers

    min number = 1
    max number = 6

    return number
*/

int dice(){
    srand(time(NULL));
    return (rand() % 6 + 1);
}

int startGame();

int movePlayer1(int p1[] ,int pm1);
int movePlayer2(int p2[] ,int pm2);

void startOne();
void startTwo();

/*
    Funtion : main
    
    this function stars game
 
    return none
*/
int main(){
        
    int game;
    int p1, p2;

    int result = startGame();

    reset();
    printf("\n *** PLAYER %d will start the game... ***\n\n",result);

    if(result == 1) startOne();
    else startTwo();

    return 0;
}

/*
    Funtion : startGame
    
    this function decides who starts game 
 
    return who Starts Game
    return 1 => player one starts game
    return 2 => player two starts game
*/
int startGame(){
    int p1, p2;
    char c;

    do{
        yellow();
        printf("PLAYER 1... ENTER to dice ");
        scanf("%c",&c);

        p1 = dice();
        printf("DICE: %d",p1);

        cyan();
        printf("\nPLAYER 2... ENTER to dice ");
        scanf("%c",&c);

        p2 = dice();
        printf("DICE: %d",p2);
        reset();
        if(p1==p2) printf("\nSame dice value... Please try again.\n");
    }while(p1==p2);

    return p2>p1 ? 2 : 1;
}

/*
    Funtion : printMap
    
    it does 
        printing updated map whenever it called 
 
    return none
*/
void printMap(char arr[15][30], int p1[2], int p2[2]){
    for(int a = 0; a < 15;a++){
        for(int b = 0; b < 30; b++){
            if( arr[a][b] == 'X' ) {
                red();
                printf("%c",arr[a][b]);
                reset();
            }

            else if(p1[0] == a && p1[1] == b){
                yellow();
                printf("1");
                reset();
            }

            else if(p2[0] == a && p2[1] == b){
                cyan();
                printf("2");
                reset();
            }

            else if ( arr[a][b] == '_'){
                green();
                printf("%c",arr[a][b]);
                reset();
            }
            else printf("%c",arr[a][b]);
        }printf("\n");
    }
}
/*
    Funtion : createMap
    
    it create first map beginnig in the game 
 
    return none
*/
void createMap(char arr[15][30]){
    for(int a = 0; a < 15;a++){
        for(int b = 0; b < 30; b++){

            if(a == 0 || a == 14) arr[a][b] = '.';
            else if( b == 0 || b == 29) arr[a][b] = ':';

            else if( a == 2 && b == 1) arr[a][b] = '_';
            else if( a == 4 && b == 3) arr[a][b] = '_';

            else if((a == 2 || a == 12) && (b >= 2 && b <= 27) ) arr[a][b] = '.';
            else if( (a >= 3 && a <= 12) && (b == 2 || b == 27) ) arr[a][b] = ':';

            else if( (a == 4 || a == 10) && (b >= 4 && b <= 25) ) arr[a][b] = '.';
            else if( (a >= 5 && a <= 10) && (b == 4 || b == 25) ) arr[a][b] = ':';

            else if( ( a==1 && b == 14) || (a == 7 && b == 28) || (a == 13 && b  == 14) ) {
                red();
                arr[a][b] = 'X';
                reset();
            }

            else if( ( a==3 && b == 10) || (a == 3 && b == 18) || (a == 5 && b  == 26) || (a == 10 && b  == 26) || (a == 11 && b  == 10) || (a == 11 && b  == 18)) {
                red();
                arr[a][b] = 'X';
                reset();
            }

            else arr[a][b] = ' ';
        }
    }
}
/*
    Funtion : movePlayer1
    
    This function moves player1 in 4 special areas
    This function is a key point for game
 
    return 1  => if game has finished
    return 0  => if game is continue
*/
int movePlayer1(int p1[] ,int pm1){

    /* upper line and from right top to bottom */
    if( (p1[1] < 28) && (p1[0] == 1) ){
        int posibleMove = p1[1] + pm1;
        int leftMove;

        if(posibleMove > 28){
            leftMove = posibleMove - 27;
            p1[1] = 28;
            p1[0] = leftMove;
        }
        else{
            p1[1] = posibleMove;
            if( (p1[0] == 1 && p1[1] == 14) || (p1[0] == 7 && p1[1] == 28) || (p1[0] == 13 && p1[1] == 14) ){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p1[1] = posibleMove-2;
            }
        }
    }
    /* right top to bottom */
    else if( (p1[1] == 28 && p1[0] <= 14 )){
        int posibleMove = p1[0] + pm1;
        int leftMove;

        if(posibleMove > 13){
            leftMove = posibleMove - 13;
            p1[0] = 13;
            p1[1] = 28-leftMove;    
        }
        else{
            p1[0] = posibleMove;
            if( (p1[0] == 1 && p1[1] == 14) || (p1[0] == 7 && p1[1] == 28) || (p1[0] == 13 && p1[1] == 14) ){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p1[0] = posibleMove-2;
            }
            
        }
    }
    /* bottom to left */
    else if( (p1[0] == 13 && p1[1] <= 28 )){
        int posibleMove = p1[1] - pm1;
        int leftMove;

        if(posibleMove < 1){
            leftMove = 12 + posibleMove;
            p1[1] = 1;
            p1[0] = leftMove;
        }
        else{
            p1[1] = posibleMove;
            if( (p1[0] == 1 && p1[1] == 14) || (p1[0] == 7 && p1[1] == 28) || (p1[0] == 13 && p1[1] == 14) ){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p1[1] = posibleMove+2;
            }
        }
    }
    /* bottom to left top */
    else{
        int posibleMove = p1[0] - pm1;
        int leftMove;
        /* Checking game is finished or not */
        if(posibleMove <= 1){
            yellow();
            printf("\t*****PLAYER 1 WON*****\n");
            reset();
            p1[0] = 1;
            p1[1] = (-1)*posibleMove + 2 ;
            return 1;
        }
        else{
            p1[0] = posibleMove;
            /* Checking game is finished or not */
            if( p1[0] == 2 && p1[1] == 1 ){
                yellow();
                printf("\t*****PLAYER 1 WON*****\n");
                reset();
                return 1;
            }
        }

        
    }
    
    return 0;
}
/*
    Funtion : movePlayer2
    
    This function moves player2 in 4 special areas
    This function is a key point for game
 
    return 1  => if game has finished
    return 0  => if game is continue
*/
int movePlayer2(int p2[] ,int pm2){

    /* upper line and from right top to bottom */
    if( (p2[1] < 26) && (p2[0] == 3) ){
        int posibleMove = p2[1] + pm2;
        int leftMove;

        if(posibleMove > 26){
            leftMove = posibleMove - 25;
            p2[1] = 26;
            p2[0] = leftMove+2;
            if( p2[0] ==  5 && p2[1] == 26){
                cyan();
                printf("Penalty for player 2...\n");
                reset();
                p2[0] = 3;
            }

        }
        else{
            p2[1] = posibleMove;
            if( (p2[0] == 3 && p2[1] == 10) || (p2[0] == 3 && p2[1] == 18) || (p2[0] == 5 && p2[1] == 26) || (p2[0] == 10 && p2[1] == 26) || (p2[0] == 11 && p2[1] == 10) || (p2[0] == 11 && p2[1] == 18) ){
                cyan();
                printf("Penalty for player 2...\n");
                reset();
                p2[1] = posibleMove-2;
            }
        }
    }
    /* right top to bottom */
    else if( (p2[1] == 26 && p2[0] <= 11 )){
        int posibleMove = p2[0] + pm2;
        int leftMove;

        if(posibleMove > 11){
            leftMove = posibleMove - 11;
            p2[0] = 11;
            p2[1] = 26-leftMove;    
        }
        else{
            p2[0] = posibleMove;
            if( (p2[0] == 3 && p2[1] == 10) || (p2[0] == 3 && p2[1] == 18) || (p2[0] == 5 && p2[1] == 26) || (p2[0] == 10 && p2[1] == 26) || (p2[0] == 11 && p2[1] == 10) || (p2[0] == 11 && p2[1] == 18) ){
                cyan();
                printf("Penalty for player 2...\n");
                reset();
                p2[0] = posibleMove-2;
            }
            
        }
    }
    /* bottom to left */
    else if( (p2[0] == 11 && p2[1] <= 26 )){
        int posibleMove = p2[1] - pm2;
        int leftMove;

        if(posibleMove < 3){
            leftMove = 10 + posibleMove - 2;
            p2[1] = 3;
            p2[0] = leftMove;
        }
        else{
            p2[1] = posibleMove;
            if( (p2[0] == 3 && p2[1] == 10) || (p2[0] == 3 && p2[1] == 18) || (p2[0] == 5 && p2[1] == 26) || (p2[0] == 10 && p2[1] == 26) || (p2[0] == 11 && p2[1] == 10) || (p2[0] == 11 && p2[1] == 18) ){
                cyan();
                printf("Penalty for player 2...\n");
                reset();
                p2[1] = posibleMove+2;
            }
        }
    }
    /* bottom to left top */
    else{
        int posibleMove = p2[0] - pm2;
        int leftMove;
        /* Checking game is finished or not */
        if(posibleMove <= 3 ){
            cyan();
            printf("*****PLAYER 2 WON*****\n");
            reset();
            p2[0] = 3;
            p2[1] = (-1)*posibleMove + 6;
            return 1;
        }
        else{
            p2[0] = posibleMove;
            /* Checking game is finished or not */
            if((p2[0] == 4 && p2[1] == 3)){
                cyan();
                printf("\t*****PLAYER 2 WON*****\n");
                reset();
                return 1;
            }
        }
    }
    return 0;
}
/*
    Funtion : startOne
    
    if game starts with player one this function manages game
    This function is a key point for game
 
    return none
*/
void startOne(){
    int isOver = 0;
    char c;

    int pm1, pm2;

    char gameBoard[15][30];
    int p1[2] = {1, 1}, p2[2] = {3, 3};

    createMap(gameBoard);

    while(isOver == 0){
        printMap(gameBoard, p1,p2);
        yellow();
        printf("\nPLAYER 1... ENTER to dice ");
        scanf("%c",&c);

        pm1 = dice();
        printf("DICE: %d\n",pm1);

        isOver = movePlayer1(p1, pm1);
        
        if(isOver == 0) {
            cyan();
            printf("\nPLAYER 2... ENTER to dice ");
            scanf("%c",&c);

            pm2 = dice();
            printf("DICE: %d\n",pm2);

            reset();

            isOver = movePlayer2(p2, pm2);
        }
    }

    printMap(gameBoard, p1,p2);
}
/*
    Funtion : startTow
    
    if game starts with player two this function manages game
    This function is a key point for game
 
    return none
*/
void startTwo(){
    int isOver = 0;
    char c;

    int pm1, pm2;

    char gameBoard[15][30];
    int p1[2] = {1, 1}, p2[2] = {3, 3};

    createMap(gameBoard);
    
    while(isOver == 0){
        
        printMap(gameBoard, p1,p2);
        cyan();
        printf("\nPLAYER 2... ENTER to dice ");
        scanf("%c",&c);

        pm2 = dice();
        printf("DICE: %d\n",pm2);
        isOver =  movePlayer2(p2, pm2);
        if(isOver == 0) {
            
            yellow();
            printf("\nPLAYER 1... ENTER to dice ");
            scanf("%c",&c);

            pm1 = dice();
            printf("DICE: %d\n",pm1);
            reset();

            isOver = movePlayer1(p1, pm1);
        }
    }

    printMap(gameBoard, p1,p2);
}
