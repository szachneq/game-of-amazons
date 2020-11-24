/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */
#include <stdio.h>

#define BOARD_SIZE 10

int g_amazons = 5;
int g_board[BOARD_SIZE][BOARD_SIZE];
int g_currentPlayer = 1;
int g_scores[2] = { 0, 0 };

typedef enum {
    NONE,
    BROKEN_ARROW,
    SPEAR,
    HORSE
} EArtifact;

void generateBoard(int g_board[BOARD_SIZE][BOARD_SIZE]) {

    // printf("Generating game board...\n");
    // populate the board randomly
    // printf("Board generated!\n");
}

void placeAmazon(int player) {
    // int row,column;
    // printf("Enter the coordinates of the amazon:\n");

    // if(scanf("%d %d", &row,&column)){

    //     while(g_board[row][column] != 0){
    //         printf("Field is already taken!\n");
    //         printf("Enter the coordinates of the amazon:\n");
    //         scanf("%d %d", &row,&column);
    //     }
    //     g_board[row][column] = player;
    //     printf("Player %d placed amazon!\n", player);
    // }
    // get user input and alter the board state by
    // adding amazon to the board
}

void presentBoardState(int g_board[BOARD_SIZE][BOARD_SIZE]) {

    // present board state to the user
    for(int row = 0; row <= BOARD_SIZE; ++row){
        for(int column = 0; column <= BOARD_SIZE; ++column){

            if(row == 0  ){
                if(column == 0){
                    printf("| %d  ", column);
                }else{
                    printf("| %d ", column);
                 }
                
            }else if(column == 0 && row !=0){

                if(row < 10){
                 printf("| %d  ", row);
                 }else{
                     printf("| %d ", row);
                 }

            }

            if(row > 0 && column > 0){
                printf("| %d ", g_board[row][column]);
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

EArtifact moveAmazon(int player, int g_board[BOARD_SIZE][BOARD_SIZE]) {
    // get user input and alter board state
    // by moving the amazon of the specified player
    // this function returns artifact from the tile
    // that player moved amazon to
    // also adds score for the player using the scores array
    
    return NONE;
}

void shootArrow(int player, int g_board[BOARD_SIZE][BOARD_SIZE]) {
    // shoot arrow code
    printf("Player %d shoot his arrow!\n", player);
}

void throwSpear(int player, int g_board[BOARD_SIZE][BOARD_SIZE]) {
    printf("Player %d threw his spear!\n", player);
    // throw spear code
}

int isMovePossible(int g_board[BOARD_SIZE][BOARD_SIZE]) {
    // is it possible to perform any move
    return 0;
}

void switchPlayer(int *player) {
    if (*player == 1) *player = 2;
    if (*player == 2) *player = 1;
}

int main() {
    // Game main source code
    generateBoard(&g_board[0]);

    presentBoardState(g_board);

    printf("Input amount of the amazons: ");

    scanf("%d", &g_amazons);

    for (int i = 0; i < g_amazons; i++) {
        presentBoardState(g_board);
        placeAmazon(1);
        presentBoardState(g_board);
        placeAmazon(2);
    }
    while (1) {
        presentBoardState(g_board);
        EArtifact artifact = moveAmazon(g_currentPlayer, &g_board[0]);
        switch(artifact) {
            case BROKEN_ARROW:
                switchPlayer(&g_currentPlayer);
                break;
            case SPEAR:
                throwSpear(g_currentPlayer, &g_board[0]);
                switchPlayer(&g_currentPlayer);
                break;
            case HORSE:
                shootArrow(g_currentPlayer, &g_board[0]);
                break;
            case NONE:
                shootArrow(g_currentPlayer, &g_board[0]);
                switchPlayer(&g_currentPlayer);
                break;
        }
        if (!isMovePossible(&g_board[0])) break;
    }
    int winner = 0;
    if (g_scores[0] > g_scores[1]) winner = 1;
    if (g_scores[0] < g_scores[1]) winner = 2;

    if (winner) {
        printf("Player %d won! \n", winner);
    } else {
        printf("Draw \n");
    }
	return 0;
}
