#ifndef _bank_account
#define _bank_account

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define boolean int

typedef struct ACCOUNT Account;

typedef struct BIG_NUMBER CPF;

Account *createAccount(const char *name, const char *cpf, const int age, const float balance);

void printAccount(const Account *account);

CPF *newCPF(char *c);
CPF *getCPF(Account *account);

/** Parametros:
    Account *parent : conta na raíz da árvore
    Account *new : novo registro
    Retorna:
    True se o valor numérico do CPF da raíz for maior
    que o do novo registro.
 **/
boolean compareCPF(Account *parent, Account *new);

/** Printa o CPF com a formatação original **/
void printCPF(CPF *c);

#endif
