#include <stdlib.h>
#include <stdio.h>

#include "board_entities.h"
#include "board.h"
#include "file_parser.h"

void initialize_board(FILE *file, Board *board) {
  char tokens[board->height * board->width * 4][4];
  tokenize_board_file(file, board->height, board->width, tokens);
  board->fields = (Field*) malloc(sizeof(Field) * board->height * board->width);
  for (int row = 0; row < board->height; row++) {
    for (int column = 0; column < board->width; column++) {
      board->fields[row * board->width + column] = field_from_token(tokens[row * board->width + column]);
    }
  }
}

Field field_from_token(char token[4]) {
  Field field;
  field.value = (int)(token[0] - '0');
  field.artifact = (EArtifact)(token[1] - '0');
  field.player_id = (int)(token[2] - '0');
  return field;
}

void field_to_token(Field field, char token[4]) {
  token[0] = field.value + '0';
  token[1] = (int)(field.artifact) + '0';
  token[2] = field.player_id + '0';
}

// get pointer to field using 1 based counting
Field *get_field(Board board, Position position) {
  int is_out_of_bounds= position.x > board.width ||
                        position.x < 1 ||
                        position.y > board.height ||
                        position.y < 1;
  if (is_out_of_bounds) {
    printf("Position provided to get field is out of bounds \n");
    printf("x: %d, y: %d \n", position.x, position.y);
    return NULL;
  }
  int x = position.x - 1;
  int y = position.y - 1;
  return &(board.fields[y * board.width + x]);
}
