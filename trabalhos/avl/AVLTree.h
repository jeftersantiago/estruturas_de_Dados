#ifndef _avl_tree_
#define _avl_tree_
#include "Game.h"

typedef struct AVL_TREE AVLTree;
AVLTree * newTree ();
void deleteTree (AVLTree * tree);
void traverse (AVLTree * tree, int trasverseType);
#endif
