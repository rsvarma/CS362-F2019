#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int test_tribute(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
    int bonus = 0;
    int successful = 0;
    printf("Test 1: Player 0 plays tribute and Player 1 has no cards to reveal:\n\n");
    //Pre Game State Requirements: Player 0 has tribute with three coins, other player has empty deck and discard
    //Post Game State Requirements: Player 0 gains nothing
    struct gameState initial = G;
    //set pre game state
    initial.hand[0][0] = tribute; 
    initial.hand[1][0] = copper;
    initial.deckCount[1] = 0;
    initial.discardCount[1] = 0;
    initial.coins = 3;
    initial.numActions = 1;

    //run function
    playTribute(0,0,0,&initial,0,&bonus,0,1);

    //check if game state meets post game state requirements
    if(initial.coins != 3 || initial.numActions != 1 || initial.handCount[0] != 5 ){
        printf("player 0 gained something when they shouldn't have\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nTribute test 1 successful!\n\n");
    }else{
        printf("\nTribute test 1 unsuccessful\n\n");
    }


    successful = 0;
    printf("Test 2: Player 0 plays tribute and Player 1 reveals copper, deck has cards:\n\n");
    //Pre Game State Requirements: Player 0 has tribute with three coins, other player reveals two coppers from deck
    //Post Game State Requirements: Player 0 gains three coins
    initial = G;
    //set pre game state
    initial.hand[0][0] = tribute; 
    initial.deck[1][0] = copper;
    initial.deck[1][1] = copper;
    initial.deckCount[1] = 10;
    initial.discardCount[1] = 0;
    initial.coins = 3;
    initial.numActions = 1;

    //run function
    playTribute(0,0,0,&initial,0,&bonus,0,1);

    //check if game state meets post game state requirements
    if(initial.coins != 6){
        printf("player 0 gained an incorrect number of coins\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nTribute test 2 successful!\n\n");
    }else{
        printf("\nTribute test 2 unsuccessful\n\n");
    }

    successful = 0;
    printf("Test 3: Player 0 plays tribute and Player 1 reveals coppers, deck is empty:\n\n");
    //Pre Game State Requirements: Player 0 has tribute with three coins, other player reveals two coppers
    //after shuffling discard pile into deck
    //Post Game State Requirements: Player 0 gains three coins
    initial = G;
    //set pre game state
    initial.hand[0][0] = tribute; 
    initial.discard[1][0] = copper;
    initial.discard[1][1] = copper;
    initial.deckCount[1] = 0;
    initial.discardCount[1] = 2;
    initial.coins = 3;
    initial.numActions = 1;

    //run function
    playTribute(0,0,0,&initial,0,&bonus,0,1);

    //check if game state meets post game state requirements
    if(initial.coins != 6){
        printf("player 0 gained an incorrect number of coins\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nTribute test 2 successful!\n\n");
    }else{
        printf("\nTribute test 2 unsuccessful\n\n");
    }


    return 0;
}

int main(){

    test_tribute();

    printf("done with unittest2.c (target function handle_tribute):\n\n");
    
}