#include "AVLTree.h"
typedef struct NODE Node;

static void preorder_traversal(Node *node);
static void inorder_traversal(Node *node);
static void postorder_traversal(Node *node);

static Node  * leftRotate (Node * node) ;
static Node  * rightRotate (Node * node) ;
static Node * insertNode (Node * node, Game * game, int * flag);
static Node * removeNode (Node * node, Game * game, int * h);
static void delete_node(Node * node);
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

  char * fname = "CSV.csv";
  FILE *file;
  file = fopen(fname, "r");
  fseek(file, 3, SEEK_SET);

  char line[200];
  Game * game =  NULL;

  while(fgets(line, 200, file) != NULL){
    game = newGame(line);
    insert(tree, game);
  }

  fclose(file);
  return tree;
}

static Game * search(Node * node, int year){
  if(node == NULL)
    return NULL;
  if(getYear(node->game) == year)
     return node->game;
  if(getYear(node->game) > year)
    return search(node->left, year);
  else
    return search(node->right, year);
}
Game * searchGame(AVLTree * tree, int year) {
  if(tree != NULL)
    return search(tree->parent, year);
  return NULL;
}

static Node * newNode(Game * game) {
  Node * node = (Node *) malloc(sizeof(Node));
  if(node != NULL) {
    node->game = game;
    node->left = NULL;
    node->right = NULL;
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
static Node * leftRightRotate(Node * node){
  if(node != NULL){
    node->left = leftRotate(node->left);
    node = rightRotate(node);
  }
  return node;
}
static Node * rightLeftRotate(Node * node){
  if(node != NULL){
    node->right = rightRotate(node->right);
    node = leftRotate(node);
  }
  return node;
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
          /* Caso com desbalanceamento. node->height > 1 */
        case 1:
          /* Caso: Rotacao simples */
          if(node->left->balance == 1) {
            node = rightRotate(node);
            node->right->balance = 0;
            node->balance = 0;
          }
          /* Sinais diferentes -> Rotacao dupla */
          else {
            node = leftRightRotate(node);
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
        switch(node->balance){
        case 1:
          node->balance = 0;
          *flag = 0;
          break;
        case 0:
          node->balance = -1;
          *flag = 1;
          break;
        case -1:
          // node->left->balance == -1
          if(node->right->balance == -1) {
            node = leftRotate(node);
            node->left->balance = 0;
            node->balance = 0;
          }
          else {
            node = rightLeftRotate(node);
            if(node->balance == -1){
              node->left->balance = 1;
              node->right->balance = 0;
              node->balance = 0;
            }
            else if (node->balance == 1) {
              node->left->balance = 0;
              node->right->balance = -1;
              node->balance = 0;
            }
            // node->balance == 0
            else { 
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
  else{
    node = newNode (game);
    node->balance = 0;
    *flag = 1;
  }
  return node;
}

static void insert (AVLTree * tree, Game * game){
  int flag = 1;
  tree->parent = insertNode(tree->parent, game, &flag);
}

static Node * rightBalance (Node * node, int * h) {
  switch(node->balance){
    /* altura alterada */
  case  -1:
    node->balance = 0;
    break;
    /* altura nao alterada */
  case 0:
    node->balance = 1;
    *h = 0;
    break;
    /* altura alterada e arvore desbalanceada */
  case 1:
    /* Rotacao simples a esquerda */
    if(node->left->balance >= 0){
      node = rightRotate(node);
      if(node->balance == 0){
        node->right->balance = 1;
        node->balance = -1;
        *h = 0;
      } else {
        node->right->balance = 0;
        node->balance = 0;
      }
    }
    else {
      /* Rotacao dupla Esquerda/Direita */
      node = leftRightRotate(node);
      if(node->balance == 1) {
        node->left->balance =  0;
        node->right->balance = -1;
      }
      else if (node->balance == -1){
        node->left->balance = 1;
        node->right->balance = 0;
      }
      // node->balance == 0 
      else { 
        node->left->balance = 0;
        node->right->balance = 0;
      }
      node->balance = 0;
    }
    break;
  }
  return node;
}
static Node * leftBalance (Node * node, int * h) {
  switch(node->balance){
    /* altura alterada */
  case  1:
    node->balance = 0;
    break;
    /* altura nao alterada */
  case 0:
    node->balance = -1;
    *h = 0;
    break;
    /* altura alterada e arvore desbalanceada */
  case -1:
    /* Rotacao simples a esquerda */
    if(node->right->balance <= 0){
      node = leftRotate(node);
      if(node->balance == 0){
        node->left->balance = -1;
        node->balance = 1;
        /* altura nao muda depois da rotacao */
        *h = 0;
      } else {
        node->left->balance = 0;
        node->balance = 0;
      }
    }
    else {
      /* Rotacao dupla Direita/Esquerda */
      node = rightLeftRotate(node);
      if(node->balance == 1) {
        node->left->balance = 0 ;
        node->right->balance = -1;
      }
      else if (node->balance == -1){
        node->left->balance = 1;
        node->right->balance = 0;
      }
      // node->balance == 0 
      else { 
        node->left->balance = 0;
        node->right->balance = 0;
      }
      node->balance = 0;
    }
    break;
  }
  return node;
}

Node * searchAndRemove (Node * p, Node * node, int * h){
  Node * aux;
  if(p->right != NULL){
    p->right = searchAndRemove(p->right, node, h);
    if(*h == 1)
      p = rightBalance(p, h);
  }
  else {
    deleteGame(node->game);
    node->game = p->game;
    aux = p;
    p = p->left;
    free(aux);
    *h = 1;
  }
  return p;
}
static Node * removeNode (Node * node, Game * game, int * h) {
  Node * aux;
  if(node == NULL){
    printf("Jogo nao encontrado\n");
    *h = 0;
  }
  /* Lado esquerdo. */
  else if (isGreater(node->game, game)){
    node->left = removeNode(node->left, game, h);
    if(*h == 1)
      node = leftBalance(node, h);
  }
  /* Lado direito .*/
  else if (isGreater(game, node->game)){
    node->right = removeNode(node->right, game, h);
    if(*h == 1)
      node = rightBalance(node, h);
  }
  /* game == node->game */
  else {
    /* No eh folha ou tem apenas filho esquerdo */
    if(node->right == NULL) {
      aux = node;
      node = node->left;
      deleteGame(aux->game);
      free(aux);
      *h = 1;
    }
    /* ... ou tem apenas filho direito  */
    else if (node->left == NULL) {
      aux = node;
      node = node->right;
      deleteGame(aux->game);
      free(aux);
      *h = 1;
    }
    else {
      /* Troca no pelo maior da esquerda */
      node->left = searchAndRemove(node->left, node, h);
      if(*h == 1){
        node = leftBalance(node, h);
      }
    }
  }
  return node;
}

void removeGame (AVLTree * tree, Game * game) {
  int flag = 0;
  tree->parent = removeNode(tree->parent, game, &flag);
}

void traverse(AVLTree * tree, int traverseType){
  if(traverseType == 1)
    preorder_traversal(tree->parent);
  else if(traverseType == 2)
    inorder_traversal(tree->parent);
  else if(traverseType == 3)
    postorder_traversal(tree->parent);
}

static void preorder_traversal(Node *node){
  if(node != NULL){
    printGame(node->game);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
  }
}

static void inorder_traversal(Node *node){
    if(node != NULL){
        inorder_traversal(node->left);
        printGame(node->game);
        inorder_traversal(node->right);
    }
}

static void postorder_traversal(Node *node){
    if(node != NULL){
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        printGame(node->game);
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

/* Funcoes de teste */

static void print2DUtil(Node *parent, int space)
{
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
  printGame(parent->game);
  //  printf("%d\n", getYear(parent->game));

  // Process left child
  print2DUtil(parent->left, space);
}

// Wrapper over print2DUtil()
void print_b_tree(AVLTree  *tree)
{
    // Pass initial space count as 0
    print2DUtil(tree->parent, 0);
}
