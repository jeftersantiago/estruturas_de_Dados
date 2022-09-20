#include<stdio.h>
#include<stdlib.h>
#include "pokedex.h"

int main(){

    // Pokemon
    char name[50];
    char type1[20];
    char type2[20];
    int hp;
    int deffense;
    int attack;
    int specialAttack;
    int specialDeffense; 
    int speed;

    // Ataque
    int pokPosition;
    int attackPosition;
    char nameAttack[20];
    int powerBase;
    float accuracy;
    char class;
    
    int n_elements = 5;
    Pokemon **pokemon = (Pokemon **) malloc(n_elements * sizeof(Pokemon*));

    Attack *nAttack = NULL;

    int option = -1;

    int i = 0; // nao
    int key = 0;
    int indexPokemon;
    int indexAttack;

    while(option != 0){

        scanf("%d", &option);
//        option = 0;

        if(option == 1){

            if(key == n_elements){
                n_elements *= 2;
                pokemon = (Pokemon **) realloc(pokemon, sizeof(Pokemon*) * n_elements);
            }

            scanf("%s\n", name);
            scanf("%s\n", type1);
            scanf("%s\n", type2);
            scanf("%d\n", &hp);
            scanf("%d\n", &attack);
            scanf("%d\n", &deffense);
            scanf("%d\n", &specialAttack);
            scanf("%d\n", &specialDeffense);
            scanf("%d\n", &speed);

            *(pokemon + key) = newPokemon(name, type1, type2, hp, attack,
                                    deffense, specialAttack, specialDeffense, speed);
            key++;
        }
        // adicionar ataque
        if (option == 2){

            scanf("%d\n%d\n", &pokPosition, &attackPosition);
            scanf("%d\n", &pokPosition);
            scanf("%d\n", &attackPosition);

            scanf("%s\n", nameAttack);
            scanf("%d\n", &powerBase);
            scanf("%f\n", &accuracy);
            scanf("%c\n", &class);

            nAttack = newAttack(nameAttack, powerBase, accuracy, class);
            addAttack(*(pokemon + pokPosition), nAttack, attackPosition);
        }
        // retorna info do pokemon
        if (option == 3){
            scanf("%d",&indexPokemon);
            printPokemon(pokemon[indexPokemon]);
            printf("\n");
        }
        // retorna info do ataque de um pokemon
        if (option == 4){
            scanf("%d",&indexPokemon);
            scanf("%d",&indexAttack);
            printAttack(getAttack(pokemon[indexPokemon],indexAttack));
            printf("\n");
        }
        i++;
    }

    free(nAttack);
    free(pokemon);
    return 0;
}
