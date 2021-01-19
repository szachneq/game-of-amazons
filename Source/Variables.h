
#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#define BOARD_SIZE 10
#define INTERNAL_BOARD_SIZE 12

typedef enum {
    NONE = 0,
    HORSE = 1,
    BROKEN_ARROW = 2,
    SPEAR = 3,
} EArtifact;

typedef enum {
    VERTICALL = 1,
    HORIZONTALL = 2,
    DIAGONALL = 3,
} ERoadType;


typedef struct {
    int value;
    EArtifact artifact;  
    int playerID;
} Field;

typedef struct {
  int x;
  int y;
} position;


#endif