#ifndef Libavailable_H_INCLUDED
#define Libavailable_H_INCLUDED
#include "Variables.h"
int isMovePossible(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player);
int isThrowArrow(int isArrow);
int isThrowSpear(int isSpear);
int canAmazonMove(position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
int canAmazonMoveHere(position p, position pAamazon,Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player);
#endif