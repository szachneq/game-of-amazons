#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_parser.h"
#include "game.h"

void read_board_size(FILE *file, Board *board) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  fgets(line, MAX_LINE_WIDTH, file);
  char *token;
  char *rest = line;
  token = strtok_r(rest, " ", &rest);
  board->height = atoi(token);
  token = strtok_r(rest, " ", &rest);
  board->width = atoi(token);
}

void tokenize_board_file(FILE *file, int height, int width, char tokens[][4]) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  char *token;
  // read first line but ignore the contents so that we skip to the board state
  fgets(line, MAX_LINE_WIDTH, file);
  // loop through lines with board state information
  for (int row = 0; row < height; row++) {
    fgets(line, MAX_LINE_WIDTH, file);
    char *rest = line;
    for (int column = 0; column < width; column++) {
      token = strtok_r(rest, " ", &rest);
      strcpy(tokens[row * width + column], token);
    }
  }
}

// reads player info into game object
void read_player_info(FILE *file, Game *game, int *are_we_on_list) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  // skip to the part of the file which stores player info
  for (int row = 0; row < game->board.height + 1; row++) {
    fgets(line, MAX_LINE_WIDTH, file);
    // printf("%s", line);
  }

  char *token;
  int index = 0;
  while (fgets(line, MAX_LINE_WIDTH, file)) {
    char *rest = line;
    token = strtok_r(rest, " ", &rest);
    // printf("%s \n", token);
    strcpy(game->players[index].name, token);
    token = strtok_r(rest, " ", &rest);
    // printf("%s \n", token);
    game->players[index].id = atoi(token);
    token = strtok_r(rest, " ", &rest);
    // printf("%s \n", token);
    game->players[index].points = atoi(token);

    if(game->players[index].name == TEAM_NAME){
      *are_we_on_list = 1;
    }

    index++;
  }

  game->num_players = index;
}