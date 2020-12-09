/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Lib/Variables.h"

Field g_board[INTERNAL_BOARD_SIZE][INTERNAL_BOARD_SIZE];
int current_player = 1;
int g_scores[2] = { 0, 0 };


#include "../Lib/Libavailable.h"
#include "../Lib/Libinteractive.h"
#include "../Lib/Libmovement.h"

int main() {
    srand(time(0)); 

    init_placement(g_board);

    initMovement(g_board);

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
