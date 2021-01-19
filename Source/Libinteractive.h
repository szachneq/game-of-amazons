#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"

void generate_board(Game *game);
void present_board_state(Game *game);
void switch_player(int *current_player);
void place_amazon(Game *game, int player);
int can_place_here(Game *game);
void init_placement(Game *game);
void add_score(Game *game);
    

#endif
