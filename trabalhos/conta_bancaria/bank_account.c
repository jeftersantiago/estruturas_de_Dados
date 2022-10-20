#include "bank_account.h"

static char *formatCPF();

struct ACCOUNT {
    char name[100];
    char cpf[14];
    int age;
    float balance;
};

Account *createAccount(const char *name, const char *cpf, const int age, const float balance) {
    Account *account = (Account *) malloc(sizeof(Account));

    if(account != NULL){

        strcpy(account->name, name);
        strcpy(account->cpf, formatCPF(cpf));

        account->age = age;
        account->balance = balance;
        
    }
    return account;
}

char * getCPF(Account *account){
    return account->cpf; 
}

void printAccount(const Account *account){
    printf("Conta :: %s\n", account->name);
    printf("CPF :: %s\n", account->cpf);
    printf("Idade :: %d\n", account->age);
    printf("Saldo atual :: %f\n", account->balance);
}

static char *formatCPF (const char *c) {
    int n = 14;
// 11 dígitos 
    char *formated = (char *) malloc(sizeof(char) * 11);

    int j = 0;
    int i = 0;

    while(i < n){
        if((c[i] != '.') && (c[i] != '-')){
            formated[j] = c[i];
            j++;
        }
        i++;
    }
    return formated;
}
