#include "Libinteractive.h"

void generateBoard() 
{
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
