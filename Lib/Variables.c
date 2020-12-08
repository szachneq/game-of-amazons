#include "Variables.h"

typedef enum {
    NONE = 0,
    HORSE = 1,
    BROKEN_ARROW = 2,
    SPEAR = 3,
} EArtifact;

typedef struct {
    int value;
    EArtifact artifact;  
    int playerID;
} Field;

typedef struct {
  int x;
  int y;
} position;

Field g_board[BOARD_SIZE][BOARD_SIZE];
int g_current_player = 1;
int g_scores[2] = { 0, 0 };