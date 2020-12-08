#ifndef LIBINTERACTIVE_H_INCLUDED
#define LIBINTERACTIVE_H_INCLUDED
#include "Variables.h"

void generateBoard();
void presentBoardState();
void switchPlayer();
int can_place_here(position p);
void initPlacement();
    

#endif