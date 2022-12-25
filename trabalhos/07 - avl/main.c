#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>

char *readLine();

int main ()  {

  AVLTree * tree;
  Game * game;
  char * line;
  int year;
  int traverseType;

  tree = newTree();

  scanf("%d\n", &traverseType);

  year = -1;
  game = NULL;
  line =  readLine(); 

  while(strcmp(line, "F") != 0){

    year = atoi(line);
    game = searchGame(tree, year);

    while(game != NULL){
      removeGame(tree, game);
      game = searchGame(tree, year);
    }
    free(line); line = NULL;
    line = readLine();
  } 
  free(line); 
  traverse(tree, traverseType);
  // print_b_tree(tree);
  deleteTree(tree);
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

