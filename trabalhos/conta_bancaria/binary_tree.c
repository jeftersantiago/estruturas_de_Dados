#include "binary_tree.h"
#include "bank_account.h"

typedef struct NODE Node;

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

Account * searchTree (b_tree * tree, char * key) {
  CPF * cpf = newCPF(key);
  return search(tree->parent, cpf);
}

b_tree *createTree() {
    b_tree *tree = (b_tree *) malloc(sizeof(b_tree));    
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

/**
   Parametros:
   boolean side : Assumi que se side == true, então o lado
   é direito.
 **/
static Node * insertNode(Node *parent, Account *account, CPF *cpf){

  boolean side = false;
  if(parent != NULL)
    side = compareCPF(getCPF(parent->account), getCPF(account), greater);

  if(parent == NULL)
    parent = createNode(account);
  else if(side)
    parent->right = insertNode(parent->right, account, cpf);
  else if(!side)
    parent->left = insertNode(parent->left, account, cpf);
  return parent;
}

void insert(b_tree  *tree, Account *account){
  if(tree->parent == NULL)
    tree->parent = createNode(account);
  else
    insertNode(tree->parent, account, getCPF(tree->parent->account));
}

/**
   Example of use
   traverse(tree, inorder_traversal)
 **/
void traverse(b_tree *tree, Traversal traversal){
    traversal(tree);
}

void preorder_traversal(b_tree *tree){preorder_traversal_recursive(tree->parent);}

void inorder_traversal(b_tree *tree){inorder_traversal_recursive(tree->parent);}

void postorder_traversal(b_tree *tree){postorder_traversal_recursive(tree->parent);}

static void preorder_traversal_recursive(Node *node){
    if(node != NULL){
        printAccount(node->account);
        preorder_traversal_recursive(node->left);
        preorder_traversal_recursive(node->right);
    }
}

static void inorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        printAccount(node->account);
        preorder_traversal_recursive(node->right);
    }
}

static void postorder_traversal_recursive(Node *node){
    if(node != NULL){
        preorder_traversal_recursive(node->left);
        preorder_traversal_recursive(node->right);
        printAccount(node->account);
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
void delete_tree(b_tree * tree){
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
void print_b_tree(b_tree *tree)
{
    // Pass initial space count as 0
    print2DUtil(tree->parent, 0);
}

