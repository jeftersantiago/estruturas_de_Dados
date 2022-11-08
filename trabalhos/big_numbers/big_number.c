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

bigInt *newBigInt() {

    bigInt *list = (bigInt *) malloc(sizeof(bigInt));

    if(list != NULL) {

        list->begin = NULL;
        list->end = NULL;
        list->size = 0;

    }
    return list;
}

/**
   Fiz uma matemagica para funcionar, nao sei como deixar mais legivel
   resumindo ele le a string de tras pra frente e quando fecha a qntd
   de digitos por no ele insere
 **/

bigInt *stringtoBigInt(bigInt *n,char *s){
    int N=strlen(s),number=0;
    char c[1];

    for (int i=N-1;i>=0;i--){

        c[0]=s[i];

        if (i==0 && (strcmp(c,"0"))){
            break;
        }
        if (strcmp(c,"-")){

        }

        number+=(atoi(c)*pow(10,(N-i-1)%(N_DIG)));

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
    if(p==n->end)
        printf("%d",p->number);
    else{
        recursivePrint(n,p->next);
        printf("%.4d",p->number);
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
boolean greaterBigInt(bigInt *n1, bigInt *n2){
    if(n1 == NULL || n2 == NULL)
        return false;
    if(n1->size!=n2->size)
        return (n1->size>n2->size ? true:false);

    if(compareBigInt(n1,n2,n1->begin,n2->begin)==1)
        return true;

    return false;
}

static int compareBigInt(bigInt *n1, bigInt *n2, Node *p1, Node *p2){
    if(p1==n1->end)
        return compareNode(p1,p2);

    else{
        int aux=compareBigInt(n1,n2,p1->next,p2->next);;
        if (aux==1)
            return 1;
        if (aux==0)
            return 0;

        return compareNode(p1,p2);
    }
}

static int compareNode(Node *p1, Node *p2){
    if(p1->number>p2->number)
        return 1;
    if(p1->number<p2->number)
        return 0;
    else
        return 2;

}

boolean equalBigInt(bigInt *n1, bigInt *n2){

    if(is_empty(n1) && is_empty(n2))
        return false;
    if(n1->size!=n2->size)
        return false;

    if(compareBigInt(n1,n2,n1->begin,n2->begin)==2)
        return true;

    return false;
}

bigInt *SumBigInt(bigInt *n1, bigInt *n2){
    bigInt *n3=newBigInt();
    int index=0;

    Node *current_n1 = n1->begin;
    Node *current_n2 = n2->begin;

    while(current_n1!=NULL || current_n2!=NULL){
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
