#ifndef _bank_account
#define _bank_account

#include "Util.h"

typedef struct ACCOUNT Account;

// Account *createAccount(const char *name, const char *cpf, const int age, const float balance);
Account *createAccount(char *str);
void deleteAccount (Account * account);

void printAccount(const Account *account);

char *getName(Account *account);

#endif
