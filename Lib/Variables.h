
#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#define BOARD_SIZE 10

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

#endif