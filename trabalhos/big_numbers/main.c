/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "big_number.h"

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

    int N;
    char n1[30],n2[30],s[7];

    bigInt *a,*b;

    scanf("%d\n",&N);

    while(N--){
        strcpy(s,readLine());
        strcpy(n1,readLine());
        strcpy(n2,readLine());
        a=newBigInt();
        b=newBigInt();
        stringtoBigInt(a,n1);
        stringtoBigInt(b,n2);


        printf("Resultado :: ");

        if(strcmp(s,"soma")==0){
            printBigInt(SumBigInt(a,b));
        }
        if(strcmp(s,"maior")==0){
            if(greaterBigInt(a,b))
                printf("True\n");
            else
                printf("False\n");
        }
        if(strcmp(s,"menor")==0){
            if(greaterBigInt(b,a))
                printf("True\n");
            else
                printf("False\n");
        }
        if(strcmp(s,"igual")==0){
            if(equalBigInt(b,a))
                printf("True\n");
            else
                printf("False\n");
        }
    }



    return 0;
}
