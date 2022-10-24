#include "catalogo.h"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct CATALOGUE{
	Game **list;
	int size;
};

Catalogue *newCatalogue(){
	Catalogue *catalogue = (Catalogue*) malloc(sizeof(Catalogue));
    catalogue->list = NULL; // (Game **) malloc(sizeof(Game *));
	catalogue->size = 0;
	return catalogue;
} 

void addGame(Catalogue *catalogue, Game *game){
    int index = catalogue->size;
	catalogue->size++;
    catalogue->list = (Game **) realloc(catalogue->list, sizeof(Game *) * catalogue->size);
    catalogue->list[index] = game;
}

void findGamebyYear(Catalogue *catalogue, int year){
	int find = 0;
	for (int i = 0; i < catalogue->size; i++){
		if (getYear(catalogue->list[i])==year){
			printName(catalogue->list[i]);
			find=1;
		}
	}
	if (find == 0){
		printf("Nada encontrado\n");
	}
}

void findGamebyDeveloper(Catalogue *catalogue, char *Developer){
	int find =0;
	for (int i=0; i < catalogue->size; i++){
		if (strcmp(getDeveloper(catalogue->list[i]), Developer)==0){
			printName(catalogue->list[i]);
			find=1;
		}
	}
	if (find == 0){
		printf("Nada encontrado\n");
	}
}

void destroyCatalogue(Catalogue *catalogue){
    for(int i = 0; i < catalogue->size; i++){
        free(catalogue->list[i]);
    }
    free(catalogue->list);
    free(catalogue);
    catalogue = NULL;
}
