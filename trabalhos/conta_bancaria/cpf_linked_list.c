#include "bank_account.h"
#include <string.h>

static boolean is_empty(const CPF *list); 
static void insert(CPF *list, int number);


typedef struct NODE Node;

struct NODE {
  int number;
  Node *next;
};

struct BIG_NUMBER {
  Node *begin;
  Node *end;
  
  int size;
};

static void delete_node(Node * node){
  Node *aux = NULL;

  if(node != NULL)  {
    aux = node->next;
    free(node);
    delete_node(aux);
  }
}

void deleteCPF(CPF *list){
  Node * node = list->begin;
  delete_node(node);
  free(list);
}


CPF *newCPF(char *c) {

    CPF *cpf = (CPF *) malloc(sizeof(CPF));

    if(cpf != NULL) {

        cpf->begin = NULL;
        cpf->end = NULL;
        cpf->size = 0;

        c = strdup(c);

        /* Divide os pedaços do cpf e insere lista ligada. */
        insert(cpf, atoi(strsep(&c, ".")));
        insert(cpf, atoi(strsep(&c, ".")));
        insert(cpf, atoi(strsep(&c, "-")));
        insert(cpf, atoi(c));

    }
    return cpf;
}

static void insert(CPF *list, int number){

  if(list != NULL){

    Node *node = (Node *) malloc(sizeof(Node));

    if(node != NULL) {
      node->number = number;
      node->next = NULL;

      if(is_empty(list))
        list->begin = node;
      else
        list->end->next = node;

      list->end = node;
      list->size++;
    }
  }
}

static boolean is_empty(const CPF *list) {
    return (list->begin == NULL);
}

boolean compareCPF(CPF *cpf1, CPF * cpf2, Comparision cmp){

  boolean ans = false;
  if(cpf1 != NULL && cpf2 != NULL){

    Node *current_n1 = cpf1->begin;
    Node *current_n2 = cpf2->begin;
    
    while(current_n1 != NULL && current_n2 != NULL){
      if(cmp(current_n1->number, current_n2->number))
        ans = true;

      if(cmp == greater)  return ans;

      current_n1 = current_n1->next;
      current_n2 = current_n2->next;
    }
  }
  return ans;
}

boolean greater(int a, int b) {
  return a > b;
}
boolean equal (int a, int b) {
  return a == b;
}

void printCPF(CPF *cpf, boolean formated){
  if(cpf != NULL){
    if(formated)
      printf("CPF :: %d.%d.%d-%02d\n",
             cpf->begin->number,
             cpf->begin->next->number,
             cpf->begin->next->next->number,
             cpf->begin->next->next->next->number
             );
    else 
      printf("%d%d%d%02d\n",
             cpf->begin->number,
             cpf->begin->next->number,
             cpf->begin->next->next->number,
             cpf->begin->next->next->next->number
             );
  }
}

int getCPF_tests(CPF *cpf){
  return cpf->begin->number;
}

