/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/
// #include "bank_account.h"
// #include "binary_tree.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#include "big_number.h"
#include "bank_account.h"

char *readLine();


int main(){

    char *c = (char *) malloc (sizeof(char) * 11);
    char *b = (char *) malloc (sizeof(char) * 11);
    
    c = "11846956102";
    b = "49822893876";

    printf("N\n");
    bigInt *n = newBigInt(c);
    printBigInt(n);

    printf("M\n");
    bigInt *m = newBigInt(b);
    printBigInt(m);

    if(compareBigInt(n, m)){
        printf("b > c\n");
    }

    return 0;
}

/** 
int main_test(){

    b_tree *tree = createTree();
    char *c = readLine();

    while(! strcmp(c, "B") || !strcmp(c, "R")){

        c = strdup(c);

        char *cpf = strsep(&c, ",");

        char *name = strsep(&c, ",");
        int age = (int) *(strsep(&c, ","));
        float balance = (float) *c;
        
        Account *account = createAccount(name, cpf, age, balance);


           if(getCPF(account) > getCPF(tree->parent->account))
           insert(tree, account, RIGHT);
           else
           insert(tree, account, LEFT);
        **/
        
    /**
        free(c);
        c = NULL;
        c = readLine();
    }
       if(strcmp(c, "B")){
       scanf("%s", &c);
       search(tree, c);
       }
    return 0;
}
**/

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


