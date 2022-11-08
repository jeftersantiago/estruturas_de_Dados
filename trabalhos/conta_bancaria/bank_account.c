#include "bank_account.h"
static CPF *formatCPF (const char *c);

struct ACCOUNT {
    char name[100];
    CPF *cpf;
    int age;
    float balance;
};

Account *createAccount(const char *name, const char *cpf, const int age, const float balance) {

    Account *account = (Account *) malloc(sizeof(Account));

    if(account != NULL){
        
        strcpy(account->name, name);
        account->cpf = formatCPF(cpf);
        account->age = age;
        account->balance = balance;
        
    }
    return account;
}

CPF *getCPF(Account *account) {
    return account->cpf;
}

char *getName(Account *account){
  return account->name;
}

void printAccount(const Account *account){
    printf("Conta :: %s\n", account->name);
    //    printCPF(account->cpf);
//  printf("Idade :: %d\n", account->age);
//  printf("Saldo atual :: R$ %.2f\n", account->balance);
}

/**
   Remove os caracteres especiais da string do CPF
   e retorna pointer do tipo CPF.
 **/
static CPF *formatCPF (const char *c) {
    int n = 14;
// 11 dígitos 
    char *formated = (char *) malloc(sizeof(char) * n);

    int j = 0;
    int i = 0;

    while(i < n){
        if((c[i] != '.') && (c[i] != '-')){
            formated[j] = c[i];
            j++;
        }
        i++;
    }
    return newCPF(formated);
}
