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

    b_tree *tree = createTree();

    int n;
    char *c = readLine(); //  scanf("%d", &n);
    n = atoi(c);
    int i = 0;
    while(i < n) { // !strcmp(c, "B") || !strcmp(c, "R")){

        c = readLine();
        c = strdup(c);

        char *cpf = strsep(&c, ";");
        char *name = strsep(&c, ";");
        int age = atoi(strsep(&c, ";"));
        float balance = atof(c);
        Account *account = createAccount(name, cpf, age, balance);

        insert(tree, account);

        i++;
    }
//    free(c);
    printf("Traverse\n");
    //    traverse(tree, preorder_traversal);

    print_b_tree(tree);
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
