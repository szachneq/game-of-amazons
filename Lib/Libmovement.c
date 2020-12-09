#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libmovement.h"
#include "Libavailable.h"
#include "Libinteractive.h"

EArtifact moveAmazon(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
    EArtifact currFieldArtifact;
    position pAamazon = { .x=0, .y=0 }, p = { .x=0, .y=0 };

    // 1. Ask which amazone to make move with
    while (1) {
        do{
        printf("Player %d, input coordinates for amazon that you want to move (x, y): ", player);
        scanf("%d %d", &pAamazon.x, &pAamazon.y);
        }while(board[pAamazon.x-1][pAamazon.y-1].playerID != 1 || board[pAamazon.x-1][pAamazon.y-1].playerID != 2 );
         

        if(board[pAamazon.y][pAamazon.x].playerID = player){
            
            if(canAmazonMove(pAamazon, board)){
                
                while (1) {
                    printf("Player %d, input coordinates for amazon to move (x, y): ", player);
                    scanf("%d %d", &p.y, &p.x);

                // To make can_amazon_move_here() function

                if (canAmazonMoveHere(p, board)) 
                {
                    break;
                }

                }  
                break;         
            }
        }
    }

    // 4. Clean the old spot 
    board[pAamazon.y][pAamazon.x].playerID = 0;
    // 5. Move amazon to new position
    board[p.y][p.x].playerID = player;
    // 6. addScore()
    addScore(board[p.y][p.x].value, player);
    // 7. Return artifact form new spot
    currFieldArtifact = (EArtifact) board[p.y][p.x].artifact;
    return currFieldArtifact;
}

void shootArrow(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {

    // shoot arrow code
        int a,b;
	    printf("Player %d :enter coordinates to shoot an arrow\n", player);
    
		scanf(" %d %d", &a, &b);
        if( isThrowArrow(board[a][b].playerID))
        {
            board[a][b].playerID = 9;        
        }
        printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {

     int a,b;
	    printf("Player %d :enter coordinates to shoot an spear\n", player);
    
		scanf(" %d %d", &a, &b);
        if(isThrowSpear(board[a][b].playerID))
        {
            board[a][b].playerID = 9;        
        }
        printf("Player %d threw his spear!\n", player);
}

void initMovement( Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE] ) {

        int current_player = 1;

        while (1) {
        presentBoardState(board);
        EArtifact artifact = moveAmazon(current_player, board);
        switch(artifact) {
            case BROKEN_ARROW:
                switch_player(&current_player);
                break;
            case SPEAR:
                throwSpear(current_player, board);
                switch_player(&current_player);
                break;
            case HORSE:
                shootArrow(current_player, board);
                break;
            case NONE:
                shootArrow(current_player, board);
                switch_player(&current_player);
                break;
        }
        if (!isMovePossible(board, current_player)) break;
    }
}