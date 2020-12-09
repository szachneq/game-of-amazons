#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"
#include "Libavaliable.h"
#include "Libinteractive.h"

EArtifact moveAmazon(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void shootArrow(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void switchPlayer(int *current_player);
void throwSpear(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void initMovement( Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE] );

#endif