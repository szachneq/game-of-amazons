#include "Libavaliable.h"

int isMovePossible(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player)
 {
    // 1. Find all player amazons (x,y coordinates) array of c coordinates ( position coordinates[n] )
    // 2. For at least one amaznon if there is an unoccupied field n*canAmazonMove()

    // Ask if one player can play if the other cannot move?

    // 3. Return result

    return 1;
}

int canAmazonMove(position p){
    
    // takes x,y ind returns if the can be move done

    return 1;
}



int canPlaceHere(position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
    if (p.x < 1 || p.y < 1) return 0;
    if (p.x > BOARD_SIZE || p.y > BOARD_SIZE) return 0;
    if (board[p.x][p.y].playerID != 0) return 0;
    return 1;
    return 0;
}

int isThrowArrow(int isArrow){
    // vertically, horizontally, diagonally from amazon + obsticles
    if(isArrow == 0){
        return 1;
    }else{
        return 0;
    }
};

int isThrowSpear(int isSpear){
    // vertically, horizontally, diagonally from amazon
    if(isSpear == 0){
        return 1;
    }else{
        return 0;
    }
};

