#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int test_mine(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
   
    int successful = 0;
    printf("Test 1: Player 0 plays mine and trashes copper electing to gain a silver:\n\n");
    //Pre Game State Requirements: Player 0 has mine and a copper in hand
    //Post Game State Requirements: Player 0 gains a silver
    struct gameState initial = G;
    //set pre game state
    initial.hand[0][0] = mine; 
    initial.hand[0][1] = copper;

    //run function
    int r = handle_mine(1,5,0,&initial,0);



    //check if game state meets post game state requirements
    if(r != 0){
        printf("valid action was declined!\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nMine test 1 successful!\n\n");
    }else{
        printf("\nMine test 1 unsuccessful\n\n");
    }


    successful = 0;
    printf("Test 2: Player 0 plays mine and trashes copper that is first card in hand electing to gain a gold:\n\n");
    //Pre Game State Requirements: Player 0 has mine and a copper in hand, copper is first card in hand
    //Post Game State Requirements: Player 0's action is denied
    initial = G;
    //set pre game state
    initial.hand[0][1] = mine; 
    initial.hand[0][0] = copper;

    //run function
    r = handle_mine(0,6,1,&initial,0);



    //check if game state meets post game state requirements
    if(r == 0){
        printf("invalid action was allowed!\n");
        successful = 1;
    }
    if(initial.handCount[0] != 3){
        printf("cards were not appropriately discarded and trashed\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nMine test 2 successful!\n\n");
    }else{
        printf("\nMine test 2 unsuccessful\n\n");
    }



    return 0;
}

int main(){

    test_mine();

    printf("done with unittest3.c (target function handle_mine):\n\n");
    
}