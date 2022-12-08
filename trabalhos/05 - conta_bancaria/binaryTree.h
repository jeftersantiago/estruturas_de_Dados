#ifndef _binary_tree
#define _binary_tree

#include "Util.h"
#include "linkedList.h"

typedef struct BINARY_TREE BTree;
typedef struct NODE TreeNode;

BTree *createTree();
Account * searchTree (BTree * tree, char * cpf);
void insertTree(BTree  *tree, Account *account);
void removeFromTree(BTree *tree, char * cpf);
void preorderTraversal(BTree *tree);
void deleteTree(BTree * tree);

#endif
