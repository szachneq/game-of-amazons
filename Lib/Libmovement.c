#include "Libmovement.h"


EArtifact moveAmazon(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]) {
    // get user input and alter board state
    // by moving the amazon of the specified player
    // this function returns artifact from the tile
    // that player moved amazon to
    // also adds score for the player using the scores array
    
    return NONE;
}

void shootArrow(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]) {
    // shoot arrow code
    // printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]) {
    // printf("Player %d threw his spear!\n", player);
    // throw spear code
}

void placeAmazon(int player_id, position p) {

  g_board[p.y][p.x].playerID = player_id;
}