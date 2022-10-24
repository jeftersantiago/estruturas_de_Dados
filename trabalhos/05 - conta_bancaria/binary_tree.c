#include "binary_tree.h"
#include "bank_account.h"

typedef struct NODE Node;

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

static Node * insert_node(Node *parent, Account *account, int side){
    
}

void insert(b_tree  *tree, Account *account){
    if(tree->parent == NULL){
        
    }
    /**
    int side = -1;

    if(isGreater(tree->parent->account, account))
        side = 1;
    else
        side = 0;
    **/
}




