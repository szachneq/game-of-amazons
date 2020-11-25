
#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

    


#define BOARD_SIZE 10

int g_amazons = 5;
int g_board[BOARD_SIZE][BOARD_SIZE];
int g_currentPlayer = 1;
int g_scores[2] = { 0, 0 };

typedef enum {
    NONE,
    BROKEN_ARROW,
    SPEAR,
    HORSE
} EArtifact;




#endif