#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "error_codes.h"
#include "cli_parser.h"
#include "game.h"
#include "file_parser.h"
#include "board_entities.h"

void get_movable_amazons(Game *game, Field *amazon_fields[], Position amazon_positions[], int *num_found_amazons) {
  int our_id = get_our_id(game);

  for (int row = 1; row <= game->board.height; row++) {
    for (int column = 1; column <= game->board.width; column++) {
      Position p = { .x = column, .y = row };
      Field *f = get_field(game->board, p);
      int can_move = 0;
      if (f->player_id == our_id) {
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            Position r = { .x = column-1+j, .y = row-1+i };
            Field *test = get_field(game->board, r);
            if (test == NULL) continue;
            if (test->player_id == 0) { 
              can_move = 1;
              amazon_positions[*num_found_amazons] = p;
            }
          }
        }
      }
      if (can_move == 1) {
        amazon_fields[*num_found_amazons] = f;
        *num_found_amazons += 1;
      }
    }
  }
}

int main(int argc, char *argv[]) {

  srand(time(NULL));
  Game game = create_game(argc, argv);

  if (game.phase == PLACEMENT) {
    if (count_our_amazons(&game) >= game.amazons) {
      printf("Can't place more amazons, limit exceeded \n");
      exit(MOVE_IMPOSSIBLE);
    }
    place_amazon_randomly(&game);
  }

  if (game.phase == MOVEMENT) {
    int our_id = get_our_id(&game);
    
    Field *amazon_fields[20];
    Position amazon_positions[20];
    int num_found_amazons = 0;

    get_movable_amazons(&game, amazon_fields, amazon_positions, &num_found_amazons);

    if (num_found_amazons < 1) {
      printf("Cant move any amazon.\n");
      exit(MOVE_IMPOSSIBLE);
    }

    printf("Found our movable amazons: \n");
    for (int i = 0; i < num_found_amazons; i++) {
      printf("Position x:%d, y:%d \n", amazon_positions[i].x, amazon_positions[i].y);
    }
    
    int index = rand() % num_found_amazons; // randomly choose amazon to move

    Position old_position = amazon_positions[index];
    Field *old_field = get_field(game.board, old_position);

    do {
      Position new_position;
      Field *new_field;
      int moved = 0;
      int counter = 0;
      while (!moved) {
        int x_dir = (rand() % 3) - 1;
        int y_dir = (rand() % 3) - 1;
        Position r = { .x = amazon_positions[index].x+x_dir, .y = amazon_positions[index].y+y_dir };
        Field *test = get_field(game.board, r);
        if (test == NULL) continue;
        if (test->player_id == 0) {
          old_field->player_id = 0;
          new_position.x = r.x;
          new_position.y = r.y;
          new_field = get_field(game.board, new_position);
          new_field->player_id = our_id;
          game.players[our_id-1].points += new_field->value;
          new_field->value = 0;
        }
        counter++;
        if (counter > 10) { break; }
      }
      
      if (new_field->artifact == NONE || new_field->artifact == SPEAR) {
        old_field->player_id = 9;
        break;
      }
      if (new_field->artifact == BROKEN_ARROW) {
        break;
        // just do nothing
      }
      if (new_field->artifact == HORSE) {
        printf("doing horse stuff \n");
        old_field->player_id = 9;
        old_field = get_field(game.board, new_position);
        old_position.x = new_position.x;
        old_position.y = new_position.y;
        break;
      }

    } while (1);

  }

  write_game_state(&game);

  exit(PROGRAM_SUCCESS);
}
