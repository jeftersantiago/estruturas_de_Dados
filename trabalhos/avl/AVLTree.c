#include "AVLTree.h"
#include "Game.h"

static void preorder_traversal_recursive(Node *node);
static void inorder_traversal_recursive(Node *node);
static void postorder_traversal_recursive(Node *node);

static void deleteNode(Node * node);

static Node * createNode(Game * game);
static Node * insertNode (Node * parent, Game * game) ;

static void print2DUtil(Node *parent, int space);

struct AVL_TREE {
  Node * parent;
  int height;
};

struct NODE {
  Game * game;
  Node * left;
  Node * right;
};


AVLTree * buildTree() {

  AVLTree * tree = NULL; // (AVLTree *) malloc(sizeof(AVLTree));

  char * fname = "./data/allGames.csv";
  FILE *file;
  file = fopen(fname, "r");

  //  char * line = (char *) malloc(sizeof(char *) * 100);
  char line[150];

  Game ** game  = (Game **) malloc(sizeof(Game *) * 34);
  int i = 0 ;
  while(fgets(line, 150, file)){

    game[i] = newGame(line);
    printGame(game[i]);
    
    //    insert(tree, game[i]);
    //    printTree(tree);
    i++;
  }  

  for(int i = 0; i < 34; i++)
    printGame(game[i]);
  

  fclose(file);
  //  free(line);
  return tree;
}

static Node * createNode(Game * game){
  Node * newNode  = (Node *) malloc(sizeof(Node));
  if(newNode != NULL){
    newNode->game = game;
    newNode->left = NULL;
    newNode->right = NULL;
  }
  return newNode;
}
static Node * insertNode (Node * parent, Game * game) {
  if(parent == NULL)
    parent = createNode(game);
  else if (compare(game, parent->game))
    parent->right = insertNode(parent->right, game);
  else if (compare(parent->game, game))
    parent->left = insertNode(parent->left, game);
  return parent;
}

void insert(AVLTree * tree, Game * game){
  if(tree->parent == NULL)
    tree->parent = createNode(game);
  else
    insertNode(tree->parent, game);
}

void traverse(AVLTree *tree, int traverseType){
  if(traverseType == 1)
    preorder_traversal_recursive(tree->parent);
  if(traverseType == 2)
    inorder_traversal_recursive(tree->parent);
  if(traverseType == 3)
    postorder_traversal_recursive(tree->parent);
}

static void preorder_traversal_recursive(Node *node){
  if(node != NULL){
    //    printCPF(getCPF(node->account), false);
    preorder_traversal_recursive(node->left);
    preorder_traversal_recursive(node->right);
  }
}

static void inorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        //        printCPF(getCPF(node->account), false);
        preorder_traversal_recursive(node->right);
    }
}

static void postorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        preorder_traversal_recursive(node->right);
        //        printCPF(getCPF(node->account), false);
    }
}


static void deleteNode(Node * node){
  Node * auxRight = NULL;
  Node * auxLeft = NULL;

  if(node != NULL){
    auxLeft = node->left;
    auxRight = node->right;

    deleteGame(node->game);
    free(node);
    
    deleteNode(auxLeft);
    deleteNode(auxRight);
  }

}
void deleteTree(AVLTree * tree){
  Node * parent = tree->parent;
  if(parent != NULL){
    deleteNode(parent->left);
    deleteNode(parent->right);
  }
  free(tree);
}
void printTree(AVLTree *tree) {
  print2DUtil(tree->parent, 0);
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
static void print2DUtil(Node *parent, int space){
  int COUNT = 6;
  // Base case
  if (parent == NULL)
    return;

  // Increase distance between levels
  space += COUNT;

  // Process right child first
  print2DUtil(parent->right, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  // printf("%s\n", getName(parent->account));
  printf("%s\n", getName(parent->game));
  //int getCPF_tests(CPF *c);

  // Process left child
  print2DUtil(parent->left, space);
}
