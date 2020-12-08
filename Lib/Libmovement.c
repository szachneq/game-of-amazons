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
      //      int a,b;
	//		printf("enter coordinates to shoot an arrow\n");
	//		scanf(" %d %d", &a, &b);
            
			
    //printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field board[BOARD_SIZE][BOARD_SIZE]) {
    // printf("Player %d threw his spear!\n", player);
    // throw spear code
}

void placeAmazon(int player_id, position p, Field board[BOARD_SIZE][BOARD_SIZE]) {

  board[p.y][p.x].playerID = player_id;
}

void switchPlayer(int *current_player) {
    if (current_player == 1) current_player = 2;
    if (current_player == 2) current_player = 1;
}

void initMovement( Field board[BOARD_SIZE][BOARD_SIZE] ){

        int current_player = 1;

        while (1) {
        presentBoardState();
        EArtifact artifact = moveAmazon(current_player, board[0]);
        switch(artifact) {
            case BROKEN_ARROW:
                switchPlayer(&current_player);
                break;
            case SPEAR:
                throwSpear(current_player, board[0]);
                switchPlayer(&current_player);
                break;
            case HORSE:
                shootArrow(current_player, board[0]);
                break;
            case NONE:
                shootArrow(current_player, board[0]);
                switchPlayer(&current_player);
                break;
        }
        if (!isMovePossible(board[0])) break;
    }
}