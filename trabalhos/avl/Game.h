#ifndef _game_
#define _game_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0
#define boolean int


typedef struct GAME Game;

Game * newGame();

char * getName(Game * game);

void deleteGame(Game * game);
void printGame(Game * game);

boolean compare(Game * game1, Game * game2);
#endif
