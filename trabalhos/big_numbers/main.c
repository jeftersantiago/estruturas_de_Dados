/**
   Jefter Santiago, nºUSP: 12559016
   João Lucas Vasconselos, nºUSP: 12557870
 **/
#include "big_number.h"

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

