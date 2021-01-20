#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libinteractive.h"
#include "Variables.h"
#include "Libavailable.h"
#include "Libmovement.h"



/**
 * @brief Function which generates the board and randomly sets artifacts and treasures.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * 
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * 
 * @warning Randomly choosen values and artifacts have adjusted suitable frequency.
 */
void generate_board(Game *game) {
    printf("Generating game board...\n");

    // To define limits of the significant artifacts
    // it is first row == border
    int arrArtifact[10] = {0,0,0,0,0,1,2,2,3,3};
    
    int arrValue[17] = {5,4,4,3,3,2,2,2,1,1,1,1,0,0,0,0,0};

   
    for (int column = 0; column < INTERNAL_BOARD_SIZE; column++) {
        game->board[0][column].playerID = 9;
    }
    for(int row = 1; row <= BOARD_SIZE; row++){
        game->board[row][0].playerID = 9; // it is first column = border
        for(int column = 1; column <= BOARD_SIZE; column++) {

            game->board[column][row].value = arrValue[rand()%17]; // Assigning random value from 0 - 5 
            game->board[column][row].artifact = arrArtifact[rand() % 10]; // Assigning random value from 0 - 4
            game->board[column][row].playerID = 0; // Assigning 0 because all fields are unoccupied
        }
        game->board[row][INTERNAL_BOARD_SIZE-1].playerID = 9; // it is last column = border
    }
    // it is last row = border
    for (int column = 0; column < INTERNAL_BOARD_SIZE; column++) {
        game->board[INTERNAL_BOARD_SIZE-1][column].playerID = 9;
    }

    printf("Board generated!\n");
}
/**
 * @brief Function prints generated board.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, g_scores.
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * @note int g_scores displays held in the structure amount of points collected by the current player.
 */
void present_board_state(Game *game) {
    // print the state of the board in console
    for(int row = 0; row <= BOARD_SIZE; row++) {
        for(int column = 0; column <= BOARD_SIZE; column++) {
            if(row == 0) {
                if(column == 0) { printf("| %d ", column); }
                else { printf("|   %d   ", column); }
            } else if(column == 0 && row !=0) {
                if(row == 10) {
                    printf("| %d", row);
                } else if(row < 10) {
                    printf("| %d ", row);
                } else {
                    printf("| %d ", row);
                }
            }
            if (row > 0 && column > 0) {
                printf("| %d %d %d ", game->board[row][column].value, game->board[row][column].artifact, game->board[row][column].playerID);
            }
        }
        if(row == 0) { 
            printf("|\n");
        } else {
            printf(" |\n");
        }        
    }
    printf("Score: Player1 - %d, Player2 - %d\n", game->g_scores[0], game->g_scores[1]);
}
/**
 * @brief Function switches between players.
 * 
 * @param current_player we use a pointer to get to the value.
 * @note Function switch_player is always called by a different function which takes the game structure.
 */
void switch_player(int *current_player) 
{
    if (*current_player == 1)
    { 
        *current_player = 2;
    }
    else{ 
        *current_player = 1;
    }
}


/**
 * @brief Function places an amazon.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * @param player current player's ID which is switched by switch_player function.
 * 
 */
void place_amazon(Game *game, int player) {
  game->board[game->p.y][game->p.x].playerID = player;
  game->board[game->p.y][game->p.x].value = 0;
  game->board[game->p.y][game->p.x].artifact = 0;
}

/**
 * @brief One of the leading functions, it asks the user about amount of amazons and coordinates on which the player places the amazons.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board, p.
 * 
 * @note Field board included in game structure holds player's ID, value of a treasure and type of artifact.
 * @note Position p included in game structure holds amazons coordinates.
 * 
 */
void init_placement(Game *game) {
    
    int amazons = 0;
    int player_id = 1;
    generate_board(game);

    present_board_state(game);

    printf("Input amount of the amazons: ");

   while(scanf("%d", &amazons)==0){
       printf("\nNon-numeric input detected. Input a number.\n");
       scanf(" %*s ");
       printf("Input amount of the amazons: ");
     }
   
    for (int i = 0; i < amazons*2 ; i++) {
        
        position p = { .x=0, .y=0 };
        while (1) {
            present_board_state(game);
            printf("Player %d, input coordinates for amazon.\n", player_id);
            printf("Cordinate X: ");

            while(scanf("%d", &game->p.x)==0){
                printf("\nNon-numeric input detected. Input a number.\n");
                scanf(" %*s ");
                printf("Coordinate X: ");
            }
            printf("Coordinate Y: ");
            while(scanf("%d", &game->p.y)==0){
                printf("\nNon-numeric input detected. Input a number.\n");
                scanf(" %*s ");
                printf("Coordinate Y: ");
            }
            if (can_place_here(game)) break;
        }
        place_amazon(game, player_id);
        
        switch_player(&player_id);
    }
}
