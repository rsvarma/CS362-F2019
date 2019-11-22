#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int test_baron(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
   
    int x = 0;
    for(;x<50;x++){
        printf("made it here");
        struct gameState initial = G;
        //set pre game state
        initial.hand[0][0] = baron; 
        int flag = rand()%2;
        int card_flag[2] = {estate,copper};
        initial.hand[0][1] = card_flag[flag];
        initial.hand[0][2] = copper;
        initial.hand[0][3] = copper;
        initial.hand[0][4] = copper;
        initial.numBuys = 1;
        initial.coins = 3;
        int choice1 = rand()%2;
        //run function
        int res = handle_baron(choice1,&initial,0);

        printf("\ntest descriptipn: discards = %d, hasEstate = %d\n",choice1,flag);
        if(choice1 == 1){
            if(initial.numBuys != 2){
                printf("player 0 has improper number of buys\n");
            }
            if(initial.coins != 7){
                printf("player 0 has improper number of coins\n");
            }
        }
        else if(choice1 == 0 && flag == 0){
            int foundEstate = 0;
            int i = 0;
            for(i = 0; i<initial.discardCount[0]; i++){
                if (initial.discard[0][i] == estate){
                    foundEstate = 1;
                }
            }
            if(foundEstate != 1){
                printf("estate card not properly discarded by player 0\n");
            }
        }
        else if(choice1 == 0 && flag == 1){
            if(res == 0){
                printf("no\n");
            }
        }
    }

    return 0;
}

int main(){

    test_baron();

    printf("done with randomtestcard2.c (target function handle_baron):\n\n");
    
}