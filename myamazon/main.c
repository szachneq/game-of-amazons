#include <stdio.h>

#include "board.h"
#include "file_parser.h"
#include "error_codes.h"
#include "cli_parser.h"
#include "game.h"



int main(int argc, char *argv[]) {


  Game game;
  char input_board_file_name[32];
  char output_board_file_name[32];
  int game_init_status;

  // start of game initialization

  game_init(argc, argv, &game, input_board_file_name,output_board_file_name, &game_init_status);

  if ( game_init_status == INPUT_FILE_ERROR ){
    printf("Cannot open game state file \"%s\" \n", input_board_file_name);
    return INPUT_FILE_ERROR;
  }

  // end of game initialization

  for (int row = 1; row <= game.board.height; row++) {
    for (int column = 1; column <= game.board.width; column++) {
      Position p = { .x=column, .y=row };
      Field *f = get_field(game.board, p);
      f->player_id = 5;
    }
  }

  for (int i = 0; i < game.num_players; i++) {
    game.players[i].id, game.players[i].points = 420;
  }


  // start of turning game state into file

  game_write_file(&game, output_board_file_name);
  
  // end of turning game state into file

  return PROGRAM_SUCCESS;
}
