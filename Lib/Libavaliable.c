#include "Libavaliable.h"

int isMovePossible(Field board[BOARD_SIZE][BOARD_SIZE])
 {
    // is it possible to perform any move
    return 0;
}
int canPlaceHere(position p, Field board[BOARD_SIZE][BOARD_SIZE]) {
    if (p.x < 1 || p.y < 1) return 0;
    if (p.x > BOARD_SIZE || p.y > BOARD_SIZE) return 0;
    if (board[p.x-1][p.y-1].playerID != 0) return 0;
    return 1;
    return 0;
}
int isThrowArrow(Field board [BOARD_SIZE][BOARD_SIZE]);
int isThrowSpear(Field board [BOARD_SIZE][BOARD_SIZE]);
