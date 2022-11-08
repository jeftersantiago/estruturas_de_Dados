#include "util.h"

struct ITEM{
    int key;
    char* name;
    float value;
};

Item *createItem(int key, const char *name, float value){

    Item* item = (Item *) malloc(sizeof(Item));

    item->name = NULL;
    if(item != NULL){
        item->key = key;
        item->name = (char *) malloc(sizeof(char));
        strcpy(item->name, name);
        item->value = value;
        return item;
    }
    return NULL;
}

boolean deleteItem(Item **item){
    if(*item != NULL){
        (*item)->key = ERROR;
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
}

void printItem(const Item *item){
    if(item != NULL){
        printf("Nome = %s\n", item->name);
        printf("Chave = %d\n", item->key);
        printf("Valor = %f\n", item->value);
    }
}

int getItemKey(const Item *item){
    if(item != NULL) return item->key;
    return ERROR;
}

void setItemKey(Item *item, int key){
    if(item != NULL) item->key = key;
}

int *generateRandomVector(int size, int min, int max){
    int *vec = malloc(sizeof(int) * size);
    srand(time(NULL));
    for(int i = 0; i < size; i++)
        vec[i] = (rand() % (max - min + 1)) + min;
    return vec;
}

void printVector(int* vec, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}
