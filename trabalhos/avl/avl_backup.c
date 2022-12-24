#include "AVLTree.h"
typedef struct NODE Node;


static void preorder_traversal_recursive(Node *node);
static void inorder_traversal_recursive(Node *node);
static void postorder_traversal_recursive(Node *node);

static AVLTree * createTree () ;
static void delete_node(Node * node);


static Node * insertNode(Node * node, Game * game);
static void insert (AVLTree * tree, Game * game);

static int max(int a, int b);


struct NODE {
  Game * game;
  Node * left;
  Node * right;
  int height;
};

struct AVL_TREE {
  Node * parent;
};

static AVLTree * createTree () {
  AVLTree * tree = (AVLTree *) malloc(sizeof(AVLTree));
  if(tree != NULL){
    tree->parent = NULL;
  }
  return tree;
}
AVLTree * newTree() {

  AVLTree * tree = createTree(); 

  char * fname = "./data/allGames.csv";
  FILE *file;
  file = fopen(fname, "r");

  char line[150];

  Game * game  = NULL; 
  int i = 0 ;
  while(fgets(line, 150, file)){
    game = newGame(line);
//    insert(tree, game);
    i++;
  }  
  fclose(file);
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
    printGame(node->game);
    preorder_traversal_recursive(node->left);
    preorder_traversal_recursive(node->right);
  }
}



static void inorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        printGame(node->game);
        preorder_traversal_recursive(node->right);
    }
}

static void postorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        preorder_traversal_recursive(node->right);
        printGame(node->game);
    }
}

static int height (Node * node) {
  if(node != NULL)
    return node->height;
  return 0;
}

static int max(int a, int b) {
  return a > b ? a : b;
}

static Node * rightRotate (Node * node) {
  if(node != NULL){

    Node * aux = node->left;
    node->left = aux->right;
    aux->right = node;

    node->height = max(height(node->left), height(node->right)) + 1;
    aux->height =  max(height(aux->left),  height(aux->right))  + 1;

    return aux;
  }
  return NULL;
}

static Node * leftRotate (Node * node) {
  if(node != NULL){

    Node *aux = node->right;
    node->right = aux->left;
    aux->left = node;

    node->height = max(height(node->left), height(node->right)) + 1;
    aux->height =  max(height(aux->left), height(aux->right))   + 1;

    return aux;
  }
  return NULL;
}
static int balanceFactor (Node * node) {
  if(node != NULL){
    printf("height(node->left) = %d\n", height(node->left));
    printf("height(node->right) = %d\n", height(node->right));
    return height(node->left) - height(node->right);
  }
  else
    return 0;
}

static  Node  * rebalance(Node ** node) {

  int bf = balanceFactor(*node);
  printf("BF = %d\n", bf);

  /* Caso 1 -> Arvore desbalanceada para esquerda */
  if(bf >= 1){
    /* Caso 1.1 -> Rotacao dupla */
    if(balanceFactor((*node)->right) < 0){
      (*node)->right = rightRotate((*node)->right);
      (*node) = leftRotate(*node);
    }
    else
      *node = leftRotate(*node);
  }
  /* Caso 2 -> Arvore desbalanceada para direita */
  else if (bf <= -1){
    /* Caso 2.1 - Rotacao dupla */
     if(balanceFactor((*node)->left) > 0){
      (*node)->left = rightRotate((*node)->left);
      (*node) = rightRotate(*node);
    }   
     else
       *node = rightRotate(*node);
  }
  return *node;
}

static Node * insertNode (Node * node, Game * game) {

  if(node == NULL){
    return createNode(game);
  }

  if(isGreater(node->game, game)){
    //    printf("Esquerda -> "); printGame(game);
    insertNode(node->left, game);
  }
  else if(isGreater(game, node->game)){
    //    printf("Direita -> "); printGame(game);
    insertNode(node->right, game);
  }

  node->height = 1 + max(height(node->left), height(node->right));
  printf("node->height = %d\n", node->height);
  //  node = rebalance(&node);
  int balance = balanceFactor(node);
  printf("BF = %d\n", balance);

  return node;
}

static void insert (AVLTree * tree, Game * game) {
  tree->parent = insertNode(tree->parent, game);
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

