/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "jogo.h"
#include "catalogo.h"

char *readLine();

int main(){

	char name[30];
    char developer[30];
	int year;
	
	Catalogue *catalogo = newCatalogue();
    char *c; 

	do{
        c = readLine();
		strcpy(name, c);
        free(c);
        c = NULL;

		if(strcmp(name,"F")!=0){
            c = readLine();
			strcpy(developer, c);
            free(c);
            c = NULL;
			scanf("%d\n",&year);
			addGame(catalogo,newGame(name,developer,year));
		}
	} while(strcmp(name,"F")!=0);

	char option;

    for(; ;){

        scanf("%c\n",&option);
        
        if (option=='F'){
            break;
        }
        else if(option=='E'){
            c = readLine();
            strcpy(developer,c);
            findGamebyDeveloper(catalogo, developer);
        }
        else{
            scanf("%d\n",&year);
            findGamebyYear(catalogo, year);
        }
    }
    
    free(c);
    c = NULL;
    destroyCatalogue(catalogo);
	return 0;
}

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char) getchar();
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


