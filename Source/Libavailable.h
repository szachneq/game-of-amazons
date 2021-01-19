#ifndef Libavailable_H_INCLUDED
#define Libavailable_H_INCLUDED
#include "Variables.h"
int is_move_possible(Game *game);
int can_amazon_move(Game *game);
int can_amazon_move_here(Game *game);
int can_amazon_throw_spear_here(Game *game);
#endif