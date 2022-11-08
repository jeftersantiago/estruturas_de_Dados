#include "linked_list.h"

typedef struct NODE Node;

struct NODE {
    Item *item;
    Node *next;
};

struct LIST {
    Node *begin;
    Node *end;
    int size;
};


list *create_list(void){
    list *l = (list *) malloc(sizeof(list));
    if(l != NULL){
        l->begin = NULL;
        l->end = NULL;
        l->size = 0;
    }
    return l;
}

boolean is_empty(const list *l){
    if((l != NULL) && (l->begin->next == NULL))
        return true;
    return false;
}

void insert(list *l, Item *item){
    if(l != NULL){
        Node *node = (Node *) malloc(sizeof(Node));
        if(node != NULL){
            node->item = item;
            node->next = NULL;
            if(is_empty(l))
                l->begin->next = node;
            else
                l->end->next = node;
            l->end = node;
            l->size++;
        }
    }
}

Item *linear_search(list *l, int key){
    if(l != NULL){
        Node *currentNode = l->begin->next;
        while(currentNode != NULL){
            if(getItemKey(currentNode->item) == key)
                return currentNode->item;
            currentNode = currentNode->next;
        }
    }
    return NULL;
}


void remove_item(list *l, int key){
    if(l != NULL){
        Node *currentNode = l->begin;

        while((currentNode != NULL) && (getItemKey(currentNode->next->item) != key)){
        }

        
    }
}



















