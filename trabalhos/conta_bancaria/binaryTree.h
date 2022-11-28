#ifndef _binary_tree
#define _binary_tree

#include "bankAccount.h"

typedef struct BINARY_TREE BTree;
typedef struct NODE Node;

typedef void (*Traversal) (Node *tree);

BTree *createTree();

void print_b_tree(BTree *tree);

void insert(BTree  *tree, Account *account);
void removeFromTree(BTree *tree, char * cpf);

Account * searchTree (BTree * tree, char * cpf);

void traverse(BTree *tree, Traversal traversal);

void preorder_traversal(Node *node);
void inorder_traversal(Node *node);
void postorder_traversal(Node *node);

void delete_tree(BTree * tree);
#endif
