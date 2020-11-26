#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include "Variables.h"

EArtifact moveAmazon(int player, int g_board[BOARD_SIZE][BOARD_SIZE]);


void shootArrow(int player, int g_board[BOARD_SIZE][BOARD_SIZE]);


void throwSpear(int player, int g_board[BOARD_SIZE][BOARD_SIZE]);

void placeAmazon(int player);


#endif