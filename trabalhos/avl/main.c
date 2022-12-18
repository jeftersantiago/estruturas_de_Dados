#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>

char *readLine();

int main ()  {


  AVLTree * tree = buildTree();

  /*
    int traverseType;
    scanf("%d", &traverseType);
    printf("Traverse option = %d\n", traverseType);
    char * c = readLine();
  */
  
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
