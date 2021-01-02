#include <stdlib.h>

#include "board_entities.h"
#include "board.h"

Board create_board(int height, int width) {
  Board board;
  board.height = height;
  board.width = width;
  board.fields = (Field*) malloc(sizeof(Field) * height * width);
  return board;
}


