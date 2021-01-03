#ifndef BOARD_ENTITIES_H
#define BOARD_ENTITIES_H

typedef enum {
  NONE = 0,
  HORSE = 1,
  BROKEN_ARROW = 2,
  SPEAR = 3,
} EArtifact;

typedef struct {
  int value;
  EArtifact artifact;  
  int player_id;
} Field;

typedef struct {
  int x;
  int y;
} Position;

#endif // BOARD_ENTITIES_H