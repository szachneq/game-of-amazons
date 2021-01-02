#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_codes.h"
#include "game.h"

void cli_parse(int argc, char *argv[], Game *game, char input_board_file_name[32], char output_board_file_name[32]);

EPhase read_phase(int argc, char *argv[]);

int read_amazons(int argc, char *argv[]);

#endif // CLI_PARSER_H