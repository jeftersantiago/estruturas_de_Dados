#ifndef _AVLTree_
#define _AVLTree_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Game.h"

typedef struct AVL_TREE AVLTree;
typedef struct NODE Node;

AVLTree * buildTree();

void insert(AVLTree * tree, Game * game);
void traverse(AVLTree *tree, int traverseType);

// void remove(Tree * tree);

void deleteTree(AVLTree * tree);

void printTree(AVLTree *tree);
#endif
