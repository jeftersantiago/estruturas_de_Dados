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

    size_t length = strlen(name) + 5;
    game->name =  (char *) malloc(sizeof(char) *  (int) length);
    strcpy(game->name, name);

    game->year = year;

    length = strlen(dev) + 5;
    game->developer = (char *) malloc(sizeof(char) * (int) length);
    strcpy(game->developer, dev);
  }
  return game;
}

char *getName(Game * game){
  return game->name;
}
int getYear(Game * game) { return game->year; }

void printGame(Game * game){
  //  printf("%s, %d\n", game->name, game->year);
  printf("%s\n", game->name);
  // printf("%d\n", game->year);
}

void deleteGame(Game * game){
  if(game != NULL){
    free(game->name);
    free(game->developer);
    free(game);
  }
}

/*
  Retorna true se ano do game1 for maior que o de game2
  Se os anos forem iguais retorna de acordo com a comparacao da funcao
  strcmp(name1, name2) < 0;
  Se name1 > name2 => returna true
 */

boolean isGreater(Game * game1, Game * game2){
  if(game1->year != game2->year)
    return game1->year > game2->year;
  return strcmp(game1->name, game2->name) > 0;
}
