#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "jogo.h"
#include "catalogo.h"

#define MAX_GAMES 20;

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}

int main(){

	char name[30],developer[30];
	int year;
	
	GameList *catalogo;
	catalogo=newList();

	do{
		strcpy(name,readLine());

		if(strcmp(name,"F")!=0){
			strcpy(developer,readLine());
			scanf("%d\n",&year);
			putGame(catalogo,newGame(name,developer,year));

		}
	}while(strcmp(name,"F")!=0);

	char option;

	while(1==1){

		scanf("%c\n",&option);

		if (option=='F'){
			break;
		}
		else if(option=='E'){
			strcpy(developer,readLine());
			findGamebyDeveloper(catalogo, developer);
		}
		else{
			scanf("%d\n",&year);
			findGamebyYear(catalogo, year);
		}
	}
	
	return 0;
}