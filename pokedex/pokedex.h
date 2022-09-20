#ifndef _POKEDEX_
#define _POKEDEX_

typedef struct STATUS {
    int hp;
    int attack;
    int deffense;
    int specialAttack;
    int specialDeffense;
    int speed;
} Status;

typedef struct ATTACK {
    char name[20];
    int powerBase;
    float accuracy;
    // 's' for special, 'p' for physical
    char class;
} Attack;

typedef struct POKEMON {
    char name[50];
    char type1[20];
    char type2[20];
    Status *status;
    Attack *attacks[4];
} Pokemon;


Pokemon *newPokemon(const char *name, const char *type1, const char *type2, const int hp,
                    const int attack, const int deffense, const int specialAttack,
                    const int specialDeffense, const int speed);


Attack *newAttack(const char *name, const int powerBase, const float accuracy, const char class);
void addAttack(Pokemon *pokemon, Attack *attack, int index);
void printPokemon(Pokemon *pokemon);
void printAttack(Attack *attack);

#endif
