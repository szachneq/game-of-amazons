#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libmovement.h"
#include "Libavailable.h"
#include "Libinteractive.h"

int g_isHorse;


EArtifact choose_amazon(Game *game)
{   
    while (!game->g_is_horse) 
    {
        do{
        printf("Player %d, input coordinates for amazon that you want to move (x, y): ", game->current_player);
        scanf("%d %d", &game->pAmazon.x, &game->pAmazon.y);
            if(game->board[game->pAmazon.y][game->pAmazon.x].playerID != game->current_player) 
            {
                printf("Hmmm, missclick?\n");
            }
        }while(game->board[game->pAmazon.y][game->pAmazon.x].playerID != game->current_player);

            if((game->board[game->pAmazon.y][game->pAmazon.x].playerID == game->current_player) && can_amazon_move(game)) 
            {
                return move_amazon(game);
            }
    }
    if(game->g_is_horse) 
    {       
        game->g_is_horse = 0;
        return move_amazon(game);
    }





}

EArtifact move_amazon(Game *game) {
 
    EArtifact currFieldArtifact;

    do
    {
        printf("Player %d, input coordinates for amazon to move (x, y): ", game->current_player);
        scanf("%d %d", &game->p.x, &game->p.y);
    } while(can_amazon_move_here(game) == 0);

                
    // 4. Clean the old spot
    game->board[game->pAmazon.y][game->pAmazon.x].playerID = 0;
    game->board[game->pAmazon.y][game->pAmazon.x].artifact = 0;
    game->board[game->pAmazon.y][game->pAmazon.x].value = 0;

    // 5. Move amazon to new position
    game->board[game->p.y][game->p.x].playerID = game->current_player;

    currFieldArtifact = (EArtifact) game->board[game->p.y][game->p.x].artifact;
    // 5.1 update amazon position

    game->pAmazon = game->p;


    // 6. add_score()
    add_score(game);

    // Clear new spot
    game->board[game->p.y][game->p.x].value = 0;
    game->board[game->p.y][game->p.x].artifact = 0;


    return currFieldArtifact;

}

void add_score(Game *game){
    game->g_scores[game->current_player - 1] += game->board[game->pAmazon.y][game->pAmazon.x].value;
}

void shootArrow(Game *game) {

    // shoot arrow code

        do{
	        printf("Player %d, enter coordinates to shoot an arrow (x, y):", game->current_player);
		    scanf("%d %d", &game->p.x, &game->p.y);

            if(can_amazon_move_here(game)){
            game->board[game->p.y][game->p.x].playerID = 9;        
            game->board[game->p.y][game->p.x].value = 0;        
            game->board[game->p.y][game->p.x].artifact = 0;  
            break;
            }
        }while(1);

        printf("Player %d shoot his arrow!\n", game->current_player);
}

void throw_spear(Game *game) {

        do{
	        printf("Player %d, enter coordinates to shoot an spear", game->current_player);
		    scanf("%d %d", &game->p.x, &game->p.y);

            if(can_amazon_throw_spear_here(game)){
            game->board[game->p.y][game->p.x].playerID = 9;        
            game->board[game->p.y][game->p.x].value = 0;        
            game->board[game->p.y][game->p.x].artifact = 0;  
            break;
            }
        }while(1);
        printf("Player %d threw his spear!\n", game->current_player);
}

void init_movement(Game *game) 
{

        game->current_player = 1;

        while (1) 
        {
                if (!is_move_possible(game)) break;

                present_board_state(game);
                EArtifact artifact = choose_amazon(game);

                switch(artifact)
                {
                    case BROKEN_ARROW:
                        switch_player(&game->current_player);
                        break;
                    case SPEAR:
                        present_board_state(game);
                        throw_spear(game);
                        switch_player(&game->current_player);
                        break; 
                    case HORSE:
                        present_board_state(game);
                        shootArrow(game);
                        g_isHorse = 1;
                        break;
                    case NONE:
                        present_board_state(game);
                        shootArrow(game);
                        switch_player(&game->current_player);
                        break;
                }
        
                if (!is_move_possible(game)) break;
                switch_player(&game->current_player);
                if (!is_move_possible(game)) break;
                switch_player(&game->current_player);
        }   
}