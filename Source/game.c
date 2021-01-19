#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "board.h"
#include "cli_parser.h"
#include "file_parser.h"

Game create_game(int argc, char *argv[]) {
  Game game;

  cli_parse(argc, argv, &game);

  load_game_state(&game);

  return game;
}

int get_our_id(Game *game) {
  int our_id = 0;
  for (int i = 0; i < game->num_players; i++) {
    if (strcmp(game->players[i].name, "GROUP_E") == 0) {
      our_id = game->players[i].id;
    }
  }
  if (our_id < 1) {
    exit(INTERNAL_ERROR);
  }
  return our_id;
}

int count_our_amazons(Game *game) {
  int our_id = get_our_id(game);
  int num_fields = game->board.height * game->board.width;
  int num_amazons = 0;
  for (int i = 0; i < num_fields; i++) {
    if (game->board.fields[i].player_id == our_id) {
      num_amazons += 1;
    }
  }
  return num_amazons;
}

void place_amazon_randomly(Game *game) {
  int our_id = get_our_id(game);
  int num_fields = game->board.height * game->board.width;
  for (int i = 0; i < num_fields; i++) {
    int r = rand() % num_fields;
    if (game->board.fields[r].player_id == 0) {
      game->board.fields[r].player_id = our_id;
      return;
    }
  }
  exit(MOVE_IMPOSSIBLE);
}