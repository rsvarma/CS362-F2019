#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int test_ambassador(){
    // set card array to include minion
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall };
    // declare the game state
    struct gameState G;

    initializeGame(2, k, 6, &G); // initialize a new game state
   
    int successful = 0;
    printf("Test 1: Player 0 reveals a copper, returns two coppers to supply:\n\n");
    //Pre Game State Requirements: Player 0 an ambassador in hand and 2 or more coppers
    //Post Game State Requirements: Player 0 returns 2 coppers to supply, Player 1 gains two coppers
    struct gameState initial = G;
    //set pre game state
    initial.hand[0][0] = copper; 
    initial.hand[0][1] = ambassador;
    initial.hand[0][2] = copper;
    initial.hand[0][3] = copper;
    initial.hand[0][4] = copper;
    initial.handCount[0] = 5;
    initial.discardCount[1] = 0;
    int initial_coppers = initial.supplyCount[4];
 

    //run function
    handle_ambassador(0,2,1,&initial,0);

    if(initial_coppers+2 != initial.supplyCount[4]){
        printf("action failed, coppers were not returned to supply\n");
        successful = 1;
    }
    if(initial.discardCount[1] != 2){
        printf("action failed, other player did not gain two coppers\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nAmbassador test 1 succeeded!\n\n");
    }else{
        printf("\nAmbassador test 1 failed\n\n");
    }


    successful = 0;
    printf("Test 2l: Player 0 reveals a copper, tries to return three coppers to supply:\n\n");
    //Pre Game State Requirements: Player 0 has an ambassador in hand and 3 or more coppers
    //Post Game State Requirements: invalid action, action is denied
    initial = G;
    //set pre game state
    initial.hand[0][0] = copper; 
    initial.hand[0][1] = ambassador;
    initial.hand[0][2] = copper;
    initial.hand[0][3] = copper;
    initial.hand[0][4] = copper;
    initial.handCount[0] = 5;
    initial.discardCount[1] = 0;

 

    //run function
    int r = handle_ambassador(0,3,1,&initial,0);

    if(r == 0){
        printf("invalid action was allowed!\n");
        successful = 1;
    }
    if(successful == 0){
        printf("\nAmbassador test 2 succeeded!\n\n");
    }else{
        printf("\nAmbassador test 2 failed\n\n");
    }
    return 0;
}

int main(){

    test_ambassador();

    printf("done with unittest5.c (target function ambassador):\n\n");
    
}