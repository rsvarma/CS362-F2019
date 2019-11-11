#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int test_baron(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
   
    int successful = 0;
    printf("Test 1: Player 0 discards an estate:\n\n");
    //Pre Game State Requirements: Player 0 has baron and estate in hand
    //Post Game State Requirements: Player 0 gains a buy and 4 coins
    struct gameState initial = G;
    //set pre game state
    initial.hand[0][0] = baron; 
    initial.hand[0][1] = estate;
    initial.hand[0][2] = copper;
    initial.hand[0][3] = copper;
    initial.hand[0][4] = copper;
    initial.numBuys = 1;
    initial.coins = 3;

    //run function
    handle_baron(1,&initial,0);



    //check if game state meets post game state requirements
    if(initial.numBuys != 2){
        printf("player 0 has improper number of buys\n");
        successful = 1;
    }
    if(initial.coins != 7){
        printf("player 0 has improper number of coins\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nBaron test 1 successful!\n\n");
    }else{
        printf("\nBaron test 1 unsuccessful\n\n");
    }

    successful = 0;
    printf("Test 2: Player 0 chooses to gain an estate:\n\n");
    //Pre Game State Requirements: Player 0 has baron in hand
    //Post Game State Requirements: Player 0 gains an estate
    initial = G;
    //set pre game state
    initial.hand[0][0] = baron; 
    initial.hand[0][1] = estate;
    initial.hand[0][2] = copper;
    initial.hand[0][3] = copper;
    initial.hand[0][4] = copper;
    initial.discardCount[0] = 0;

    //run function
    handle_baron(0,&initial,0);



    //check if game state meets post game state requirements
    int foundEstate = 0;
    int i = 0;
    for(i = 0; i<initial.discardCount[0]; i++){
        if (initial.discard[0][i] == estate){
            foundEstate = 1;
        }
    }
    if(foundEstate != 1){
        successful = 1;
    }
    if(successful == 0){
        printf("\nBaron test 2 successful!\n\n");
    }else{
        printf("\nBaron test 2 unsuccessful\n\n");
    }


    successful = 0;
    printf("Test 3: Player 0 chooses to gain an estate, but doesn't have estate:\n\n");
    //Pre Game State Requirements: Player 0 has baron in hand
    //Post Game State Requirements: Player 0 gains an estate
    initial = G;
    //set pre game state
    initial.hand[0][0] = baron; 
    initial.hand[0][1] = copper;
    initial.hand[0][2] = copper;
    initial.hand[0][3] = copper;
    initial.hand[0][4] = copper;
    initial.discardCount[0] = 0;

    //run function
    int r = handle_baron(1,&initial,0);



    //check if game state meets post game state requirements
    if(r == 0){
        printf("invalid baron action allowed");
        successful = 1;
    }
    if(successful == 0){
        printf("\nBaron test 3 successful!\n\n");
    }else{
        printf("\nBaron test 3 unsuccessful\n\n");
    }
    return 0;
}

int main(){

    test_baron();

    printf("done with unittest4.c (target function handle_baron):\n\n");
    
}