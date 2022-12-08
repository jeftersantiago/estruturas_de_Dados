#include "Game.h"

struct GAME {
  char * name;
  int year;
  char * developer; 
};

Game * newGame (char * line) {

  Game * game = (Game *) malloc(sizeof(Game));

  if(game != NULL) {

    char * name = strsep(&line, ";");
    int year =  atoi(strsep(&line, ";"));
    char * dev = strsep(&line, ";");

    game->name = (char *) malloc(sizeof(char) * strlen(name));
    strcpy(game->name, name);

    game->developer = (char *) malloc(sizeof(char) * strlen(dev));
    strcpy(game->developer, dev);

    game->year = year;
    
  }
  return game;
}



char *getName(Game * game){
  return game->name;
}
void printGame(Game * game){
  printf("%s %d %s", game->name, game->year, game->developer);
}

void deleteGame(Game * game){
  free(game->name);
  free(game->developer);
  free(game);
}

/* Retorna true se ano do Game1 for maior que o de Game2
   Se forem iguais retorna de acordo com a comparacao da funcao
   strcmp(name1, name2) < 0;
   Se name1 > name2 => returna true
 */
boolean compare(Game * game1, Game * game2) {
  if(game1->year > game2->year)
    return true;
  if(game1->year == game2->year)
    return strcmp(game1->name, game2->name) < 0; 
  return false;
}














