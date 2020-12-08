#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include "Variables.h"

void generateBoard(Field board[BOARD_SIZE][BOARD_SIZE]);
void presentBoardState(Field board[BOARD_SIZE][BOARD_SIZE]);
void switch_player(int *current_player);
int can_place_here(position p, Field board[BOARD_SIZE][BOARD_SIZE]);
void init_placement(Field board[BOARD_SIZE][BOARD_SIZE]);
    

#endif