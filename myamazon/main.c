#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "error_codes.h"
#include "cli_parser.h"
#include "game.h"
#include "file_parser.h"
#include "board_entities.h"

int main(int argc, char *argv[]) {
  // Code for autonomous mode
  srand(time(NULL));
  Game game = create_game(argc, argv);

  if (game.phase == PLACEMENT) {
    if (count_our_amazons(&game) >= game.amazons) {
      printf("cant place more amazons, limit exceeded \n");
      exit(MOVE_IMPOSSIBLE);
    }
    place_amazon_randomly(&game);
  }

  if (game.phase == MOVEMENT) {
    int our_id = get_our_id(&game);
    Field *amazon_to_move = NULL;
    Position amazon_position;
    for (int row = 1; row <= game.board.height; row++) {
      for (int column = 1; column <= game.board.width; column++) {
        Position p = { .x = column, .y = row };
        Field *f = get_field(game.board, p);
        int can_move = 0;
        if (f->player_id == our_id) {
          for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
              Position r = { .x = column-1+j, .y = row-1+i };
              Field *test = get_field(game.board, r);
              if (test == NULL) continue;
              if (test->player_id == 0) { 
                can_move = 1;
                amazon_position = p;
              }
            }
          }
        }
        if (can_move == 1) {
          amazon_to_move = f;
          printf("Can move amazon \n");
          printf("on position x:%d, y:%d \n", amazon_position.x, amazon_position.y);
        }
      }
    }
  }

  // Example code for automatic mode
  // for (int row = 1; row <= game.board.height; row++) {
  //   for (int column = 1; column <= game.board.width; column++) {
  //     Position p = { .x=column, .y=row };
  //     Field *f = get_field(game.board, p);
  //     f->player_id = 5;
  //   }
  // }

  // for (int i = 0; i < game.num_players; i++) {
  //   game.players[i].id, game.players[i].points = 420;
  // }

  write_game_state(&game);
  // End of autonomnous code

  exit(PROGRAM_SUCCESS);
}
