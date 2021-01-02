#include <stdio.h>

#define PROGRAM_SUCCESS 0
#define MOVE_IMPOSSIBLE 1
#define INPUT_FILE_ERROR 2
#define INTERNAL_ERROR 3

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Filename not specified \n");
    return INPUT_FILE_ERROR;
  }

  const char *file_name = argv[1];
  FILE *file = fopen(file_name, "r");
  char line[256];

  if (file == NULL) {
    printf("Cannot open game state file \"%s\" \n", file_name);
    return INPUT_FILE_ERROR;
  }

  while(fgets(line, sizeof(line), file)) {
    printf("%s", line);
  }

  printf("\n\n");

  fclose(file);

  return 0;
}