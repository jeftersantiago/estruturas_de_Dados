#ifndef _big_number
#define _big_number

#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0
#define boolean int

typedef struct BIG_INT bigInt;

boolean compareBigInt(bigInt *n1, bigInt *n2);

void printBigInt(bigInt *b);

bigInt *newBigInt(char *c);

#endif
