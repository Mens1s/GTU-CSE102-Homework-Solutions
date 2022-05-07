#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void boardBuilt(char board[][15], int loc[][4],char words[][20]);
void playGame(char board[][15], int loc[][4], char words[][20]);
void printMap(char board[][15]);

int main(){
    char gameBoard[15][15] = {0};
    int loc[7][4] = {0};
    char words[7][20] = {0};

    boardBuilt(gameBoard, loc, words);
    playGame(gameBoard ,loc, words);

    return 0;
}   
/*
    Function : boardBuilt
    
    this function create game area || game board randomly
 
    return none
*/
void boardBuilt(char board[][15], int loc[][4],char words[][20]){
    int randomNum[7] = {0};
    srand(time(NULL));
    /* Taking 7 random numbers*/
    for(int a = 0; a < 7; a++){
        int temp = rand() % 50;

        /* control of randomNum contains temp num */
        for(int b = 0; b < 7; b++){
            while(temp == randomNum[b]){
                temp = rand() % 50;
                b = 0;
            }
        }
        randomNum[a] = temp;
    }
    /* Taking random 7 words form wordlist.txt */
    FILE *text = fopen("wordlist.txt","r");
    char tempStr[1][20] = {0};
    int idx = 0;
    int word = 0;
    while(fscanf(text, "%s", tempStr[0]) == 1){
        for(int a = 0; a < 7 ; a++){
            if(randomNum[a] == idx){
                strcpy(words[word], tempStr[0]);
                word++;
            }
        }
        idx++;
    }
    fclose(text);
    /* Closing file */
    /* creating board */
    int counter = 0 , random = 0, wCounter = 0;
    /*
        1-> left to right
        2-> right to left
        3-> up to down
        4-> down to up
        5-> left diagnosal to right
        6-> left reverse diagnosal to right
        7-> right diagnosal to left
        8-> right reverse diagnosal to left
    */
    while(counter < 15){
        random = rand() % 8; 
        /* printing left to right */
        if(random == 0 && wCounter < 7) {
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len);
            int end = start + len;

            loc[wCounter][0] = counter;
            loc[wCounter][1] = start;
            loc[wCounter][2] = counter;
            loc[wCounter][3] = end - 1;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int idx = 0; idx < 15 ; idx++){ 

                if(idx >= start && idx < end) board[counter][idx] = words[wCounter][idx-start];   
                else{
                    char temp = 97 + rand() % 26;
                    board[counter][idx] = temp;
                }                            
            }
            counter++;
            wCounter++;
        }
        /* printing right to left */
        else if(random == 1 && wCounter < 7){
            int c=0;
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len);
            int end = start + len ;

            loc[wCounter][0] = counter;
            loc[wCounter][1] = end - 1;
            loc[wCounter][2] = counter;
            loc[wCounter][3] = start;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int idx = 0; idx < 15 ; idx++){           
                if(idx >= start && idx < end) {
                    board[counter][idx] = words[wCounter][len-1-c];   
                    c++;
                }
                else{
                    char temp = 97 + rand() % 26;
                    board[counter][idx] = temp;
                }
            }
            counter++;
            wCounter++;
        }
        /* printing diagnosal */
        else if(random == 2 && counter < 5 && wCounter < 7){
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len);
            int end = start + len;
            int idx = 0;

            loc[wCounter][0] = counter  ;
            loc[wCounter][1] = start;
            loc[wCounter][2] = counter + len - 1;
            loc[wCounter][3] = end - 1;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int row = counter; row < len+counter; row++){
                int control = 1;
                for(int col = 0; col < 15 ; col++ ){    
                    if(start == col && control == 1) {
                        board[row][col] = words[wCounter][idx];   
                        idx++;
                        start++;
                        control = 0;
                    }
                    else{
                        char temp = 97 + rand() % 26;
                        board[row][col] = temp;
                    }
                }
            }
            counter += len;
            wCounter++;
        }
        /* printing reverse diagnosal */
        else if(random == 3 && counter < 5 && wCounter < 7){
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len);
            int end = start + len;
            int idx = len-1;

            loc[wCounter][2] = counter  ;
            loc[wCounter][3] = start;
            loc[wCounter][0] = counter + len - 1;
            loc[wCounter][1] = end - 1;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int row = counter; row < len+counter; row++){
                int control = 1;
                for(int col = 0; col < 15 ; col++ ){    
                    if(start == col && control == 1) {
                        board[row][col] = words[wCounter][idx];   
                        idx--;
                        start++;
                        control = 0;
                    }
                    else{
                        char temp = 97 + rand() % 26;
                        board[row][col] = temp;
                    }
                }
            }
            counter += len;
            wCounter++;
        }
        /* printing top to low */
        else if(random == 4 && counter < 5 && wCounter < 7 ){
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len);
            int end = start + len;
            int idx = 0;
            loc[wCounter][0] = counter  ;
            loc[wCounter][1] = start;
            loc[wCounter][2] = counter + len - 1;
            loc[wCounter][3] = start;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int row = counter; row < len+counter; row++){
                int control = 1;
                for(int col = 0; col < 15 ; col++ ){    
                    if(start == col && control == 1) {
                        board[row][start] = words[wCounter][idx];   
                        idx++;
                        control = 0;
                    }
                    else{
                        char temp = 97 + rand() % 26;
                        board[row][col] = temp;
                    }
                }
            }
            counter += len;
            wCounter++;
        }
        /* printing low to top */
        else if(random == 5 && counter < 5 && wCounter < 7){
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len);
            int end = start + len;
            int idx = len-1;

            loc[wCounter][2] = counter  ;
            loc[wCounter][3] = start;
            loc[wCounter][0] = counter + len - 1;
            loc[wCounter][1] =  start;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int row = counter; row < len+counter; row++){
                int control = 1;
                for(int col = 0; col < 15 ; col++ ){    
                    if(start == col && control == 1) {
                        board[row][start] = words[wCounter][idx];   
                        idx--;
                        control = 0;
                    }
                    else{
                        char temp = 97 + rand() % 26;
                        board[row][col] = temp;
                    }
                }
            }
            counter += len;
            wCounter++;
        }
        /* reverse diagnosal right to left */
        else if(random == 6 && counter < 5 && wCounter < 7){            
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len) + len;
            int end = start - len + 1;
            int idx = len-1;
            loc[wCounter][2] = counter  ;
            loc[wCounter][3] = start;
            loc[wCounter][0] = counter + len - 1;
            loc[wCounter][1] = end + 1 - 1;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int row = counter; row < len+counter; row++){
                int control = 1;
                for(int col = 0; col < 15 ; col++ ){    
                    if(start == col && control == 1) {
                        board[row][col] = words[wCounter][idx];   
                        idx--;
                        start--;
                        control = 0;
                    }
                    else{
                        char temp = 97 + rand() % 26;
                        board[row][col] = temp;
                    }
                }
            }
            counter += len;
            wCounter++;
        }
        /* reverse diagnosal left to right */
        else if(random == 7 && counter < 5 && wCounter < 7){
            int len = strlen(words[wCounter]);
            int start = rand() % (15 - len) + len;
            int end = start - len;
            int idx = 0;
            loc[wCounter][0] = counter  ;
            loc[wCounter][1] = start;
            loc[wCounter][2] = counter + len - 1;
            loc[wCounter][3] = end + 1;
            printf("Word %5s Loc: %d %d\n",words[wCounter],loc[wCounter][0],loc[wCounter][1]);
            for(int row = counter; row < len+counter; row++){
                int control = 1;
                for(int col = 0; col < 15 ; col++ ){    
                    if(start == col && control == 1) {
                        board[row][col] = words[wCounter][idx];   
                        idx++;
                        start--;
                        control = 0;
                    }
                    else{
                        char temp = 97 + rand() % 26;
                        board[row][col] = temp;
                    }
                }
            }
            counter += len;
            wCounter++;
        }
        else if(wCounter >= 7){
            for(int idx = 0; idx < 15 ; idx++){
                char temp = 97 + rand() % 26;
                board[counter][idx] = temp;
            }
            counter++;
        }
    }
}
/*
    Function : printMap
    
    this function print game area || game board randomly
 
    return none
*/
void printMap(char board[][15]){
    for(int a = 0; a < 15 ;a++){
        for(int b = 0; b < 15; b++){
            if(board[a][b] == 'X'){
                printf("\033[0;31m");
                printf("%2c ",board[a][b]);
                printf("\033[0m");
            }
            else printf("%2c ",board[a][b]);
        }   printf("\n");
    }
}
/*
    Function : playGame
    
    this function starting game and controls game rules
        also
    checking game has to be run or determine
 
    return none
*/
void playGame(char board[][15] ,int loc[][4],char words[][20]){
    char word[20]={0}, input[20]={0}, str[20], usedWords[7][20] = {0};

    int choice[2], health = 3, point = 0;

    while(health > 0 && point < 14){
        printMap(board);
        printf("Enter coordinates and word :");

        gets(input);
        /* Checking exit command */
        sscanf(input,"%s ",str);
        if(strcmp(str,":q") == 0) {
            printf("Exiting....");
            health = -10;
            break;
        }

        sscanf(input,"%d %d %s",&choice[0],&choice[1],str);
        int pos = -1;
        int count = 0;

        for(int a = 0; a < 7 && pos == -1; a++){
            if(strcmp(str, words[a]) == 0) {
                pos = a;
                strcpy(word, words[a]);
                break;
            }
            if(strcmp(str, usedWords[a]) == 0){
                printf("You have already found this word!\n");
                break;
            }
        }
        if(pos == -1){
            health--;
            printf("Wrong choice! You have only %d lefts.\n",health);
        }
        else{
            /* for left to right */
            if(loc[pos][0] == choice[0] && loc[pos][1] == choice[1]){
                point += 2;
                printf("Founded! You got two points. Total Point is %d.\n",point);
                int len = strlen(words[pos]);
                /* for one line */
                if(loc[pos][0] == loc[pos][2]){
                    /* left to right */
                    if(loc[pos][1] < loc[pos][3]){
                        for(int row = choice[1]; row < choice[1] + len ; row++){
                            board[choice[0]][row] = 'X';
                        }
                    }
                    else{
                        for(int row = choice[1]; row > choice[1] - len ; row--){
                            board[choice[0]][row] = 'X';
                        }
                    }
                }
                /* for buttom to top or top to buttom */
                else{
                    int row = choice[0];
                    int col = choice[1];
                    /* for top to buttom or buttom to top */
                    if(loc[pos][1] == loc[pos][3]){

                        if(loc[pos][0] < loc[pos][2]){
                            for(int a = 0 ; a < len ; a++){
                                board[row][col] = 'X';
                                row++;
                            }
                        }
                        else{
                            for(int a = 0 ; a < len ; a++){
                                board[row][col] = 'X';
                                row--;
                            }
                        }
                    }
                    /* for diagnosal */
                    else{
                        /* Checking reverse diagnosal */
                        if(loc[pos][0] > loc[pos][2]){
                            if(loc[pos][1] < loc[pos][3]){
                                for(int a = 0 ; a < len ; a++){
                                    board[row][col] = 'X';
                                    row--;
                                    col++;
                                }
                            }
                            else{
                                for(int a = 0 ; a < len ; a++){
                                    board[row][col] = 'X';
                                    row--;
                                    col--;
                                }
                            }
                        }
                        /* Checking right diagnosal */
                        else{
                            if(loc[pos][1] < loc[pos][3]){
                                for(int a = 0 ; a < len ; a++){
                                    board[row][col] = 'X';
                                    row++;
                                    col++;
                                }
                            }
                            else{
                                for(int a = 0 ; a < len ; a++){
                                    board[row][col] = 'X';
                                    row++;
                                    col--;
                                }
                            }
                        }
                    }
                    strcpy(usedWords[count], word);
                    count++;
                }
            }
            else{
                health--;
                printf("Wrong choice! You have only %d lefts.\n",health);
            }
        }
    }
    if(point == 14){
        printf("YOU WON THE GAME! POINT : %d\n",point);
    }
    else if(health == -10 ) printf("\nYour point is %d\n",point);
    else printf("You lose the game!.. Point : %d\n",point);
    return;
}