#ifndef _linkedList_
#define _linkedList_
#include "bankAccount.h"

typedef struct BIG_NUMBER CPF;

typedef boolean (*Comparision) (int a, int b);

CPF *newCPF(char *c);
CPF *getCPF(Account *account);
void deleteCPF(CPF *list);

/** Parametros:
    Account *parent : conta na raíz da árvore
    Account *new : novo registro
    Copmarision cmp : ponteiro de funcao para
    qual funcao de comparacao quero usar.
    
 **/
boolean compareCPF(CPF *cpf1, CPF * cpf2, Comparision cmp);
/* Retorna true se a > b  */
boolean equal (int a, int b);
/* Retorna true se a == b */
boolean greater(int a, int b);

/** Printa o CPF com a formatação original **/
void printCPF(CPF *cpf, int option);
boolean isEqual (const CPF * cpf1, const CPF * cpf2);
#endif
