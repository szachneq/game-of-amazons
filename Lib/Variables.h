
#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

    
#define BOARD_SIZE 10

typedef enum {
    NONE,
    BROKEN_ARROW,
    SPEAR,
    HORSE
} EArtifact;

typedef struct {
    int value;
    EArtifact artifact;  
    int playerID;
    
}Field;

Field g_board[BOARD_SIZE][BOARD_SIZE];



#endif