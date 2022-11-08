#ifndef _btree_
#define _btree_

#include "util.h"

typedef struct BINARY_TREE b_tree;

typedef void (*Traversal) (b_tree *tree);

b_tree *create_b_tree();

void traverse(b_tree *tree, Traversal traversal);

void preorder_traversal(b_tree *tree);
void inorder_traversal(b_tree *tree);
void postorder_traversal(b_tree *tree);

boolean insert_item(b_tree *tree, Item *item, int side, int key);
#endif
