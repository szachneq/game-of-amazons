#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include "Variables.h"

void generateBoard(Field board[BOARD_SIZE][BOARD_SIZE]);
void presentBoardState(Field board[BOARD_SIZE][BOARD_SIZE]);
int canPlaceHere(position p, Field board[BOARD_SIZE][BOARD_SIZE]);
void initPlacement(Field board[BOARD_SIZE][BOARD_SIZE]);
    

#endif