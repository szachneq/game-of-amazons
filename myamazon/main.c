#include <stdio.h>

#include "board.h"
#include "file_parser.h"
#include "error_codes.h"
#include "cli_parser.h"
#include "game.h"

int main(int argc, char *argv[]) {

  // start of game initialization

  Game game;
  char input_board_file_name[32];
  char output_board_file_name[32];

  cli_parse(argc, argv, &game, input_board_file_name, output_board_file_name);

  FILE *file = fopen(input_board_file_name, "r");

  if (file == NULL) {
    printf("Cannot open game state file \"%s\" \n", input_board_file_name);
    return INPUT_FILE_ERROR;
  }

  read_board_size(file, &game.board);
  initialize_board(file, &game.board);
  read_player_info(file, &game);

  fclose(file);

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

  FILE *write_file = fopen(output_board_file_name, "w");

  fprintf(write_file, "%d %d\n", game.board.height, game.board.width);

  for (int row = 1; row <= game.board.height; row++) {
    for (int column = 1; column <= game.board.width; column++) {
      Position p = { .x=column, .y=row };
      Field *f = get_field(game.board, p);
      char token[4];
      field_to_token(*f, token);
      fprintf(write_file, "%s", token);
      if (column < game.board.width) fprintf(write_file, " ");
    }
    fprintf(write_file, "\n");
  }

  for (int index = 0; index < game.num_players-1; index++) {
    fprintf(write_file, "%s %d %d\n", game.players[index].name, game.players[index].id, game.players[index].points);
  }

  fprintf(write_file, "%s %d %d", game.players[game.num_players-1].name, game.players[game.num_players-1].id, game.players[game.num_players-1].points);

  fclose(write_file);

  // end of turning game state into file

  return PROGRAM_SUCCESS;
}
