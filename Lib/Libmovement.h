#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"
#include "Libavailable.h"
#include "Libinteractive.h"

EArtifact chooseAmazon(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int* g_score);
EArtifact moveAmazon(int player,  Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int* g_score);
void shootArrow(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void switch_player(int *current_player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void throwSpear(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]);
void initMovement( Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int* g_scores);

#endif