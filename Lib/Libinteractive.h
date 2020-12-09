#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"

void generateBoard(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void presentBoardState(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void switch_player(int *current_player);
void placeAmazon(int player_id, position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
int can_place_here(position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void init_placement(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
    

#endif