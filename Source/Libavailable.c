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
    for(int i = 1; i< 11; i++){
        for(int j = 1; j< 11; j++){

            position p = {.x= i, .y=j};
            if(board[p.y][p.x].playerID == player){
                if(canAmazonMove(p ,board)){
                    return 1;
                }
            }

        }
    }


    return 0;
}

int canAmazonMove(position p, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
    // takes coordinates of amazon on the board
    // and returns whether it can move
    int can_move = 0;
    if (board[p.y-1][p.x-1].playerID == 0) { can_move = 1; }
    if (board[p.y-1][p.x+1].playerID == 0) { can_move = 1; }
    if (board[p.y][p.x-1].playerID   == 0) { can_move = 1; }
    if (board[p.y][p.x+1].playerID   == 0) { can_move = 1; }
    if (board[p.y-1][p.x].playerID   == 0) { can_move = 1; }
    if (board[p.y+1][p.x].playerID   == 0) { can_move = 1; }
    if (board[p.y+1][p.x-1].playerID == 0) { can_move = 1; }
    if (board[p.y+1][p.x+1].playerID == 0) { can_move = 1; }

    return can_move;
}

int isDiagonall(position p, position pAamazon){
    int xCor = abs(p.x - pAamazon.x);
    int yCor = abs(p.y - pAamazon.y);

    return (xCor == yCor) ? 1 : 0;
}

int isPathClear(position p, position pAamazon, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], ERoadType type, int player) {
    
    // type is trip of amazon verticall(1), horizontall(2), diagonall (3)
    switch(type)
    {
        case VERTICALL:
            if((pAamazon.y - p.y) < 0){
                for(int i=pAamazon.y; i<=p.y; i++){
                    if(board[i+1][pAamazon.x].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }else{
                for(int i=p.y; i<pAamazon.y; i++){
                    if(board[i][pAamazon.x].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }
            break;
        case HORIZONTALL:
            if((pAamazon.x - p.x) < 0){
                for(int i=pAamazon.x; i<=p.x; i++){
                    if(board[pAamazon.y][i+1].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }else{
                for(int i=p.x; i<pAamazon.x; i++){
                    if(board[pAamazon.y][i].playerID!=0){
                        printf("There is an obstacle on the path\n");
                        return 0;
                    }
                }
            }
            break;
        case DIAGONALL:
            if((pAamazon.x - p.x) < 0){
                if((pAamazon.y - p.y) < 0){
                    
                    for(int i=pAamazon.x; i < p.x; i++){
                        int temp = 1;
                        if(board[pAamazon.y+temp][pAamazon.x+temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }
                }else{
                    for(int i=pAamazon.x; i < p.x; i++){
                        int temp = 1;
                        if(board[pAamazon.y-temp][pAamazon.x+temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }  
                }   
            }else{
                if((pAamazon.y - p.y) < 0){
                    for(int i=p.x; i < pAamazon.x; i++){
                        int temp = 1;
                        if(board[pAamazon.y+temp][pAamazon.x-temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }  
                }else{
                    for(int i=p.x; i < pAamazon.x; i++){
                        int temp = 1;
                        if(board[pAamazon.y-temp][pAamazon.x-temp].playerID!=0){
                            printf("There is an obstacle on the path\n");
                            return 0;
                        }
                        temp++;
                    }
                }
            }
            break;
    }
  
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
    if(isDiagonall(p, pAamazon)){
        return isPathClear(p, pAamazon, board, (ERoadType)3, player);
    }  
    
    printf("Amazon can only shoot vertically, horizontally and diagonally\n");

    return 0;
}

int canAmazonThrowSpearHere(position p, position pAamazon, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int player) {
    // cheack vertically, horizontally, diagonally from amazon if amazon can move and of the field is free
    if(p.x == pAamazon.x){
        if(board[p.y][p.x].playerID == 0){
            return 1;
        }    
    }
    if(p.y == pAamazon.y){
        if(board[p.y][p.x].playerID == 0){
            return 1;
        } 
    }
    if(isDiagonall(p, pAamazon)){
        if(board[p.y][p.x].playerID == 0){
            return 1;
        } 
    }  
    
    printf("Amazon can only shoot vertically, horizontally and diagonally\n");

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

int isThrowSpear(int isSpear) {
    // vertically, horizontally, diagonally from amazon
    if(isSpear == 0){
        return 1;
    }else{
        return 0;
    }
};
