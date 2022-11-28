#include <string.h> // adicioanr stdbool
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "big_number.h"

#define N_DIG 4
#define MAX 10000 // 10^N_DIG

static boolean is_empty(const bigInt *list);
static void insert(bigInt *list, int number);
static int compareBigInt(bigInt *n1, bigInt *n2, Node *p1, Node *p2);
static int compareNode(Node *p1, Node *p2);
static void recursivePrint(bigInt *n, Node *p);

struct NODE {
    int number;
    Node *next;
};

struct BIG_INT {
    Node *begin;
    Node *end;
    int size;
    int signal;
};


static void delete_node(Node * node){
  Node *aux = NULL;
  if(node != NULL)  {
    aux = node->next;
    free(node);
    delete_node(aux);
  }
}

void delete_list(bigInt *list){
  Node * node = list->begin;
  delete_node(node);
  free(list);
}

bigInt *newBigInt() {

    bigInt *n = (bigInt *) malloc(sizeof(bigInt));

    if(n != NULL) {

        n->begin = NULL;
        n->end = NULL;
        n->size = 0;
        n->signal=1;

    }
    return n;
}

bigInt *createBigNumber(char *s){

  bigInt * n  = newBigInt();

  int N = strlen(s);
  int number=0;
  int digit;

  for (int i=N-1;i>=0;i--){

    if (s[i]=='-'){
      n->signal*=-1;
      if (number>0) insert(n,number);
      break;
    }
    digit=(int)s[i]-(int)'0'; // transforma char em int

    if (i==0 && number==0 && digit==0 && n->size>0)
      break;

    number += (digit * pow(10, (N-i-1) % (N_DIG)));
    
    if(((N-i-1)%(N_DIG)==N_DIG-1 || i==0)){
      insert(n,number);
      number=0;
    }
  }
  return n;
}

static void insert(bigInt *list, int number){

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


static boolean is_empty(const bigInt *list) {
    return (list->begin == NULL);
}

void printBigInt(bigInt *list){
    if(list != NULL){
        recursivePrint(list,list->begin);
    }
    printf("\n");
}

static void recursivePrint(bigInt *n, Node *p){
    if(p==n->end){
        if (n->signal==-1)
            printf("-");
        printf("%d",p->number);
    }
    else{
        recursivePrint(n,p->next);
        printf("%.4d",p->number);
    }
}

boolean greaterBigInt(bigInt *n1, bigInt *n2){

    if(n1 == NULL || n2 == NULL)
        return false;

    if(n1->signal!=n2->signal)
        return n1->signal>n2->signal;

    if(n1->size!=n2->size){
        if(n1->signal==1)
            return (n1->size > n2->size ? true:false);
        else
            return (n1->size > n2->size ? false:true);
    }

    if(compareBigInt(n1,n2,n1->begin,n2->begin)==1){
        if(n1->signal==1)
            return true;
        else
            return false;
    }
    return false;
}

boolean equalBigInt(bigInt *n1, bigInt *n2){

    if(is_empty(n1) && is_empty(n2))
        return false;
    if(n1->size!=n2->size || n1->signal!=n2->signal)
        return false;

    if(compareBigInt(n1,n2,n1->begin,n2->begin)==0)
        return true;

    return false;
}
/**
 * compara dois Big ints de tamanhos iguais, retorna 1, se n1>n2
 * -1 se n1<n2 e 0 se n1 == n2
**/
static int compareBigInt(bigInt *n1, bigInt *n2, Node *p1, Node *p2){
  if(p1==n1->end)
    return compareNode(p1,p2);

  else {
    int aux=compareBigInt(n1,n2,p1->next,p2->next);
      
    if (aux!=0)
      return aux;
    
    return compareNode(p1,p2);
    }
}

static int compareNode(Node *p1, Node *p2){
    if(p1->number>p2->number)
        return 1;
    if(p1->number<p2->number)
        return -1;
    else
        return 0;
}

bigInt *SumBigInt(bigInt *n1, bigInt *n2){
    bigInt *n3=newBigInt();
    int index=0;

    Node *current_n1 = n1->begin;
    Node *current_n2 = n2->begin;

    while(current_n1!=NULL || current_n2!=NULL || index!=0){
        insert(n3,index);

        if(current_n1!=NULL){
            n3->end->number+=current_n1->number;
            current_n1 = current_n1->next;
        }
        if(current_n2!=NULL){
            n3->end->number+=current_n2->number;
            current_n2 = current_n2->next;
        }
        index=n3->end->number/MAX;
        n3->end->number=n3->end->number%MAX;
    }
    return n3;
}
