#ifndef _catalogo_
#define _catalogo_

#include "jogo.h"

#define MAX 100

typedef struct GAMELIST GameList;

GameList *newList();

void putGame(GameList *game_list, Game *game);

void findGamebyYear(GameList *game_list, int year);

void findGamebyDeveloper(GameList *game_list, char *Developer);

#endif