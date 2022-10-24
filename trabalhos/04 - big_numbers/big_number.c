#include "big_number.h"
#include <string.h>

typedef struct NODE Node;

static boolean is_empty(const bigInt *list); 
static void insert(bigInt *list, int number);

char *build_cpf_string (bigInt *list);

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
        char tmp2[3];
        char tmp3[3];
        char tmp4[2];

//      printf("sizeof(tmp1) = %ld\n", sizeof(tmp1));
//      printf("sizeof(tmp4) = %ld\n", sizeof(tmp4));

        int n1 = atoi(strncpy(tmp1, &c[0], sizeof(tmp1)));
//        printf("%d\n", n1);
        insert(list, n1);
        int n2 = atoi(strncpy(tmp2, &c[3], sizeof(tmp2)));
//        printf("%d\n", n2);
        insert(list, n2);
        int n3 = atoi(strncpy(tmp3, &c[6], sizeof(tmp3)));
//        printf("%d\n", n3);
        insert(list, n3);
        strncpy(tmp4, &c[9], sizeof(tmp4));
        tmp4[2] = '\0';
        int n4 = atoi(strncpy(tmp4, &c[9], sizeof(tmp4)));
//        printf("%02d\n", n4);
        insert(list, n4);
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

//        char *c;

        build_cpf_string(list);
//        printf("len = %ld\n", strlen(c));

        /**
        Node *current = list->begin;
        while(current != NULL) {
            current = current->next;
        }
        **/
    }
}

char *build_cpf_string(bigInt *list){
    if(list != NULL){
        Node *node = list->begin;
        char current[4];
        char * string = malloc(sizeof(char));
        while(node != NULL){

            sprintf(current, "%02d", node->number);
            printf("%s\n", current);

            strcat(string, current);
            node = node->next;

        }
        printf("%s\n", string);
    }
    return NULL;
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
            else return false;

            current_n1 = current_n1->next;
            current_n2 = current_n2->next;
        }
    }
    return false;
}
