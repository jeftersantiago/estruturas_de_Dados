/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/

#include "binaryTree.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char *readLine();

int main(){

    BTree *tree = createTree();

    int n;
    scanf("%d\n", &n);
    int i = 0;

    while(i < n) {

      char * c = readLine();
      Account *account = createAccount(c);
      insert(tree, account);

      free(c);
      c = NULL;
      i++;
    }

    char command;
    scanf("%c\n", &command);

    if(command == 'I'){

      char * line = readLine();

      Account * account = createAccount(line);

      free(line);
      line = NULL;

      insert(tree, account);
      traverse(tree, preorder_traversal);
    }
    else if (command == 'B') {

      char * cpf = readLine();

      Account * account = searchTree(tree, cpf);

      printAccount(account);

      free(cpf);
      cpf = NULL;
    }
    else if (command == 'R'){

      char * cpf = readLine();
      removeFromTree(tree, cpf);

      free(cpf);
      cpf = NULL;

      traverse(tree, preorder_traversal);
    }

    printf("\n"); /* So pra fazer o output correto no runcodes*/

    delete_tree(tree);
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
