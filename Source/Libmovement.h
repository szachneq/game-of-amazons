#ifndef LIBMOVEMENT_H_INCLUDED
#define LIBMOVEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Variables.h"
#include "Libavailable.h"
#include "Libinteractive.h"

EArtifact choose_amazon(Game *game);
EArtifact move_amazon(Game *game);
void throw_spear(Game *game);
void init_movement(Game *game);

#endif