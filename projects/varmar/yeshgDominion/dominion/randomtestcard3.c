#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int test_tribute(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
   
    int x = 0;
    for(;x<50;x++){
        struct gameState initial = G;
        //set pre game state
        initial.hand[0][0] = tribute; 
        initial.hand[1][0] = copper;
        int deck_options[2] = {0,10};
        int deck_flag = rand()%2;
        if(deck_flag){
            initial.deck[1][0] = copper;
            initial.deck[1][1] = copper;
        }
        initial.deckCount[1] = deck_options[deck_flag];
        int discard_options[2] = {0,2};
        int discard_flag = rand()%2;
        initial.discardCount[1] = discard_options[discard_flag];
        if(discard_flag){
            initial.discard[1][0] = copper;
            initial.discard[1][1] = copper;
        }
        initial.coins = 3;
        initial.numActions = 1;
        int bonus = 0;
        //run function
        playTribute(0,0,0,&initial,0,&bonus,0,1);

        //check if game state meets post game state requirements
        printf("\ntest description: deckCount = %d, discardCount = %d\n",deck_options[deck_flag],discard_options[discard_flag]);
        if(deck_flag == 0 && discard_flag == 0){
            if(initial.coins != 3 || initial.numActions != 1 || initial.handCount[0] != 5 ){
                printf("player 0 gained something when they shouldn't have\n");
            }
        }
        else{
            if(initial.coins != 7){
                printf("player 0 didn't gain appropriate number of coins\n");
            }
        }
    }
    return 0;
}

int main(){

    test_tribute();

    printf("done with unittest2.c (target function handle_tribute):\n\n");
    
}