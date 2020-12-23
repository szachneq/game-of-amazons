#include "Libavailable.h"
#include "Variables.h"
#include <stdio.h>
#include "Libinteractive.h"
#include <math.h>

int isMovePossible(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player)
 {
     // TODO
    // 1. Find all player amazons (x,y coordinates) array of c coordinates ( position coordinates[n] )
    // 2. For at least one amaznon if there is an unoccupied field n*canAmazonMove()
    // Ask if one player can play if the other cannot move?
    // 3. Return result

    return 1;
}

int canAmazonMove(position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
    // takes coordinates of amazon on the board
    // and returns whether it can move
    int can_move = 0;
    if (board[p.y-1][p.x-1].playerID == 0) { can_move = 1; }
    if (board[p.y-1][p.x].playerID   == 0)   { can_move = 1; }
    if (board[p.y-1][p.x+1].playerID == 0) { can_move = 1; }
    if (board[p.y][p.x-1].playerID   == 0)   { can_move = 1; }
    if (board[p.y][p.x+1].playerID   == 0)   { can_move = 1; }
    if (board[p.y+1][p.x-1].playerID == 0) { can_move = 1; }
    if (board[p.y+1][p.x].playerID   == 0)   { can_move = 1; }
    if (board[p.y+1][p.x+1].playerID == 0) { can_move = 1; }

    return can_move;
}

int isDiagonall(position p, position pAamazon){
    int xCor = abs(p.x - pAamazon.x);
    int yCor = abs(p.y - pAamazon.y);

    return (xCor = yCor) ? 1 : 0;
}

int isPathClear(position p, position pAamazon, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], ERoadType type, int player) {
    
    // type is trip of amazon verticall(1), horizontall(2), diagonall (3)
    board[p.y][p.x].playerID = player;
    presentBoardState(board);
    return 1;

}

int canAmazonMoveHere(position p, position pAamazon, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player) {
    // cheack vertically, horizontally, diagonally from amazon if amazon can move and of the field is free
    if(p.x == pAamazon.x){
        return isPathClear(p, pAamazon, board, (ERoadType)1, player);
        }
    if(p.y == pAamazon.y){
        return isPathClear(p, pAamazon, board, (ERoadType)2, player);
        }
    if(can_place_here(p, board)){
        if(isDiagonall(p, pAamazon)){
            isPathClear(p, pAamazon, board, (ERoadType)3, player);
        }  
    }
    return 0;
}

int can_place_here(position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
    if (p.x < 1 || p.y < 1) 
    {
        printf("Under boundries\n");
        return 0; 
        }
    if (p.x > BOARD_SIZE || p.y > BOARD_SIZE)  {
        printf("Over boundries\n");
        return 0; 
        }
    if (board[p.y][p.x].playerID != 0) {
        printf("Field is occupied\n");
        return 0; 
        }
        printf("Sucessful placement\n");
      return 1;
}

int isThrowArrow(int isArrow) {
    // vertically, horizontally, diagonally from amazon + obsticles
    if(isArrow == 0){
        return 1;
    }else{
        return 0;
    }
};

int isThrowSpear(int isSpear) {
    // vertically, horizontally, diagonally from amazon
    if(isSpear == 0){
        return 1;
    }else{
        return 0;
    }
};

