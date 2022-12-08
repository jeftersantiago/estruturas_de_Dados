#include "binaryTree.h"
#include "bankAccount.h"

static void preorder_traversal_recursive(TreeNode *node);

struct NODE{
    Account *account;
    TreeNode *right;
    TreeNode *left;
};
struct BINARY_TREE {
    TreeNode *parent;
    int height;
};

static Account * search(TreeNode * node, CPF * cpf){
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
  Account * acc = search(tree->parent, cpf);
  deleteCPF(cpf);
  free(key);
  return acc;
}

/* Remove o nó com a conta que possui o CPF do paramêtro e retorna a conta. */
void removeNode(TreeNode **node, CPF * cpf) {
  if(*node == NULL) return;

  CPF * tmpCPF = getCPF((*node)->account);

  if(compareCPF(tmpCPF, cpf, greater))
    removeNode(&(*node)->left, cpf);
  else if(compareCPF(cpf, tmpCPF, greater))
    removeNode(&(*node)->right, cpf);

  else{
    /* Caso nó folha */
    if((*node)->left == NULL && (*node)->right == NULL){
      free(*node);
      *node = NULL;
      return;
    }
    /* So tem filho direito */
    if((*node)->left == NULL){
      TreeNode * aux = *node;
      *node = (*node)->right;
      free(aux);
      return;
    }
    /* So tem filho esquerdo*/
    if((*node)->right == NULL){
      TreeNode * aux = *node;
      *node = (*node)->left;
      free(aux);
      return;
    }
    /* Tem dois filhos
       Escolhe o menor filho do ramo direito para substituir o no removido.
     */
    else {
      TreeNode * aux = (*node)->right; 
      while(aux->left != NULL)
        aux = aux->left;
      (*node)->account = aux->account;
      return removeNode(&(*node)->right, getCPF(aux->account));
    }
  }
}
  
void removeFromTree (BTree * tree, char * key) {
  CPF * cpf = newCPF(key);
  
  Account * account = search(tree->parent, cpf);
  removeNode(&(tree->parent), cpf);

  if(account != NULL) {
    printAccount(account);
    deleteAccount(account);
  }

  free(key);
  deleteCPF(cpf);
}

BTree *createTree() {
    BTree *tree = (BTree *) malloc(sizeof(BTree));    
    if(tree != NULL){
        tree->parent = NULL;
        tree->height = -1;
    }
    return tree;
}

static TreeNode * createNode(Account *account){
    TreeNode * newNode = (TreeNode *) malloc(sizeof(TreeNode));
    if(newNode != NULL){
        newNode->account = account;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

static TreeNode * insertNode(TreeNode *parent, Account *account){

  if(parent == NULL)
    parent = createNode(account);
  else if(compareCPF(getCPF(account), getCPF(parent->account), greater)) 
    parent->right = insertNode(parent->right, account);
  else if (compareCPF(getCPF(parent->account), getCPF(account), greater)) 
    parent->left = insertNode(parent->left, account);

  return parent;
}

void insertTree(BTree  *tree, Account *account){
  if(tree->parent == NULL)
    tree->parent = createNode(account);
  else
    insertNode(tree->parent, account);
}

void preorderTraversal(BTree *tree) {
  printf("Preorder\n");
  preorder_traversal_recursive(tree->parent);
}

static void preorder_traversal_recursive(TreeNode *node){
  if(node != NULL){
    printCPF(getCPF(node->account), false);
    preorder_traversal_recursive(node->left);
    preorder_traversal_recursive(node->right);
  }
}

static void deleteTreeNode(TreeNode * node){
  TreeNode * auxRight = NULL;
  TreeNode * auxLeft = NULL;

  if(node != NULL){
    auxLeft = node->left;
    auxRight = node->right;

    deleteAccount(node->account);

    free(node);
    
    deleteTreeNode(auxLeft);
    deleteTreeNode(auxRight);
  }

}
void deleteTree(BTree * tree){
  TreeNode * parent = tree->parent;
  if(parent != NULL){
    deleteTreeNode(parent);
  }
  free(tree);
}
