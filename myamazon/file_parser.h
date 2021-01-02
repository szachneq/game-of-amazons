#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_WIDTH 256

void read_board_size(FILE *file, int *height, int *width);

#endif // FILE_PARSER_H