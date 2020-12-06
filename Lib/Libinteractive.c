#include "Libinteractive.h"

void generateBoard(Field g_board[BOARD_SIZE][BOARD_SIZE]) 
{
    // printf("Generating game board...\n");
    // populate the board randomly
    // printf("Board generated!\n");
}
void presentBoardState(Field g_board[BOARD_SIZE][BOARD_SIZE]) {

    // present board state to the user
    // for(int row = 0; row <= BOARD_SIZE; ++row){
    //     for(int column = 0; column <= BOARD_SIZE; ++column){

    //         if(row == 0  ){
    //             if(column == 0){
    //                 printf("| %d  ", column);
    //             }else{
    //                 printf("| %d ", column);
    //              }
                
    //         }else if(column == 0 && row !=0){

    //             if(row < 10){
    //              printf("| %d  ", row);
    //              }else{
    //                  printf("| %d ", row);
    //              }

    //         }

    //         if(row > 0 && column > 0){
    //             printf("| %d ", g_board[row][column]);
    //         }
            
    //     }
    //     if(row == 0){ 
    //         printf("|\n");
    //     }
    //     else{
    //         printf(" |\n");
    //     }        
    // }
}
void switchPlayer(int *player) 
{
    if (*player == 1) *player = 2;
    if (*player == 2) *player = 1;
}
