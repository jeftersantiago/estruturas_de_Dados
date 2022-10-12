#ifndef _stack_
#define _stack_
#include "util.h"

typedef struct STACK Stack;

Stack  *createStack(void);
void deleteStack(Stack **stack);
int emptyStack(Stack *stack);
boolean stackIsEmpty(Stack *stack);
Stack *top(Stack *stack);

void printStack(Stack *stack);
void inserveStack(Stack *stack);


#endif
