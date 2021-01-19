/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"

Field g_board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE];

int g_scores[2] = { 0, 0 };


#include "Libavailable.h"
#include "Libinteractive.h"
#include "Libmovement.h"

int main() {
    srand(time(0)); 

    init_placement(g_board);

    initMovement(g_board, g_scores);

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
