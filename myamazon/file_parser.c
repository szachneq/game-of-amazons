#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_parser.h"

void read_board_size(FILE *file, int *height, int *width) {
  rewind(file);
  char line[MAX_LINE_WIDTH];
  fgets(line, MAX_LINE_WIDTH, file);
  char *token;
  char *rest = line;
  token = strtok_r(rest, " ", &rest);
  *height = atoi(token);
  token = strtok_r(rest, " ", &rest);
  *width = atoi(token);
}