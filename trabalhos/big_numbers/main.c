/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "big_number.h"

int main(){

    int N;
    char n1[30],n2[30],s[7];

    bigInt *a;
    bigInt *b;
    bigInt* c;

    scanf("%d\n",&N);

    while(N--){
        scanf("%s %s %s",s,n1,n2);

        a = createBigNumber(n1);
        b = createBigNumber(n2);

        printf("Resultado :: ");
        
        if(strcmp(s,"soma") == 0){
          c = SumBigInt(a,b);
          printBigInt(c);
          delete_list(c);
        }
        if(strcmp(s,"maior") == 0){
            if(greaterBigInt(a,b))
                printf("True\n");
            else
                printf("False\n");
        }
        if(strcmp(s,"menor") == 0){
            if(greaterBigInt(b,a))
                printf("True\n");
            else
                printf("False\n");
        }
        if(strcmp(s,"igual") == 0){
            if(equalBigInt(b,a))
                printf("True\n");
            else
                printf("False\n");
        }

        delete_list(a);
        delete_list(b);
    }
    return 0;
}
