#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {
    /* variables declaration */
    float choice = 1;
    /* variables declaration for the zero decision trees  */
    int resultZ;
    int t, w;
    double p, h;
    char s;
    /* variables declaration for the first decision trees */
    float pl, pw; 
    float sl, sw;
    char resP1, resP2;
    /* variables declaration for the second decision trees */
    float x1,x2,x3;
    float x4,x5;//boolean value
    float comp;
    double s_resP1, s_resP2;
    /* variables declaration for the third decision trees */
    float rate, pRate;
    float demand;
    int fearChoice, buyerChoice;
    int resultF, resultS;
    /* This is bonus part for part3, this part reduces 26 code lines */
    /* !!But it is not used in that homework!! */
    char resultfTEXT[5][40] = {
        {"\033[1;31m STRONG SELL \033[0m "},
        {"\033[1;31m SELL \033[0m "},
        {"\033[1;36m WAIT \033[0m "},
        {"\033[1;32m BUY \033[0m "},
        {"\033[1;32m STRONG BUY \033[0m "},
    };
    /* Starting Code with request of choice */
    do
    {
        if(choice != 1 && choice != 2 && choice != 3 ) printf("\n\n\nWrong typing! Please select: ");
        else printf("\n\n\n1-) Iris Flower\n2-) Which Number best for me \n3-) Coin AI\n0-) EXIT\n\n\033[1;34m Choice \033[0m : ");
        scanf("%f",&choice);
        fflush(stdin);
        if(choice  == 1){
            /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
            printf("Enter PL and PW : ");

            scanf("%f%f",&pl,&pw);

            printf("Enter SL and SW : ");
            scanf("%f%f",&sl,&sw);

            resP1 = dt1a(pl,pw,sl,sw);
            
            resP2 = dt1b(pl,pw,0,0);
            /* Compare performances and print results */
            if(resP1 == resP2){
                if(resP1 == 'i') printf("\nYour ideal flower is : Virginica\n");
                else if(resP1 == 'v') printf("\nYour ideal flower is : Versicolor\n");
                else printf("\nYour ideal flower is : Setosa");
            }
            else{
                if(resP1 == 'i' && resP2 == 'v') printf("\ndt1a result is Virginica dt1b result is Versicolor.\n");
                else if(resP1 == 'i' && resP2 == 's') printf("\ndt1a result is Virginica dt1b result is Setosa.\n");
                else if(resP1 == 'v' && resP2 == 'i') printf("\ndt1a result is Versicolor dt1b result is Virginica.\n");
                else if(resP1 == 'v' && resP2 == 's') printf("\ndt1a result is Versicolor dt1b result is Setosa.\n");
                else if(resP1 == 's' && resP2 == 'i') printf("\ndt1a result is Setosa dt1b result is Virginica.\n");
                else printf("\ndt1a result is Setosa dt1b result is Versicolor\n.");

            }
        }
        else if(choice == 2){
            /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
            printf("Enter x1, x2 and x3 : ");

            scanf("%f%f%f",&x1, &x2, &x3);

            printf("Please enter x4 1 for TRUE or any number for FALSE : ");
            scanf("%f",&x4);

            printf("Please enter x5 1 for TRUE or any number for FALSE : ");
            scanf("%f",&x5);

            s_resP1 = dt2a(x1, x2, x3, x4, x5); // 
            s_resP2 = dt2b(x1, x2, x3, x4, x5);
            /* Compare performances and print results */
            comp = s_resP1 - s_resP2;
            if(comp<0){
                comp*=(-1);
            }
            if(s_resP1 == s_resP2) printf("Result is %lf",s_resP1);      
            else if(comp<CLOSE_ENOUGH) printf("Result is ||average|| %lf",(s_resP1+s_resP2)/2.0);
            else printf("\ndt2a result is %lf dt2b result is %lf",s_resP1, s_resP2);
        }
        else if(choice == 3){
            /*
                This is a decision tree of buy a coin or sell it || or COIN AI
                You enter your coin data's and we recommend you to best move you do!
            */
            printf("\nPlease enter the weekly increase rate of your coin : ");
            scanf("%f",&rate);
            printf("\nIf your coin has a project, rate it out of 10, otherwise enter zero : ");
            scanf("%f",&pRate);
            printf("\nDoes your coin have a demand buy from any community \n(1 for YES 0 for False) : ");
            scanf("%f",&demand);
            printf("\nPlease select your coin buyer type : \n1-) Crab-Shrimp (0-10 BTC)\n2-) Octopus (10-50 BTC)\n3-) Fish (50-100 BTC)\n4-) Dolphin (100-500 BTC)\n5-) Shark (500-1000 BTC)\n6-) Whale (1000-5000 BTC)\n7-) Humpback Whale (5000+ BTC)\n");
            scanf("%d",&buyerChoice);
            printf("\nPlease select fear&greed situation : \n1-) Extreme Fear\n2-) Fear\n3-) Neutral\n4-) Greed\n5-) Extreme Greed\n");
            scanf("%d",&fearChoice);
            if(fearChoice > 5 || buyerChoice > 7 || pRate > 10 || pRate < 0 || fearChoice < 1 || buyerChoice < 1) printf("Wrong Typing when entering the information please try again!\n");
            else{
                resultF = dt3a(rate, pRate, demand, fearChoice, buyerChoice);
                resultS = dt3b(rate, pRate, demand, fearChoice, buyerChoice);
                /*  
                    1 => Strong Sell
                    2 => Sell
                    3 => Wait
                    4 => Buy
                    5 => Strong Buy
                */
                if( resultF == resultS) {
                    if(resultS == 1) printf("We recommend \033[1;31m STRONG SELL \033[0m");
                    else if(resultS == 2) printf("We recommend \033[1;31m SELL \033[0m");
                    else if(resultS == 3) printf("We recommend  \033[1;36m WAIT \033[0m");
                    else if(resultS == 4) printf("We recommend  \033[1;32m BUY \033[0m \033[0m");
                    else printf("We recommend \033[1;32m STRONG BUY \033[0m");  
                }
                else if(resultF == 1){
                    if(resultS == 2) printf("First tree recommend \033[1;31m STRONG SELL \033[0m  and Second Tree recommend \033[1;31m SELL \033[0m ");
                    else if(resultS == 3) printf("First tree recommend \033[1;31m STRONG SELL \033[0m  and Second Tree recommend \033[1;36m WAIT \033[0m  ");
                    else if(resultS == 4) printf("First tree recommend \033[1;31m STRONG SELL \033[0m  and Second Tree recommend \033[1;32m BUY \033[0m ");
                    else if(resultS == 5) printf("First tree recommend \033[1;31m STRONG SELL \033[0m  and Second Tree recommend \033[1;32m STRONG BUY \033[0m  ");
                }
                else if(resultF == 2){
                    if(resultS == 1) printf("First tree recommend \033[1;31m SELL \033[0m and Second Tree recommend \033[1;31m STRONG SELL \033[0m  ");
                    else if(resultS == 3) printf("First tree recommend \033[1;31m SELL \033[0m and Second Tree recommend \033[1;36m WAIT \033[0m  ");
                    else if(resultS == 4) printf("First tree recommend \033[1;31m SELL \033[0m and Second Tree recommend \033[1;32m BUY \033[0m ");
                    else if(resultS == 5) printf("First tree recommend \033[1;31m SELL \033[0m  and Second Tree recommend \033[1;32m STRONG BUY \033[0m  ");
                }
                else if(resultF == 3){
                    if(resultS == 1) printf("First tree recommend \033[1;36m WAIT \033[0m  and Second Tree recommend \033[1;31m STRONG SELL \033[0m");
                    else if(resultS == 2) printf("First tree recommend \033[1;36m WAIT \033[0m and Second Tree recommend \033[1;31m SELL \033[0m  ");
                    else if(resultS == 4) printf("First tree recommend \033[1;36m WAIT \033[0m  and Second Tree recommend \033[1;32m BUY \033[0m ");
                    else if(resultS == 5) printf("First tree recommend \033[1;36m WAIT \033[0m and Second Tree recommend \033[1;32m STRONG BUY \033[0m  ");
                }
                else if(resultF == 4){
                    if(resultS == 2) printf("First tree recommend \033[1;32m BUY \033[0m \033[0m  and Second Tree recommend \033[1;31m SELL \033[0m ");
                    else if(resultS == 3) printf("First tree recommend \033[1;32m BUY \033[0m \033[0m  and Second Tree recommend \033[1;36m WAIT \033[0m  ");
                    else if(resultS == 1) printf("First tree recommend \033[1;32m BUY \033[0m \033[0m  and Second Tree recommend \033[1;31m SELL \033[0m");
                    else if(resultS == 5) printf("First tree recommend \033[1;32m BUY \033[0m \033[0m  and Second Tree recommend \033[1;32m STRONG BUY \033[0m  ");
                }
                else if(resultF == 5){
                    if(resultS == 2) printf("First tree recommend \033[1;32m STRONG BUY \033[0m  and Second Tree recommend \033[1;31m SELL \033[0m ");
                    else if(resultS == 3) printf("First tree recommend \033[1;32m STRONG BUY \033[0m and Second Tree recommend \033[1;36m WAIT \033[0m  ");
                    else if(resultS == 4) printf("First tree recommend \033[1;32m STRONG BUY \033[0m  and Second Tree recommend \033[1;32m BUY \033[0m ");
                    else if(resultS == 1) printf("First tree recommend \033[1;32m STRONG BUY \033[0m  and Second Tree recommend  \033[1;31m SELL \033[0m  ");
                }
                /*
                THAT IS BONUS PART
                it is easier than line 100-131
                if you do comment line (100-131) and use 141-144 it is same thing to do!
                if( resultF == resultS)
                    printf("We recommend %s",resultfTEXT[resultF-1]);
                else
                    printf("First tree recommend %s and Second Tree recommend %s",resultfTEXT[resultF-1],resultfTEXT[resultS-1]);
                */
            }
        }   
        /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
        /* Compare performances and print results */
        
        
    }while (choice != 0);
    return 0;
}
