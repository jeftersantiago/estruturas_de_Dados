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

// void search(b_tree *tree, const char *key);

b_tree *createTree() {
    b_tree *tree = (b_tree *) malloc(sizeof(b_tree));    
    if(tree != NULL){
        tree->parent = NULL;
        tree->height = -1;
    }
    return tree;
}

static Node * create_node(Account *account){
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
static Node * insert_node(Node *parent, Account *account, boolean side, CPF *cpf){

    if(parent != NULL){

      parent->right = insert_node(parent->right, account, side, cpf);
      parent->left = insert_node(parent->left, account, side, cpf);

      if(cpf == getCPF(parent->account)){
        //        if(side){
          //          parent->right = create_node(account);
          //        }
          //        else{
          parent->left = create_node(account);
          //        }
      }
    }
    return parent;
}

void insert(b_tree  *tree, Account *account){
    if(tree->parent == NULL)
        tree->parent = create_node(account);
    else
    {
      boolean side = compareCPF(tree->parent->account, account);
      if(side && tree->parent->right != NULL)
        printAccount(tree->parent->right->account);
      /**
         if(tree->parent->right != NULL)
         printAccount(tree->parent->right->account);
         if(tree->parent->left != NULL)
         printAccount(tree->parent->left->account);
      **/

      tree->parent = insert_node(tree->parent, account, side, getCPF(tree->parent->account));
    }
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

// Function to print binary tree in 2D
// It does reverse inorder traversal
// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
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
  printf("%s\n", getName(parent->account));

  // Process left child
  print2DUtil(parent->left, space);
}

// Wrapper over print2DUtil()
void print_b_tree(b_tree *tree)
{
    // Pass initial space count as 0
    print2DUtil(tree->parent, 0);
}

