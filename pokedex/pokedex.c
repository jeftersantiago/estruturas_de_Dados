#include "pokedex.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct STATUS {
    int hp;
    int attack;
    int deffense;
    int specialAttack;
    int specialDeffense;
    int speed;
};

struct ATTACK {
    char name[20];
    int powerBase;
    float accuracy;
    // 's' for special, 'p' for physical
    char class;
};

struct POKEMON {
    char name[50];
    char type1[20];
    char type2[20];
    Status *status;
    Attack *attacks[4];
};

Status *newStatus(const int hp, const int attack, const int deffense, const int specialAttack,
                   const int specialDeffense, const int speed){
    Status *status = (Status *) malloc(sizeof(Status));
    status->hp = hp;
    status->attack = attack;
    status->deffense = deffense;
    status->specialAttack = specialAttack;
    status->specialDeffense = specialDeffense;
    status->speed = speed;
    return status;
}

Pokemon *newPokemon(const char *name, const char *type1, const char *type2, const int hp,
                    const int attack, const int deffense, const int specialAttack,
                    const int specialDeffense, const int speed ){
    Pokemon *pokemon = (Pokemon *) malloc(sizeof(Pokemon));
    strcpy(pokemon->name, name);
    strcpy(pokemon->type1, type1);
    strcpy(pokemon->type2, type2);
    pokemon->status = newStatus(hp, attack, deffense, specialAttack, specialDeffense, speed);
    return pokemon;
}
Attack *newAttack(const char *name, const int powerBase, const float accuracy, const char class){
    Attack *attack = (Attack *) malloc(sizeof(Attack));
    strcpy(attack->name, name);
    attack->powerBase = powerBase;
    attack->accuracy = accuracy;
    attack->class = class;
    return attack;
}
Attack *getAttack(const Pokemon *pokemon, int index){
    return pokemon->attacks[index];
}
Status *getStatus(const Pokemon *pokemon){
    return pokemon->status;
}

void removePokemons(Pokemon **pokemon, const int amount){
    for(int i = 0; i < amount; i++){
        free(getStatus(pokemon[i]));
        for(int j = 0; j < 4; j++){
            if(getAttack(pokemon[i], j) != NULL){
                free(getAttack(pokemon[i], j));
            }
        }
        free(pokemon[i]);
    }
    free(pokemon);
}

void addAttack(Pokemon *pokemon, Attack *attack, int index){
    pokemon->attacks[index] = attack;
}
void printPokemon(Pokemon *pokemon){
    printf("Nome do Pokemon: %s\n", pokemon->name);
    printf("Tipo primario: %s\n", pokemon->type1);
    printf("Tipo secundario: %s\n", pokemon->type2);
    printf("Status:\n");
    printf("\tHP: %d\n", pokemon->status->hp);
    printf("\tAtaque: %d\n", pokemon->status->attack);
    printf("\tDefesa: %d\n", pokemon->status->deffense);
    printf("\tAtaque Especial: %d\n", pokemon->status->specialAttack);
    printf("\tDefesa Especial: %d\n", pokemon->status->specialDeffense);
    printf("\tVelocidade: %d\n", pokemon->status->speed);
}
void printAttack(Attack *attack){
    printf("Nome do Ataque: %s\n", attack->name);
    printf("Poder base: %d\n", attack->powerBase);
    printf("Acuracia: %f\n", attack->accuracy);
    printf("Classe: %c\n", attack->class);
}
