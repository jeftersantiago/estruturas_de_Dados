#include "binary_tree.h"
#include "bank_account.h"


static void preorder_traversal_recursive(Node *node);
static void postorder_traversal_recursive(Node *node);
static void inorder_traversal_recursive(Node *node);

struct NODE{
    Account *account;
    Node *right;
    Node *left;
};
struct BINARY_TREE {
    Node *parent;
    int height;
};

static Account * search(Node * node, CPF * cpf){
  if(node == NULL) return NULL;
  if(compareCPF(cpf, getCPF(node->account), equal))
    return node->account;
  if(compareCPF(getCPF(node->account), cpf, greater))
    return search(node->left, cpf);
  else
    return search(node->right, cpf);
}

Account * searchTree (BTree * tree, char * key) {
  CPF * cpf = newCPF(key);
  return search(tree->parent, cpf);
}

Account * swapMaxLeft (Node * swap, Node * parent, Node *prior) {
  if(swap->right != NULL) {
    swapMaxLeft(swap->right, parent, swap);
    return NULL;
  }
  if(parent == prior)
    prior->left = swap->left;
  else
    prior->right = swap->left;

  Account *tmp = parent->account;

  parent->account = swap->account;

  free(swap);
  swap = NULL;

  return tmp;
}

static Account * removeNode (Node ** node, CPF * cpf){
  Node * p;
  if(*node == NULL) return NULL;

  if(compareCPF(getCPF((*node)->account), cpf, equal)){
    if((*node)->left == NULL || (*node)->right == NULL){
      p = *node;
      if((*node)->left == NULL)
        *node = (*node)->right;
      else
        *node = (*node)->left;
      free(p);
      p = NULL;
    }
    /* Tem 2 nós filhos */
    else
      return swapMaxLeft ((*node)->left, *node, *node);
  }
  else {
    if(compareCPF(getCPF((*node)->account), cpf, greater))
       return removeNode(&(*node)->left, cpf);
    else
       return removeNode(&(*node)->right, cpf);
  }
  return NULL;
}
  
void removeFromTree (BTree * tree, char * key) {
  CPF * cpf = newCPF(key);
  removeNode(&tree->parent, cpf);
}

BTree *createTree() {
    BTree *tree = (BTree *) malloc(sizeof(BTree));    
    if(tree != NULL){
        tree->parent = NULL;
        tree->height = -1;
    }
    return tree;
}

static Node * createNode(Account *account){
    Node * newNode = (Node *) malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->account = account;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

static Node * insertNode(Node *parent, Account *account){

  if(parent == NULL)
    parent = createNode(account);
  else if(compareCPF(getCPF(account), getCPF(parent->account), greater)) 
    parent->right = insertNode(parent->right, account);
  else if (compareCPF(getCPF(parent->account), getCPF(account), greater)) 
    parent->left = insertNode(parent->left, account);

  return parent;
}

void insert(BTree  *tree, Account *account){
  if(tree->parent == NULL)
    tree->parent = createNode(account);
  else
    insertNode(tree->parent, account);
}

/**
   Example of use
   traverse(tree, inorder_traversal)
 **/
void traverse(BTree *tree, Traversal traversal){
    traversal(tree->parent);
}

void preorder_traversal(Node *node) {
  preorder_traversal_recursive(node);
}

void inorder_traversal(Node *node) {
  inorder_traversal_recursive(node);
}

void postorder_traversal(Node *node) {
  postorder_traversal_recursive(node);
}

static void preorder_traversal_recursive(Node *node){
  if(node != NULL){
    printCPF(getCPF(node->account), false);
    preorder_traversal_recursive(node->left);
    preorder_traversal_recursive(node->right);
  }
}

static void inorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        printCPF(getCPF(node->account), false);
        preorder_traversal_recursive(node->right);
    }
}

static void postorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        preorder_traversal_recursive(node->right);
        printCPF(getCPF(node->account), false);
    }
}

static void delete_node(Node * node){
  Node * auxRight = NULL;
  Node * auxLeft = NULL;

  if(node != NULL){
    auxLeft = node->left;
    auxRight = node->right;

    deleteAccount(node->account);
    free(node);
    
    delete_node(auxLeft);
    delete_node(auxRight);
  }

}
void delete_tree(BTree * tree){
  Node * parent = tree->parent;
  if(parent != NULL){
    delete_node(parent->left);
    delete_node(parent->right);
  }
  free(tree);
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
  printf("%d\n", getCPF_tests(getCPF(parent->account)));
  //int getCPF_tests(CPF *c);

  // Process left child
  print2DUtil(parent->left, space);
}

// Wrapper over print2DUtil()
void print_b_tree(BTree *tree)
{
    // Pass initial space count as 0
    print2DUtil(tree->parent, 0);
}

