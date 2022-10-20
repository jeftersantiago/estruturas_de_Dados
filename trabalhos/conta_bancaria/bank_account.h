#ifndef _bank_account
#define _bank_account

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ACCOUNT Account;

Account *createAccount(const char *name, const char *cpf, const int age, const float balance);

char *getCPF(Account *account);


void printAccount(const Account *account);

#endif
