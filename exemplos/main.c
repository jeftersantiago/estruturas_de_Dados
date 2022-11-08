#include "util.h"
#include "stack.h"
#include "linked_list.h"
#include "btree.h"

int main(){

//    Stack *stack = createStack();

//    stackItems (stack, item);

//    b_tree *tree = create_b_tree();

    Item *item = createItem(1, "test", 3.1);
//    Item *item2 = createItem(2, "test2", 9.1);
//    Item *item3 = createItem(3, "test3", 1.1);

    list *l = create_list();

    insert_list(l, item);


    return 0;
}








