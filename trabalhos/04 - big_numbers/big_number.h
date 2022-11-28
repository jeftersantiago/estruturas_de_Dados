#ifndef _big_number
#define _big_number

#define true 1
#define false 0
#define boolean int

typedef struct BIG_INT bigInt;
typedef struct NODE Node;

bigInt *newBigInt();

bigInt * createBigNumber(char *s);

bigInt *SumBigInt(bigInt *n1, bigInt *n2);

void printBigInt(bigInt *list);

boolean greaterBigInt(bigInt *n1, bigInt *n2);

boolean equalBigInt(bigInt *n1, bigInt *n2);

void delete_list(bigInt *list);

#endif
