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

// Account *createAccount(const char *name, const char *cpf, const int age, const float balance);
Account *createAccount(char *str);
void deleteAccount (Account * account);


void printAccount(const Account *account);

CPF *newCPF(char *c);
CPF *getCPF(Account *account);
void deleteCPF(CPF *list);

typedef boolean (*Comparision) (int a, int b);

/** Parametros:
    Account *parent : conta na raíz da árvore
    Account *new : novo registro

 **/
boolean equal (int a, int b);
boolean greater(int a, int b);

boolean compareCPF(CPF *cpf1, CPF * cpf2, Comparision cmp);

/** Printa o CPF com a formatação original **/
void printCPF(CPF *c);

int getCPF_tests(CPF *c);

boolean isEqual (const CPF * cpf1, const CPF * cpf2);

char *getName(Account *account);

#endif
