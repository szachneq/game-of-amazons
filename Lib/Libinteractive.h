#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include "Variables.h"

void generateBoard(int g_board[BOARD_SIZE][BOARD_SIZE]);
void presentBoardState(int g_board[BOARD_SIZE][BOARD_SIZE]);
void switchPlayer(int *player);

    

#endif