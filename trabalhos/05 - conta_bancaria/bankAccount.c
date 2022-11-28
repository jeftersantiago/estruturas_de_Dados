#include "bankAccount.h"

struct ACCOUNT {
    char *name;
    CPF *cpf;
    int age;
    float balance;
};

Account *createAccount(char *str) {

    Account *account = (Account *) malloc(sizeof(Account));
    
    if(account != NULL){

      char * cpf = strsep(&str, ";");
      char * name = strsep(&str, ";");
      int age = atoi(strsep(&str, ";"));
      float balance = atof(str);
        
      size_t length = strlen(name);
      account->name = (char *) malloc(sizeof(char *) * (int) length);

      strcpy(account->name, name);

      account->cpf = newCPF(cpf); 
      account->age = age;
      account->balance = balance;
        
    }
    return account;
}

void deleteAccount (Account * account) {
    deleteCPF(account->cpf);
    free(account->name);
    free(account);
}

CPF *getCPF(Account *account) {
    return account->cpf;
}

char *getName(Account *account){
  return account->name;
}

void printAccount(const Account *account){
  printf("Conta :: %s\n", account->name);
  printCPF(account->cpf, true);
  printf("Idade :: %d\n", account->age);
  printf("Saldo atual :: R$ %.2f\n", account->balance);
}
