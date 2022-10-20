#include "binary_tree.h"

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




