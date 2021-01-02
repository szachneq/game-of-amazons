#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>

#include "board_entities.h"

typedef struct {
  Field *fields;
  int height;
  int width;
} Board;

Board create_board(int height, int width);

#endif // BOARD_H