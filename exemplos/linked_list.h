#ifndef _linked_list
#define _linked_list

#include "util.c"

typedef struct LIST list;

list *create_list(void);
void insert(list *l, Item *item);

Item *linear_search(list *l, int key);



#endif

