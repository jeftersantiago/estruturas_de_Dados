#include "stack.h"

struct NODE{
    Item *item;
    Node *next;   
};
struct STACK{
    Node *top;
    int size;
};


Stack *createStack(){
    Stack* stack = (Stack *) malloc(sizeof(Stack));
    if(stack != NULL){
        stack->top= NULL;
        stack->size = 0;
    }
    return stack;
}

boolean stackItems(Stack *stack, Item *item){
    Node* node = (Node *) malloc(sizeof(Node *)); 
    if(node != NULL){
        node->item = item;
        node->next = stack->top;
        stack->top = node;
        stack->size++;
        return true;
    }
    return false;
}

void deleteStack(Stack **stack){
    Node *auxStack;

    if(((*stack) != NULL) && (!stackIsEmpty(*stack)))
        while((*stack)->top != NULL){

            auxStack = (*stack)->top;
            (*stack)->top = (*stack)->top->next;
            deleteItem(&auxStack->item);
            auxStack->next = NULL;
            free(auxStack); auxStack = NULL;

        }
    free(*stack);
    *stack = NULL;
}


boolean stackIsEmpty(Stack* stack){
    return ((stack != NULL) ? stack->size == 0 : false);
}

int stackSize(Stack* stack){
    return ((stack != NULL) ? stack->size : 0);
}


Item* stackTop(Stack* stack){
    if((stack != NULL) && (!stackIsEmpty(stack))){
        return stack->top->item;
    }
    return NULL;
}
    
Item* unstack(Stack* stack){
    if((stack != NULL) && (!stackIsEmpty(stack))){
        Node* node = stack->top;
        Item* item = stack->top->item;
        stack->top = stack->top->next;
        node->next = NULL;
        free(node);
        node = NULL;
        stack->size--;
        return item;
    }
    return NULL;
}
