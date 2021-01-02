#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libmovement.h"
#include "Libavailable.h"
#include "Libinteractive.h"

int g_isHorse;


EArtifact chooseAmazon(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE])
{   
  
    position pAamazon;
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

            if((board[pAamazon.y][pAamazon.x].playerID = player) && canAmazonMove(pAamazon, board)) 
            {
                
             return moveAmazon(player, pAamazon, board);

            }
    }
    
    if((board[pAamazon.y][pAamazon.x].playerID = player) && canAmazonMove(pAamazon, board)) 
    {            
        return moveAmazon(player, pAamazon, board);

    }

}

EArtifact moveAmazon(int player, position pAamazon, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
 
    EArtifact currFieldArtifact;

    // 1. Ask which amazone to make move with
        position correctAmazon = pAamazon;
        position p = {.x= 0, .y=0};
        
               do
                {
                    printf("Player %d, input coordinates for amazon to move (x, y): ", player);
                    scanf("%d %d", &p.x, &p.y);
                } while(canAmazonMoveHere(p, correctAmazon, board, player) == 0);

                
    // 4. Clean the old spot 
    board[correctAmazon.y][correctAmazon.x].playerID = 0;
    board[correctAmazon.y][correctAmazon.x].artifact = 0;
    board[correctAmazon.y][correctAmazon.x].value = 0;

     // 5. Move amazon to new position
    board[p.y][p.x].playerID = player;

    // 6. addScore()
    addScore(board[p.y][p.x].value, player);

    // 7. Return artifact form new spot
    currFieldArtifact = (EArtifact) board[p.y][p.x].artifact;

    presentBoardState(board);
    
    if(currFieldArtifact != HORSE){
        g_isHorse = 0;
    }

    return currFieldArtifact;

}

void shootArrow(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {

    // shoot arrow code
        int a,b;
	    printf("Player %d, enter coordinates to shoot an arrow (x, y):", player);
    
		scanf(" %d %d", &a, &b);
        if( isThrowArrow(board[b][a].playerID))
        {
            board[b][a].playerID = 9;        
        }
        printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {

     int a,b;
	    printf("Player %d :enter coordinates to shoot an spear\n", player);
    
		scanf(" %d %d", &a, &b);
        if(isThrowSpear(board[b][a].playerID))
        {
            board[b][a].playerID = 9;        
        }
        printf("Player %d threw his spear!\n", player);
}

void initMovement(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) 
{

        int current_player = 1;

        while (1) 
        {
             
                EArtifact artifact = chooseAmazon(current_player, board);

                switch(artifact)
                {
                    case BROKEN_ARROW:
                        switch_player(&current_player,board);
                        break;
                    case SPEAR:
                        switch_player(&current_player,board);
                        throwSpear(current_player, board);
                        break; 
                    case HORSE:
                        shootArrow(current_player, board);
                        g_isHorse = 1;
                        break;
                    case NONE:
                        shootArrow(current_player, board);
                        switch_player(&current_player,board);
                        break;
                }
        
                if (!isMovePossible(board ,current_player)) break;
        }   
}