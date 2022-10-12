#include "stack.h"

struct STACK{
    Item *item;
    int top;
};


Stack *createStack(void){
    Stack* stack = (Stack *) malloc(sizeof(Stack));
    if(stack != NULL)
        stack->top = 0;
    return stack;
}

boolean stackIsEmpty(Stack *stack){
    return ((stack != NULL) ? stack->top == 0 : ERROR);
}











