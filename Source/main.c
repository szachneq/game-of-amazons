/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "../Lib/Variables.h"

Field g_board[BOARD_SIZE][BOARD_SIZE];
int current_player = 1;
int g_scores[2] = { 0, 0 };


#include "../Lib/Libinteractive.h"
#include "../Lib/Libavaliable.h"
#include "../Lib/Libmovement.h"

int main() {
    srand(time(0)); 
    init_placement();
    while (1) {
        presentBoardState();
        EArtifact artifact = moveAmazon(current_player, &g_board[0]);
        switch(artifact) {
            case BROKEN_ARROW:
                switch_player(&current_player);
                break;
            case SPEAR:
                throwSpear(current_player, &g_board[0]);
                switch_player(&current_player);
                break;
            case HORSE:
                shootArrow(current_player, &g_board[0]);
                break;
            case NONE:
                shootArrow(current_player, &g_board[0]);
                switch_player(&current_player);
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
