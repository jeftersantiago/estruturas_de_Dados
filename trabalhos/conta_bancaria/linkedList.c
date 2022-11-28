#include "bankAccount.h"
#include <string.h>

typedef struct NODE Node;

static boolean is_empty(const CPF *list); 
static void insert(CPF *list, char * number);
static void recursivePrint (Node *node);

struct NODE {
  int number;
  boolean zeroAtBegin;
  Node *next;
};

struct BIG_NUMBER {
  Node *begin;
  Node *end;
  
  int size;
};


static CPF * createCPF () {
  CPF * cpf = (CPF *) malloc(sizeof(CPF));
  if(cpf != NULL) {
        cpf->begin = NULL;
        cpf->end = NULL;
        cpf->size = 0;
  }
  return cpf; 
}

CPF *newCPF(char *c) {

  CPF * cpf = createCPF();
  
  char * c1 = strsep(&c, ".");
  char * c2 = strsep(&c, ".");
  char * c3 = strsep(&c, "-");
  char * c4 = c;
  
  /* Divide os pedaços do cpf e insere lista ligada. */
  insert(cpf,c1);
  insert(cpf,c2);
  insert(cpf,c3);
  insert(cpf,c4);

  return cpf;
}

static void insert(CPF *cpf, char * number){
  if(cpf != NULL){
    
    Node *node = (Node *) malloc(sizeof(Node));

    if(node != NULL) {
      
      node->next = NULL;

      node->number = atoi(number);
      /* Lida com caso onde numero da lista começa com 0 */
      if(number[0] == '0')
        node->zeroAtBegin = true;
      else
        node->zeroAtBegin = false;
      

      if(is_empty(cpf)) cpf->begin = node;
      else cpf->end->next = node;

      cpf->end = node;
      cpf->size++;
    }
  }
}
boolean compareCPF(CPF *cpf1, CPF * cpf2, Comparision cmp){

  boolean ans = false;

  if(cpf1 != NULL && cpf2 != NULL){

    Node *current_n1 = cpf1->begin;
    Node *current_n2 = cpf2->begin;
    
    while(current_n1 != NULL && current_n2 != NULL){
      if(cmp(current_n1->number, current_n2->number))
        ans = true;

      if(cmp == greater) return ans;

      current_n1 = current_n1->next;
      current_n2 = current_n2->next;
    }
  }
  return ans;
}

boolean greater(int a, int b) { return a > b;  }
boolean equal (int a, int b)  { return a == b; }

static boolean is_empty(const CPF *list) {
  return (list->begin == NULL);
}

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

void printCPF(CPF *cpf, boolean formated){
  if(cpf != NULL){
    if(formated)
      printf("CPF :: %d.%d.%d-%02d\n",
             cpf->begin->number,
             cpf->begin->next->number,
             cpf->begin->next->next->number,
             cpf->begin->next->next->next->number
             );
    else {
      recursivePrint(cpf->begin);
      printf("\n");
    }
  }
}

static void recursivePrint (Node *node) {
  if(node != NULL) {
    if(node->zeroAtBegin)
      printf("0%d", node->number);
    else
      printf("%d", node->number);
    node = node->next;
    recursivePrint(node);
  }
}

int getCPF_tests(CPF *cpf){
  return cpf->begin->number;
}

