#include <stdlib.h>
#include <stdio.h>

#include "error_codes.h"
#include "file_parser.h"
#include "cli_parser.h"
#include "game.h"
#include "board.h"


int are_we_on_list = 0;

int game_init(int argc, char **argv, Game *game, char *input_board_file_name, char *output_board_file_name, int *game_init_status){
    
  cli_parse(argc, argv, game, input_board_file_name, output_board_file_name);

  FILE *file = fopen(input_board_file_name, "r");

  if (file == NULL) {
    *game_init_status = INPUT_FILE_ERROR; 
  }

  read_board_size(file, &game->board);
  initialize_board(file, &game->board);
  read_player_info(file, game, &are_we_on_list);

  fclose(file);
}


void game_write_file(Game *game, char *output_board_file_name){
  FILE *write_file = fopen(output_board_file_name, "w");

  fprintf(write_file, "%d %d\n", game->board.height, game->board.width);

  for (int row = 1; row <= game->board.height; row++) {
    for (int column = 1; column <= game->board.width; column++) {
      Position p = { .x=column, .y=row };
      Field *f = get_field( game->board, p);
      char token[4];
      field_to_token(*f, token);
      fprintf(write_file, "%s", token);
      if (column < game->board.width) fprintf(write_file, " ");
    }
    fprintf(write_file, "\n");
  }

  // TODO
  /* If there is no row with player’s name 
  (at the beginning of the game) player must 
  add a corresponding row at the end of the file, 
  containing the name and setting consecutive player’s 
  number as the ID and initial points set to 0. Otherwise, 
  the player should alter his current score by the number 
  of the collected points, and leave other fields unchanged. */

  if(are_we_on_list == 0){

  if(game->num_players == 0){
      fprintf(write_file, "%s %d %d", TEAM_NAME, 1, 0);
  }else{
    for (int index = 0; index < game->num_players; index++) {
       fprintf(write_file, "%s %d %d\n", game->players[game->num_players-1].name, game->players[game->num_players-1].id, game->players[game->num_players-1].points);
    }
    fprintf(write_file, "%s %d %d\n", TEAM_NAME, game->players[game->num_players].id, 0);
    // Can Later Define Our Id
  }
  }else{
    for (int index = 0; index < game->num_players; index++) {
      if (index == game->num_players-1) {
        fprintf(write_file, "%s %d %d", game->players[index].name, game->players[index].id, game->players[index].points);
      } else {
       fprintf(write_file, "%s %d %d\n", game->players[game->num_players-1].name, game->players[game->num_players-1].id, game->players[game->num_players-1].points);
      }
  }
  }






  fclose(write_file);
}
