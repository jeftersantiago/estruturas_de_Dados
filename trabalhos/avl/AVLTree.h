#ifndef _avl_tree_
#define _avl_tree_
#include "Game.h"

typedef struct AVL_TREE AVLTree;

AVLTree * newTree ();


Game * searchGame(AVLTree * tree, int year);
void removeGame (AVLTree * tree, Game * game);

void deleteTree (AVLTree * tree);
void traverse (AVLTree * tree, int trasverseType);
void print_b_tree(AVLTree  *tree);
#endif
