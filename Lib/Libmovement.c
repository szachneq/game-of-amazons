#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libmovement.h"
#include "Libavailable.h"
#include "Libinteractive.h"

int g_isHorse;
position pAamazon;


EArtifact chooseAmazon(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int* g_scores)
{   
    while (!g_isHorse) 
    {
        do{
        printf("Player %d, input coordinates for amazon that you want to move (x, y): ", player);
        scanf("%d %d", &pAamazon.x, &pAamazon.y);
            if(board[pAamazon.y][pAamazon.x].playerID != player) 
            {
                printf("Hmmm, missclick?\n");
            }
        }while(board[pAamazon.y][pAamazon.x].playerID != player);

            if((board[pAamazon.y][pAamazon.x].playerID == player) && canAmazonMove(pAamazon, board)) 
            {
                return moveAmazon(player, board, g_scores);
            }
    }
    if(g_isHorse) 
    {       
        g_isHorse = 0;
        return moveAmazon(player, board, g_scores);
    }





}

EArtifact moveAmazon(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int *g_scores) {
 
    EArtifact currFieldArtifact;

    // 1. Input spot to move to 
        position correctAmazon = pAamazon;
        position p = {.x= 0, .y=0};
        
        do
        {
            printf("Player %d, input coordinates for amazon to move (x, y): ", player);
            scanf("%d %d", &p.x, &p.y);
        } while(canAmazonMoveHere(p, correctAmazon, board, player) == 0);

                
    // 4. Clean the old spot
    board[pAamazon.y][pAamazon.x].playerID = 0;
    board[pAamazon.y][pAamazon.x].artifact = 0;
    board[pAamazon.y][pAamazon.x].value = 0;

    // 5. Move amazon to new position
    board[p.y][p.x].playerID = player;

    currFieldArtifact = (EArtifact) board[p.y][p.x].artifact;
    // 5.1 update amazon position

    pAamazon = p;


    // 6. addScore()
    addScore(board[p.y][p.x].value, player, g_scores);

    // Clear new spot
    board[p.y][p.x].value = 0;
    board[p.y][p.x].artifact = 0;


    return currFieldArtifact;

}

void addScore(int value, int player, int* g_scores){
    g_scores[player-1] += value;
}

void shootArrow(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {

    // shoot arrow code
        position arrow;

        do{
	        printf("Player %d, enter coordinates to shoot an arrow (x, y):", player);
		    scanf("%d %d", &arrow.x, &arrow.y);

            if(canAmazonMoveHere( arrow, pAamazon, board, player)){
            board[arrow.y][arrow.x].playerID = 9;        
            board[arrow.y][arrow.x].value = 0;        
            board[arrow.y][arrow.x].artifact = 0;  
            break;
            }
        }while(1);

        printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {

    position spear;
        do{
	        printf("Player %d, enter coordinates to shoot an spear", player);
		    scanf("%d %d", &spear.x, &spear.y);

            if(canAmazonThrowSpearHere( spear, pAamazon, board, player)){
            board[spear.y][spear.x].playerID = 9;        
            board[spear.y][spear.x].value = 0;        
            board[spear.y][spear.x].artifact = 0;  
            break;
            }
        }while(1);
        printf("Player %d threw his spear!\n", player);
}

void initMovement(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE], int* g_scores) 
{

        int current_player = 1;

        while (1) 
        {
                if (!isMovePossible(board ,current_player)) break;

                presentBoardState(board);
                EArtifact artifact = chooseAmazon(current_player, board, g_scores);

                switch(artifact)
                {
                    case BROKEN_ARROW:
                        switch_player(&current_player,board);
                        break;
                    case SPEAR:
                        presentBoardState(board);
                        throwSpear(current_player, board);
                        switch_player(&current_player,board);
                        break; 
                    case HORSE:
                        presentBoardState(board);
                        shootArrow(current_player, board);
                        g_isHorse = 1;
                        break;
                    case NONE:
                        presentBoardState(board);
                        shootArrow(current_player, board);
                        switch_player(&current_player,board);
                        break;
                }
        
                if (!isMovePossible(board ,current_player)) break;
        }   
}