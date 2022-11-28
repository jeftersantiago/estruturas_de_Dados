#ifndef _jogo_
#define _jogo_

typedef struct GAME Game;

Game *newGame(const char *name, const char *Developer, const int year);
void printName(Game *game);
char* getDeveloper(Game *game);
int getYear(Game *game);

Game getGame();



#endif
