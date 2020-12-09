#ifndef LIBAVALIABLE_H_INCLUDED
#define LIBAVALIABLE_H_INCLUDED
#include "Variables.h"
int isMovePossible(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player);
int isThrowArrow(int isArrow);
int isThrowSpear(int isSpear);
int canAmazonMove(position p);
#endif