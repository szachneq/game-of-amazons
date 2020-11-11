/*  Project  */
/* Signature */
/*  Goes     */
/* Here      */
#include <stdio.h>

#define BOARD_SIZE 10

int amazons = 5;
int board[BOARD_SIZE][BOARD_SIZE];
int current_player = 1;
int scores[2] = { 0, 0 };

typedef enum {
    NONE,
    BROKEN_ARROW,
    SPEAR,
    HORSE
} Artifact;

void generate_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    // populate the board randomly
}

void place_amazon(int player, int board[BOARD_SIZE][BOARD_SIZE]) {
    // get user input and alter the board state by
    // adding amazon to the board
}

void present_board_state(int board[BOARD_SIZE][BOARD_SIZE]) {
    // present board state to the user
}

Artifact move_amazon(int player, int board[BOARD_SIZE][BOARD_SIZE]) {
    // get user input and alter board state
    // by moving the amazon of the specified player
    // this function returns artifact from the tile
    // that player moved amazon to
    // also adds score for the player using the scores array
    return NONE;
}

void shoot_arrow(int player, int board[BOARD_SIZE][BOARD_SIZE]) {
    // shoot arrow code
}

void throw_spear(int player, int board[BOARD_SIZE][BOARD_SIZE]) {
    // throw spear code
}

int is_possible_move(int board[BOARD_SIZE][BOARD_SIZE]) {
    // is it possible to perform any move
    return 0;
}

void switch_player(int *player) {
    if (*player == 1) *player = 2;
    if (*player == 2) *player = 1;
}

int main() {
    // Game main source code
    generate_board(&board[0]);
    for (int i = 0; i < amazons; i++) {
        place_amazon(1, &board[0]);
        place_amazon(2, &board[0]);
    }
    while (1) {
        present_board_state(board);
        Artifact artifact = move_amazon(current_player, &board[0]);
        switch(artifact) {
            case BROKEN_ARROW:
                switch_player(&current_player);
                break;
            case SPEAR:
                throw_spear(current_player, &board[0]);
                switch_player(&current_player);
                break;
            case HORSE:
                shoot_arrow(current_player, &board[0]);
                break;
            case NONE:
                shoot_arrow(current_player, &board[0]);
                switch_player(&current_player);
                break;
        }
        if (!is_possible_move(&board[0])) break;
    }
    int winner = 0;
    if (scores[0] > scores[1]) winner = 1;
    if (scores[0] < scores[1]) winner = 2;

    if (winner) {
        printf("Player %d won! \n", winner);
    } else {
        printf("Draw \n");
    }
	return 0;
}
