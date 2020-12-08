/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "../Lib/Variables.h"

Field g_board[BOARD_SIZE][BOARD_SIZE];
int g_current_player = 1;
int g_scores[2] = { 0, 0 };


#include "../Lib/Libinteractive.h"
#include "../Lib/Libavaliable.h"
#include "../Lib/Libmovement.h"

int main() {
    srand(time(0)); 
    initPlacement();
    while (1) {
        presentBoardState();
        EArtifact artifact = moveAmazon(g_current_player, &g_board[0]);
        switch(artifact) {
            case BROKEN_ARROW:
                switchPlayer(&g_current_player);
                break;
            case SPEAR:
                throwSpear(g_current_player, &g_board[0]);
                switchPlayer(&g_current_player);
                break;
            case HORSE:
                shootArrow(g_current_player, &g_board[0]);
                break;
            case NONE:
                shootArrow(g_current_player, &g_board[0]);
                switchPlayer(&g_current_player);
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
