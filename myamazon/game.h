#ifndef GAME_H
#define GAME_H

#include "board.h"

#define MAX_PLAYERS 8
#define TEAM_NAME "GROUP_E"

typedef struct {
  char name[16];
  int id;
  int points;
} Player;

typedef enum {
  PLACEMENT,
  MOVEMENT,
} EPhase;

typedef struct {
  Board board;
  EPhase phase;
  Player players[MAX_PLAYERS];
  int amazons;
  int num_players;
} Game;

int game_init(int argc, char **argv, Game *game, char *input_board_file_name, char *output_board_file_name, int *game_init_status);

void game_write_file(Game *game, char *output_board_file_name);

#endif // GAME_H