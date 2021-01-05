#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

#define MAX_LINE_WIDTH 256

void read_board_size(FILE *file, Board *board);

void tokenize_board_file(FILE *file, int height, int width, char tokens[][4]);

void read_player_info(FILE *file, Game *game, int *are_we_on_list);

#endif // FILE_PARSER_H