#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

#include "rngs.h"



int test_minion(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
    printf("numplayers %d: \n",G.numPlayers);
    int successful = 0;
    printf("Test 1: Player 0 chooses to gain two coins from minion:\n\n");
    //Test 1: User chooses to gain two coins from minion
    //Pre Game State Requirements: Player 0 has minion in their hand,3 coppers, and 1 estate
    //Other player has same game state as initialization
    //Post Game State Requirements: Player 0 has 4 cards in their hand, 5 in deck, 1 in discard
    struct gameState initial = G;
    //set pre game state
    initial.hand[0][0] = minion;
    initial.hand[0][1] = copper; 
    initial.hand[0][2] = copper; 
    initial.hand[0][3] = copper; 
    initial.hand[0][4] = estate; 
    initial.coins = 3;
    int bonus = 0;
    //run function
    playMinion(1, 0,0,&initial,0,&bonus,0);

    //check if game state meets post game state requirements
    if(initial.coins != 5){
        printf("wrong number of coins for player 0\n");
        printf("number of coins: %d",initial.coins);
        successful = 1;
    }
    if(initial.handCount[0] != 4){
        printf("wrong number of cards in hand of player 0\n");
        successful = 1;
    }
    if(initial.deckCount[0] != 5){
        printf("wrong number of cards in deck of player 0\n");
        successful = 1;
    }
    if(initial.discardCount[0] != 1){
        printf("wrong number of cards in discard pile of player 0\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nMinion test 1 successful!\n\n");
    }else{
        printf("\nMinion test 1 unsuccessful\n\n");
    }


  printf("Test 2: Player 0 chooses to gain four cards, Player 1 must discard and redraw:\n\n");
    //Test 2: User chooses to gain two coins from minion
    //Pre Game State Requirements: Player 0 has minion in their hand,3 coppers, and 1 estate
    //Other player has same game state as initialization
    //Post Game State Requirements: Player 0 has 9 cards in their hand, 1 in deck, 1 in discard
    //player 1 has 4 in hand, 1 in deck, 5 in discard
    initial = G;
    //set pre game state
    initial.hand[0][0] = minion;
    initial.hand[0][1] = copper; 
    initial.hand[0][2] = copper; 
    initial.hand[0][3] = copper; 
    initial.hand[0][4] = estate;  
    initial.hand[1][0] = minion;
    initial.hand[1][1] = copper; 
    initial.hand[1][2] = copper; 
    initial.hand[1][3] = copper; 
    initial.hand[1][4] = estate; 
    initial.handCount[1] = 5;
    initial.coins = 3;
    
    //run function
    playMinion(0, 1, 0,&initial,0,&bonus,0);

    successful = 0;
    //check if post game state requirements are met
    if(initial.handCount[0] != 4){
        printf("wrong number of cards in hand of player 0\n");
        successful = 1;
    }
    if(initial.handCount[1] != 4){
        printf("wrong number of cards in hand of player 1\n");
        successful = 1;
    }
    if(initial.deckCount[0] != 1){
        printf("wrong number of cards in deck of player 0\n");
        successful = 1;
    }
    if(initial.deckCount[1] != 6){
        printf("wrong number of cards in deck of player 1\n");
        successful = 1;
    }
    if(initial.discardCount[0] != 1){
        printf("wrong number of cards in discard pile of player 0\n");
        successful = 1;
    }
    if(initial.discardCount[1] != 5){
        printf("wrong number of cards in discard pile of player 1\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nMinion test 2 successful!\n\n");
    }else{
        printf("\nMinion test 2 unsuccessful\n\n");
    }



    printf("Test 3: Player 0 chooses to gain four cards, Player 1 doesn't have to discard:\n\n");
    //Test 2: User chooses to gain two coins from minion
    //Pre Game State Requirements: Player 0 has minion in their hand,3 coppers, and 1 estate
    //Player 1 only has 4 cards in their hand
    //Post Game State Requirements: Player 0 has 8 cards in their hand, 1 in deck, 1 in discard
    //player 1 has 4 in hand, 1 in deck, 5 in discard
    initial = G;
    //set pre game state
    initial.hand[0][0] = minion;
    initial.hand[0][1] = copper; 
    initial.hand[0][2] = copper; 
    initial.hand[0][3] = copper; 
    initial.hand[0][4] = estate; 
    initial.hand[1][0] = minion;
    initial.hand[1][1] = copper; 
    initial.hand[1][2] = copper; 
    initial.hand[1][3] = copper;  
    initial.handCount[1] = 4;
    initial.coins = 3;

    //run function
    playMinion(0, 1, 0,&initial,0,&bonus,0);

    successful = 0;
    //check if post game state requirements are met
    if(initial.handCount[0] != 4){
        printf("wrong number of cards in hand of player 0\n");
        successful = 1;
    }
    if(initial.handCount[1] != 4){
        printf("wrong number of cards in hand of player 1\n");
        successful = 1;
    }
    if(initial.deckCount[0] != 1){
        printf("wrong number of cards in deck of player 0\n");
        successful = 1;
    }
    if(initial.discardCount[0] != 1){
        printf("wrong number of cards in discard pile of player 0\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nMinion test 3 successful!\n\n");
    }else{
        printf("\nMinion test 3 unsuccessful\n\n");
    }

    printf("Test 4: player tries to gain 2 coins and 4 cards\n");
    //Test result: handle_minion function should not return 0 since this isn't a valid option
    initial = G;
    initial.hand[0][0] = minion;
    initial.hand[0][1] = copper; 
    initial.hand[0][2] = copper; 
    initial.hand[0][3] = copper; 
    initial.hand[0][4] = estate; 
    initial.hand[0][5] = estate;
    initial.coins = 3;
    int r = playMinion(1,1,0,&initial,0,&bonus,0);
    if(r == 0){
        printf("handle_minion unable to detect proper input\n");
        printf("\nMinion test 4 unsuccessful\n\n");
    }else{
        printf("\nMinion test 4 successful!\n\n");
    }


    return 0;
}

int main(){

    test_minion();

    printf("done with (target function handle_minion):\n\n");
    
}