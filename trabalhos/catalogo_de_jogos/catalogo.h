#ifndef _catalogo_
#define _catalogo_

#include "jogo.h"

// #define MAX 100

typedef struct CATALOGUE Catalogue;

Catalogue *newCatalogue();

void addGame(Catalogue *game_list, Game *game);

void findGamebyYear(Catalogue *game_list, int year);

void findGamebyDeveloper(Catalogue *game_list, char *Developer);
void destroyCatalogue(Catalogue *catalogue);

int getSize(Catalogue *catalogue);
#endif
