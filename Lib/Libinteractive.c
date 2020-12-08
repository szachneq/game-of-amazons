#include "Libinteractive.h"
#include "Variables.h"

extern Field g_board[BOARD_SIZE][BOARD_SIZE];
extern int g_current_player;
extern int g_scores[2];

void generateBoard() {
    printf("Generating game board...\n");
    for(int column = 0; column < 10; column++){
        for(int row = 0; row < 10; row++){
            g_board[column][row].value = (rand() % (5)); // Assigning random value from 0 - 5 
            g_board[column][row].artifact = (rand() % (4)) ; // Assigning random value from 0 - 4
            g_board[column][row].playerID = 0; // Assigning 0 because all fields are unoccupied
        }
    }
    printf("Board generated!\n");
}

void presentBoardState() {
    //present board state to the user
    for(int row = 0; row <= BOARD_SIZE; row++){
        for(int column = 0; column <= BOARD_SIZE; column++){

            if(row == 0){
              
                if(column == 0){
                    printf("| %d ", column);
                }else{
                    printf("|   %d   ", column);
                 }
                
            }else if(column == 0 && row !=0){
                if(row == 10){
                    printf("| %d", row);
                }
                else if(row < 10){
                    
                 printf("| %d ", row);
                 }
                 else{
                     printf("| %d ", row);
                 }

            }
            

            if(row > 0 && column > 0){
               
                printf("| %d %d %d ", g_board[row-1][column-1].value, g_board[row-1][column-1].artifact, g_board[row-1][column-1].playerID);

            }
            
        }
        if(row == 0){ 
            printf("|\n");
        }
        else{
            printf(" |\n");
        }        
    }
}

void switchPlayer() {
    if (g_current_player == 1) g_current_player = 2;
    if (g_current_player == 2) g_current_player = 1;
}

int can_place_here(position p) {
    if (p.x < 1 || p.y < 1) return 0;
    if (p.x > BOARD_SIZE || p.y > BOARD_SIZE) return 0;
    if (g_board[p.x-1][p.y-1].playerID != 0) return 0;
    return 1;
    return 0;
}

void initPlacement() {
    int amazons = 0;
    generateBoard();

    presentBoardState();

    printf("Input amount of the amazons: ");

    scanf("%d", &amazons);
    for (int i = 0; i < amazons; i++) {
        presentBoardState();
        position p = { .x=0, .y=0 };
        while (1) {
            printf("Player %d, input coordinates for amazon (x, y): ", g_current_player);
            scanf("%d %d", &p.x, &p.y);
            if (can_place_here(p)) break;
        }
        placeAmazon(g_current_player, p);
        switchPlayer();
    }
}
