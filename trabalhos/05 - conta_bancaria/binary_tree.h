#ifndef _binary_tree
#define _binary_tree

#define RIGHT 0
#define LEFT 1

#include "bank_account.h"

typedef struct BINARY_TREE b_tree;

// search(b_tree *tree, const char *key);

b_tree *createTree();

void insert(b_tree  *tree, Account *account);


#endif


