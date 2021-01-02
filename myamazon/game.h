#ifndef GAME_H
#define GAME_H

#include "board.h"

#define MAX_PLAYERS 8

typedef struct {
  char *name;
  int id;
  int points;
} Player;

typedef enum {
  PLACEMENT,
  MOVEMENT,
} EPhase;

typedef struct {
  Board board;
  EPhase phase;
  Player players[MAX_PLAYERS];
  int amazons;
} Game;

#endif // GAME_H