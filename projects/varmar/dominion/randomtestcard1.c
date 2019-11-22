#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"



int test_minion(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
    printf("initial deck count: %d, %d\n", G.deckCount[0],G.deckCount[1]);
    printf("initial discard count: %d, %d\n", G.discardCount[0],G.discardCount[1]);
    printf("initial hand count: %d, %d\n", G.handCount[0],G.handCount[1]);
    int tests = 50;
    int x;
    for(x = 0; x<tests; x++){
        struct gameState initial = G;
        //set pre game state
        int other_handcount = rand()%10;
        initial.handCount[1] = other_handcount;
        int i;
        for(i = 0;i<other_handcount;i++){
            int card_index = rand()%10;
            initial.hand[1][i] = k[card_index];
        }
        initial.hand[0][0] = minion;
        initial.hand[0][1] = copper; 
        initial.hand[0][2] = copper; 
        initial.hand[0][3] = copper; 
        initial.hand[0][4] = estate; 
        initial.coins = 3;
        int choice1 = rand()%2;
        int choice2 = rand()%2;
        int handPos = rand()%5;
        //run function
        int res = handle_minion(choice1, choice2, handPos,&initial,0);

        //check if game state meets post game state requirements
        printf("\ntest details: choice1 = %d choice 2 = %d handPos = %d initial.handCount[1] = %d\n",choice1,choice2,handPos,other_handcount);
        if(choice1 == 1 && choice2 == 0){
            if(initial.coins != 5){
                printf("wrong number of coins for player 0\n");
                printf("number of coins: %d\n",initial.coins);
            }
            if(initial.handCount[0] != 4){
                printf("wrong number of cards in hand of player 0\n");
            }
            if(initial.deckCount[0] != 5){
                printf("wrong number of cards in deck of player 0\n");
            }
            if(initial.discardCount[0] != 1){
                printf("wrong number of cards in discard pile of player 0\n");
            }
        }
        else if(choice1 == 0 && choice2 == 1 && other_handcount >= 5){
            if(initial.handCount[0] != 9){
                printf("wrong number of cards in hand of player 0\n");
            }
            if(initial.handCount[1] != 4){
                printf("wrong number of cards in hand of player 1\n");
            }
            if(initial.deckCount[0] != 1){
                printf("wrong number of cards in deck of player 0\n");
            }
            if(initial.deckCount[1] != 6){
                printf("wrong number of cards in deck of player 1\n");
            }
            if(initial.discardCount[0] != 1){
                printf("wrong number of cards in discard pile of player 0\n");
            }
            if(initial.discardCount[1] != 5){
                printf("wrong number of cards in discard pile of player 1\n");
            }
        }
        else if(choice1 == 0 && choice2 == 1 && other_handcount < 5){
            if(initial.handCount[0] != 9){
                printf("wrong number of cards in hand of player 0\n");
            }
            if(initial.handCount[1] != other_handcount){
                printf("wrong number of cards in hand of player 1\n");
            }
            if(initial.deckCount[0] != 1){
                printf("wrong number of cards in deck of player 0\n");
            }
            if(initial.deckCount[1] != 10){
                printf("wrong number of cards in deck of player 1\n");
            }
            if(initial.discardCount[0] != 1){
                printf("wrong number of cards in discard pile of player 0\n");
            }
            if(initial.discardCount[1] != 0){
                printf("wrong number of cards in discard pile of player 1\n");
            }
        }
        else if(choice1 == 1 && choice2 == 1){
            if(res == 0){
                printf("function incorrectly allowed user to gain two coins and four cards\n");
            }
        }
    }



    return 0;
}

int main(){

    test_minion();

    printf("done with randomtestcard1.c (target function handle_minion):\n\n");
    
}