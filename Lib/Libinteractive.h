#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include "Variables.h"

void generateBoard(Field g_board[BOARD_SIZE][BOARD_SIZE]);
void presentBoardState(Field g_board[BOARD_SIZE][BOARD_SIZE]);
void switchPlayer(int *player);

    

#endif