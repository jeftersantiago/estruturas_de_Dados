/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/
#include "binaryTree.h"

char *readLine();

int main(){

    BTree *tree = createTree();

    int n;
    scanf("%d\n", &n);
    int i = 0;

    while(i < n) {
      Account *account = createAccount(readLine());
      insertTree(tree, account);
      i++;
    }

    char command;
    scanf("%c\n", &command);

    if(command == 'I'){
      Account * account = createAccount(readLine());
      insertTree(tree, account);
      preorderTraversal(tree);
    }
    else if (command == 'B') {
      Account * account = searchTree(tree, readLine());
      printAccount(account);
      //      deleteAccount(account);
    }
    else if (command == 'R'){
      removeFromTree(tree, readLine());
      preorderTraversal(tree);
    }
    printf("\n"); /* So pra fazer o output correto no runcodes*/
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
