#include "catalogo.h"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct GAMELIST{
	Game *gamelist[MAX];
	int size;
};

GameList *newList(){
	GameList *game_list = (GameList*)malloc(sizeof(GameList));
	game_list->size=0;
	return game_list;
} 

void putGame(GameList *game_list, Game *game){
	game_list->gamelist[game_list->size]=game;
	game_list->size++;
}

void findGamebyYear(GameList *game_list, int year){
	int find =0;
	for (int i=0;i<game_list->size;i++){
		if (getYear(game_list->gamelist[i])==year){
			printName(game_list->gamelist[i]);
			find=1;
		}
	}
	if (find == 0){
		printf("Nada encontrado\n");
	}
}

void findGamebyDeveloper(GameList *game_list, char *Developer){
	int find =0;
	for (int i=0;i<game_list->size;i++){
		if (strcmp(getDeveloper(game_list->gamelist[i]),Developer)==0){
			printName(game_list->gamelist[i]);
			find=1;
		}
	}
	if (find == 0){
		printf("Nada encontrado\n");
	}
}
