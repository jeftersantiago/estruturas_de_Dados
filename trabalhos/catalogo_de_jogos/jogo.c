#include "jogo.h"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct GAME{
	char name[30];
	char developer[30];
	int year;
};

Game *newGame(const char *name, const char *developer, const int year){

	Game *game = (Game *) malloc(sizeof(Game));
	strcpy(game->name,name);
	strcpy(game->developer,developer);
	game->year=year;
	return game;

}

char *getDeveloper(Game *game){
	return game->developer;
}

int getYear(Game *game){
	return game->year;
}

void printName(Game *game){
	printf("%s\n", game->name);
}
