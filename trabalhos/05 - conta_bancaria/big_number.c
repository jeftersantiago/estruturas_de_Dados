#include "bank_account.h"
#include <string.h>

typedef struct NODE Node;

static boolean is_empty(const CPF *list); 
static void insert(CPF *list, int number);

struct NODE {
    int number;
    Node *next;
};

struct BIG_NUMBER {
    Node *begin;
    Node *end;
    int size;
};

CPF *newCPF(char *c) {

    CPF *list = (CPF *) malloc(sizeof(CPF));

    if(list != NULL) {

        list->begin = NULL;
        list->end = NULL;
        list->size = 0;

        char tmp[3];
        char tmp2[2];
        int n;

        n = atoi(strncpy(tmp, &c[0], sizeof(tmp)));
        insert(list, n);

        n = atoi(strncpy(tmp, &c[3], sizeof(tmp)));
        insert(list, n);
        
        n = atoi(strncpy(tmp, &c[6], sizeof(tmp)));
        insert(list, n);

        strncpy(tmp2, &c[9], sizeof(tmp2));
        tmp2[2] = '\0';
        n = atoi(strncpy(tmp2, &c[9], sizeof(tmp2)));
        insert(list, n);
    }
    free(c);
    return list;
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

boolean compareCPF(Account *parent, Account *new){
    CPF *cpf_1 = getCPF(parent);
    CPF *cpf_2 = getCPF(new);
    if(cpf_1 != NULL && cpf_2 != NULL){
        Node *current_n1 = cpf_1->begin;
        Node *current_n2 = cpf_2->begin;

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

void printCPF(CPF *cpf){
    if(cpf != NULL)
        printf("CPF :: %d.%d.%d-%02d\n",
               cpf->begin->number,
               cpf->begin->next->number,
               cpf->begin->next->next->number,
               cpf->begin->next->next->next->number
            );
}

