#ifndef _POKEDEX_
#define _POKEDEX_

typedef struct STATUS Status;
typedef struct ATTACK Attack;
typedef struct POKEMON Pokemon;

Pokemon *newPokemon(const char *name, const char *type1, const char *type2, const int hp,
                    const int attack, const int deffense, const int specialAttack,
                    const int specialDeffense, const int speed);


Attack *newAttack(const char *name, const int powerBase, const float accuracy, const char class);
void addAttack(Pokemon *pokemon, Attack *attack, int index);
void printPokemon(Pokemon *pokemon);
void printAttack(Attack *attack);

#endif
