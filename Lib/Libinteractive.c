#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libinteractive.h"
#include "Variables.h"
#include "Libavailable.h"

void generateBoard(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
    printf("Generating game board...\n");

    // To define limits of the significant artifacts
    // it is first row == border
    for (int column = 0; column < INTERNAL_BOARD_SIZE; column++) {
        board[0][column].playerID = 9;
    }
    for(int row = 1; row <= BOARD_SIZE; row++){
        board[row][0].playerID = 9; // it is first column = border
        for(int column = 1; column <= BOARD_SIZE; column++) {
            board[column][row].value = (rand() % (5)); // Assigning random value from 0 - 5 
            board[column][row].artifact = (rand() % (4)) ; // Assigning random value from 0 - 4
            board[column][row].playerID = 0; // Assigning 0 because all fields are unoccupied
        }
        board[row][INTERNAL_BOARD_SIZE-1].playerID = 9; // it is last column = border
    }
    // it is last row = border
    for (int column = 0; column < INTERNAL_BOARD_SIZE; column++) {
        board[INTERNAL_BOARD_SIZE-1][column].playerID = 9;
    }

    printf("Board generated!\n");
}

void presentBoardState(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
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
                printf("| %d %d %d ", board[row][column].value, board[row][column].artifact, board[row][column].playerID);
            }
        }
        if(row == 0) { 
            printf("|\n");
        } else {
            printf(" |\n");
        }        
    }
}

void switch_player(int *current_player) {
    if (*current_player == 1)
    { 
        *current_player = 2;
        }
    else{ 
        *current_player = 1;
        }
}


void placeAmazon(int player, position p,  Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE]) {
  board[p.y][p.x].playerID = player;
}

void addScore(int value, int player){

    // addScore() summ player score

}


void init_placement(Field board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE] ) {
    
    int amazons = 0;
    int player_id = 1;
    generateBoard(board);

    presentBoardState(board);

    printf("Input amount of the amazons: ");

    scanf("%d", &amazons);
    for (int i = 0; i < amazons*2 ; i++) {
        presentBoardState(board);
        position p = { .x=0, .y=0 };
        while (1) {
            printf("Player %d, input coordinates for amazon (x, y): ", player_id);
            scanf("%d %d", &p.x, &p.y);
            if (can_place_here(p, board)) break;
        }
        placeAmazon(player_id, p, board);
        switch_player(&player_id);
    }
}
