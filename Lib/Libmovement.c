#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libmovement.h"
#include "Libavaliable.h"
#include "Libinteractive.h"


EArtifact moveAmazon(int player, Field board[BOARD_SIZE][BOARD_SIZE]) {

    // 1. Ask which amazone to make move with
    // 2. Can chosen canAmazonMove()
    
    // 3. Where to move ?
    position p = { .x=0, .y=0 };
    while (1) {
        printf("Player %d, input coordinates for amazon to move (x, y): ", player);
        scanf("%d %d", &p.x, &p.y);

        // To make can_amazon_move_here() function

        // if (can_amazon_move_here(p, board)) 
        // {
        //     break;
        // }

    }

    // 4. Clean the old spot 

    // 5. Move amazon to new position
    board[p.y-1][p.x-1].playerID = player;

    //6. addScore()

    //7. Return artifact form new spot

    return NONE;
}

void shootArrow(int player, Field board[BOARD_SIZE][BOARD_SIZE]) {

    // shoot arrow code
        int a,b;
	    printf("Player %d :enter coordinates to shoot an arrow\n", player);
    
		scanf(" %d %d", &a, &b);
        if( isThrowArrow(board[a-1][b-1].playerID))
        {
            board[a-1][b-1].playerID = 9;        
        }
        printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field board[BOARD_SIZE][BOARD_SIZE]) {

     int a,b;
	    printf("Player %d :enter coordinates to shoot an spear\n", player);
    
		scanf(" %d %d", &a, &b);
        if(isThrowSpear(board[a-1][b-1].playerID))
        {
            board[a-1][b-1].playerID = 9;        
        }
        printf("Player %d threw his spear!\n", player);
}

void initMovement( Field board[BOARD_SIZE][BOARD_SIZE] ) {

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