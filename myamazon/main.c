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

  cli_parse(argc, argv, &game, input_board_file_name, output_board_file_name);
  if (game.phase == PLACEMENT) {
    printf("placement \n");
  }

  if (game.phase == MOVEMENT) {
    printf("movement \n");
  }
  
  printf("amazons: %d \n", game.amazons);

  printf("Input board file name: %s \n", input_board_file_name);
  printf("Output board file name: %s \n", output_board_file_name);

  // token = strtok_r(rest, "=", &rest);
  // *width = atoi(token);

  // for (int i = 0; i < argc; i++) {
  //   printf("%s \n", argv[i]);
  // }

  // const char *file_name = argv[1];
  // FILE *file = fopen(file_name, "r");

  // if (file == NULL) {
  //   printf("Cannot open game state file \"%s\" \n", file_name);
  //   return INPUT_FILE_ERROR;
  // }

  // int height, width;
  // read_board_size(file, &height, &width);
  // printf("Height: %d \n", height);
  // printf("Width: %d \n", width);

  // Board board = create_board(height, width);
  // printf("board height: %d \n", board.height);
  // printf("board width: %d \n", board.width);

  // board.fields[0].value = 10;

  // printf("%d", board.fields[0].value);

  // fclose(file);

  return PROGRAM_SUCCESS;
}