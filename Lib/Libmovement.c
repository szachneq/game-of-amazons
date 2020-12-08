#include "Libmovement.h"


EArtifact moveAmazon(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]) {
    // get user input and alter board state
    // by moving the amazon of the specified player
    // this function returns artifact from the tile
    // that player moved amazon to
    // also adds score for the player using the scores array
    
    return NONE;
}

void shootArrow(int player, Field board[BOARD_SIZE][BOARD_SIZE]) {

    // shoot arrow code
        int a,b;
	    printf("enter coordinates to shoot an arrow\n");
    
		scanf(" %d %d", &a, &b);
        if( isThrowArrow(board[a-1][b-1]))
        {
        board[a-1][b-1].playerID = 9;        
        }
        printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field board[BOARD_SIZE][BOARD_SIZE]) {

    // printf("Player %d threw his spear!\n", player);
     int a,b;
	    printf("enter coordinates to shoot an arrow\n");
    
		scanf(" %d %d", &a, &b);
        if(isThrowSpear(board[a-1][b-1]))
        {
            board[a-1][b-1].playerID = 9;        
        }
        printf("Player %d shoot his spear!\n", player);
}
    // throw spear code
}

void placeAmazon(int player_id, position p) {
  g_board[p.y][p.x].playerID = player_id;
}