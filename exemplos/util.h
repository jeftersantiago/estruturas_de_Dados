#ifndef _util_
#define _util_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define boolean char

#define ERROR -1

typedef struct ITEM Item;

Item *createItem(int key, const char *name, float value);
boolean deleteItem(Item **item);
void printItem(const Item *item);
int getItemKey(const Item *item);
void setItemKey(Item *item, int key);

int *generateRandomVector(int size, int min, int max);
void printVector(int* vec, int size);

#endif
