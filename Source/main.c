/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 



int g_amazons = 5;
int g_currentPlayer = 1;
int g_scores[2] = { 0, 0 };


#include "../Lib/Libinteractive.h"
#include "../Lib/Libavaliable.h"
#include "../Lib/Libmovement.h"

int main() {
    srand(time(0)); 

    // Game main source code
    generateBoard(&g_board[0]);

    presentBoardState(g_board);

    printf("Input amount of the amazons: ");

    scanf("%d", &g_amazons);

    for (int i = 0; i < g_amazons; i++) {
        presentBoardState(g_board);
        //placeAmazon(1); add arguments to functions and position scanf
        presentBoardState(g_board);
        //placeAmazon(2); add arguments to functions and position scanf
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
