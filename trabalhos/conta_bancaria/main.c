/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/

#include "binary_tree.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>


char *readLine();

int main(){

    BTree *tree = createTree();

    int n;
    char *c = NULL;
    scanf("%d\n", &n);
    int i = 0;
    while(i < n) { // !strcmp(c, "B") || !strcmp(c, "R")){

      c = readLine();
      printf("%s\n", c);
      c = strdup(c);

      Account *account = createAccount(c);
      insert(tree, account);

      free(c);
      c = NULL;
      i++;
    }

    print_b_tree(tree);

    // printf("Preorder\n");
    //    traverse(tree, preorder_traversal);

    //    print_b_tree(tree);
    
    char * key = "186.161.140-41";
    //    printf("\nREMOVENDO 18616114041\n\n");

    removeFromTree (tree, key);
    print_b_tree(tree);

    printf("\nPreorder\n");
    traverse(tree, preorder_traversal);


    //    printAccount(removed);
    //    free(c);
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
