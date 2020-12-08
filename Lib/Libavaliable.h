#ifndef LIBAVALIABLE_H_INCLUDED
#define LIBAVALIABLE_H_INCLUDED
#include "Variables.h"
int isMovePossible(Field board[BOARD_SIZE][BOARD_SIZE]);
int isThrowArrow(Field board [BOARD_SIZE][BOARD_SIZE]);
int isThrowSpear(Field board [BOARD_SIZE][BOARD_SIZE]);
#endif