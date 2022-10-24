#ifndef _binary_tree
#define _binary_tree

#define RIGHT 0
#define LEFT 1

#include "bank_account.h"

typedef struct BINARY_TREE b_tree;

typedef void (*Traversal) (b_tree *tree);


b_tree *createTree();
void insert(b_tree  *tree, Account *account);

void traverse(b_tree *tree, Traversal traversal);

void preorder_traversal(b_tree *tree);
void inorder_traversal(b_tree *tree);
void postorder_traversal(b_tree *tree);



// search(b_tree *tree, const char *key);

#endif


