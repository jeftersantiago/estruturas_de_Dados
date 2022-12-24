#include "AVLTree.h"
typedef struct NODE Node;


static void preorder_traversal_recursive(Node *node);
/*
static void inorder_traversal_recursive(Node *node);
static void postorder_traversal_recursive(Node *node);

static void print2DUtil(Node *parent, int space);
static AVLTree * newTree () ;
*/
static Node * newNode (Game * game) ;

static Node  * leftRotate (Node * node) ;
static Node  * rightRotate (Node * node) ;
static Node * insertNode (Node * node, Game * game, int * flag);
static void insert (AVLTree * tree, Game * game);

struct NODE {
  Node * left;
  Node * right;
  Game * game;
  int balance;
};
struct AVL_TREE {
  Node * parent;
};


AVLTree * createTree () {
  AVLTree * tree = (AVLTree *) malloc(sizeof(AVLTree));
  if(tree != NULL)
    tree->parent = NULL;
  return tree;
}
AVLTree * newTree () {

  AVLTree * tree = createTree() ;

  char * fname = "./data/allGames.csv";
  FILE *file;
  file = fopen(fname, "r");

  char line[200];
  Game * game =  NULL;   // (Game **) malloc(sizeof(Game *) * 34);//
  int i = 0;

  while(fgets(line, 200, file)){
    game = newGame(line);
    //    printf("i = %d - ", i);
    printGame(game);
    insert(tree, game);
    i++;
  }

  preorder_traversal_recursive(tree->parent);

  fclose(file);
  return tree;
}

static Node * newNode(Game * game) {
  Node * node = (Node *) malloc(sizeof(Node));
  if(node != NULL) {
    node->game = game;
    node->left = NULL;
    node->right = NULL;
    /* */
    node->balance = 0;
  }
  return node;
}
static Node * leftRotate (Node * node) {
  if(node != NULL){
    Node * aux = node->right;
    node->right = aux->left;
    aux->left = node;
    return aux;
  }
  return NULL;
}
static Node * rightRotate (Node * node) {
  if(node != NULL){
    Node * aux = node->left;
    node->left = aux->right;
    aux->right = node;
    return aux;
  }
  return NULL;
}

Node * insertNode (Node * node, Game * game, int * flag) {

  if(node != NULL){

    /* Caso 1 -> Insercao do lado esquerdo. */
    if(isGreater(node->game, game)) {

      node->left = insertNode(node->left, game, flag);
      if(*flag == 1) {
        /* Casos de balanceamento */
        switch(node->balance){
        case -1:
          node->balance = 0;
          *flag = 0;
          break;
        case 0:
          node->balance = 1;
          *flag = 1;
          break;
          /* Caso com desbalanceamento.
             node->height > 1
           */
        case 1:
          /* Caso: Rotacao simples */
          if(node->left->balance == 1) {
            node = rightRotate(node);
            node->right->balance = 0;
            node->balance = 0;
          }
          /* Rotacao dupla */
          else {

            node->left = leftRotate(node->left);
            node = rightRotate(node);

            if(node->balance == -1){
              node->left->balance = 1;
              node->right->balance = 0;
              node->balance = 0;
            }
            else if(node->balance == 1){
              node->left->balance = 0;
              node->right->balance = -1;
              node->balance = 0;
            }
            else { // node->balance == 0
              node->left->balance = 0;
              node->right->balance = 0;
              node->balance = 0;
            }
          }
          *flag = 0;
          break;
        }
    }
      }
    /* Caso 2 -> Insercao do lado direito. */
    else if (isGreater(game, node->game)){
      
      node->right = insertNode(node->right, game, flag);

      if(*flag == 1) {
        /* Casos de balanceamento */
        switch(node->balance){
        case 1:
          node->balance = 0;
          *flag = 0;
          break;
        case 0:
          node->balance = -1;
          *flag = 1;
          break;
          /* Caso com desbalanceamento.
             node->height > 1
           */
        case -1:
          /* Caso: Rotacao simples */
          if(node->right->balance == -1) {
            node = leftRotate(node);
            node->left->balance = 0;
            node->balance = 0;
          }
          /* Rotacao dupla */
          else {

            node->right = rightRotate(node->right);
            node = leftRotate(node);

            if(node->balance == -1){
              node->left->balance = 1;
              node->right->balance = 0;
              node->balance = 0;
            }
            else if(node->balance == 1){
              node->left->balance = 0;
              node->right->balance = -1;
              node->balance = 0;
            }
            else { // node->balance == 0
              node->left->balance = 0;
              node->right->balance = 0;
              node->balance = 0;
            }
          }
          *flag = 0;
          break;
        }
      }
    }
  }
  else {
    node = newNode (game);
  }
  return node;
}

static void insert (AVLTree * tree, Game * game){
  int flag = 1;
  tree->parent = insertNode(tree->parent, game, &flag);
}

void traverse (AVLTree * tree, int transverseType){
  preorder_traversal_recursive(tree->parent);
}

static void preorder_traversal_recursive(Node *node){
  if(node != NULL){
    printGame(node->game);
    preorder_traversal_recursive(node->left);
    preorder_traversal_recursive(node->right);
  }
}


static void delete_node(Node * node){
  Node * auxRight = NULL;
  Node * auxLeft = NULL;

  if(node != NULL){
    auxLeft = node->left;
    auxRight = node->right;

    deleteGame(node->game);
    free(node);
    
    delete_node(auxLeft);
    delete_node(auxRight);
  }
}

void deleteTree(AVLTree * tree){
  if(tree != NULL){
    Node * parent = tree->parent;
    if(parent != NULL){
      delete_node(parent);
    }
    free(tree);
  }
}


