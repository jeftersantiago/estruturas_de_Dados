#include "big_number.h"
#include <string.h>

typedef struct NODE Node;

static boolean is_empty(const bigInt *list); 
static void insert(bigInt *list, int number);

struct NODE {
    int number;
    Node *next;
};

struct BIG_INT {
    Node *begin;
    Node *end;
    int size;
};

bigInt *newBigInt(char *c) {

    bigInt *list = (bigInt *) malloc(sizeof(bigInt));

    if(list != NULL) {

        list->begin = NULL;
        list->end = NULL;
        list->size = 0;

        /**
           Isso aqui é específico para o CPF.
           Para qualquer número precisa ser ajustado.
         **/

        char tmp1[3];
        char tmp2[4];
        char tmp3[4];

        int n1 = atoi(strncpy(tmp1, &c[0], sizeof(tmp1)));
        insert(list, n1);
        int n2 = atoi(strncpy(tmp2, &c[3], sizeof(tmp2)));
        insert(list, n2);
        int n3 = atoi(strncpy(tmp3, &c[7], sizeof(tmp3)));
        insert(list, n3);

    }
    return list;
}


static void insert(bigInt *list, int number){

    if(list != NULL){
        Node *node = (Node *) malloc(sizeof(Node));
        if(node != NULL) {
            node->number = number;
            node->next = NULL;
            if(is_empty(list))
            {
                list->begin = node;
            }
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
        Node *current = list->begin;
        while(current != NULL) {
            printf("%d\n", current->number);
            current = current->next;
        }
    }
}

/**
   Retorna true se o número da lista n1 é maior que o da lista n2
   Retorna false se não ou se os valores das listas for NULL.
 **/
boolean compareBigInt(bigInt *n1, bigInt *n2){
    if(n1 != NULL && n2 != NULL){
        Node *current_n1 = n1->begin;
        Node *current_n2 = n2->begin;

        while(current_n1 != NULL && current_n2 != NULL){
            if(current_n1->number > current_n2->number)
                return true;
            current_n1 = current_n1->next;
            current_n2 = current_n2->next;
        }
    }
    return false;
}























