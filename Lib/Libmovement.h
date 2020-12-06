#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include "Variables.h"

EArtifact moveAmazon(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]);


void shootArrow(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]);


void throwSpear(int player, Field g_board[BOARD_SIZE][BOARD_SIZE]);

void placeAmazon(int player);


#endif