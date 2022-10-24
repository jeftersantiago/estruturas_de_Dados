/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/

#include "bank_account.h"
//#include "binary_tree.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


char *readLine();

int main(){

//    b_tree *tree = createTree();

    char *c = readLine();

    int i = 1;
    while(i > 0) {// !strcmp(c, "B") || !strcmp(c, "R")){

        c = strdup(c);

        char *cpf = strsep(&c, ",");
        char *name = strsep(&c, ",");
        int age = atoi(strsep(&c, ","));
        float balance = atof(c);
        Account *account = createAccount(name, cpf, age, balance);
        printAccount(account);

        i--;

//        insert_tree(tree, account);

//        free(c);
//        c = NULL;
//        c = readLine();
    }
   /**
      if(strcmp(c, "B")){
      scanf("%s", &c);
      search(tree, c);
      }
   **/
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

















