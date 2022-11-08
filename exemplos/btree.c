#include "btree.h"

#define LEFT 0
#define RIGHT 1 


static void preorder_traversal_recursive(b_tree *tree);
static void inorder_traversal_recursive(b_tree *tree);
static void postorder_traversal_recursive(b_tree *tree);

static b_tree create_node(Item *item, b_tree *parent);

struct BINARY_TREE{

    b_tree *parent;
    b_tree *right;
    b_tree *left;

    Item *item;

    int height;
};


b_tree *create_b_tree(){

    b_tree *tree = (b_tree *) malloc(sizeof(b_tree));
    tree->item = NULL;

    if(tree != NULL){
        tree->parent = NULL;
        // Top node.
        tree->height = -1;
    }
    return tree;
}


boolean insert_item(b_tree *tree, Item *item, int side, int key){
////    if(tree->parent == NULL)
//        return (tree->parent = ;
    return 1;
}

/**
   Example of use
   traverse(tree, inorder_traversal)
 **/
void traverse(b_tree *tree, Traversal traversal){
    traversal(tree);
}

void preorder_traversal(b_tree *tree){
    preorder_traversal_recursive(tree->parent);
}

void inorder_traversal(b_tree *tree){
   inorder_traversal_recursive(tree);
}

void postorder_traversal(b_tree *tree){
    postorder_traversal_recursive(tree);
}


static void preorder_traversal_recursive(b_tree *tree){
    if(tree->parent != NULL){
        printItem(tree->item);
        preorder_traversal_recursive(tree->left);
        preorder_traversal_recursive(tree->right);
    }
}

static void inorder_traversal_recursive(b_tree *tree){
    if(tree->parent != NULL){
        preorder_traversal(tree->left);
        printItem(tree->item);
        preorder_traversal(tree->right);
    }
}

static void postorder_traversal_recursive(b_tree *tree){
    if(tree->parent != NULL){
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
        printItem(tree->item);
    }
}

static b_tree create_node(Item *item, b_tree *parent){
    b_tree *new_node = create_b_tree();
    if(new_node != NULL){
        new_node->item = item;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = parent;
    }
}







