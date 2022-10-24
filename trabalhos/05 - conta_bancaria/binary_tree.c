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
    Node * new = (Node *) malloc(sizeof(Node));
    if(new != NULL){
        new->account = account;
        new->left = NULL;
        new->right = NULL;
    }
    return new;
}

/**
   Parametros:
   boolean side : Assumi que se side == true, então o lado
   é direito, e o contrario é esquerdo.
 **/
static Node * insert_node(Node *parent, Account *account, boolean side){
    if(parent != NULL){
        parent->left = insert_node(parent->left, account, side);
        parent->right = insert_node(parent->right, account, side);

        if(side)
            parent->right = create_node(account);
        else
            parent->left = create_node(account);

    }
    return parent;
}

void insert(b_tree  *tree, Account *account){
    if(tree->parent == NULL)
        tree->parent = create_node(account);
    else
    {
        boolean side = compareCPF(tree->parent->account, account);
        tree->parent = insert_node(tree->parent, account, side);
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





















