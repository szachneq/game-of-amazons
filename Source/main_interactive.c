/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"

Game game;

#include "Libavailable.h"
#include "Libinteractive.h"
#include "Libmovement.h"

int main() {
    srand(time(0)); 

    init_placement(&game);

    init_movement(&game);

    int winner = 0;
    if (game.g_scores[0] > game.g_scores[1]) winner = 1;
    if (game.g_scores[0] < game.g_scores[1]) winner = 2;

    if (winner) {
        printf("Player %d won! \n", winner);
    } else {
        printf("Draw \n");
    }
	return 0;
}
