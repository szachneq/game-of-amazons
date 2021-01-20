#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"
#include "Libavailable.h"
#include "Libinteractive.h"

/**
 * @brief Function takes amazon place coordinates from user and passes it to move_amazon or af player stood on horse automatically goes threw.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * @return EArtifact - which indicates the artifact found on the current field.
 */

EArtifact choose_amazon(Game *game);

/**
 * @brief Funkcja przyjmuje współrzędne, w których amazon powinien umieścić, czyści nowe i stare miejsce.
 * 
 * @param game structure which contains all variables used in the current game state, this function uses variables holding: board.
 * @return EArtifact - which indicates the artifact found on the current field.
 */

EArtifact move_amazon(Game *game);
void throw_spear(Game *game);
void init_movement(Game *game);

#endif