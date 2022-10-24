/*
  Author: Jefter Santiago Mares
  nºUSP: 12559016
 */
#include<stdio.h>
/* Número de opcoes de moedas.*/
#define N_MOEDAS 6
void calculates(int input, int* vec);

int main(){

    int input;
    scanf("%d", &input);
    /* Vetor com a quantidade de moedas para cada opção
       0 -> Moedas de 1 real
       1 -> Moedas de 50 centavos
       2 -> Moedas de 25 centavos
       3 -> Moedas de 10 centavos
       4 -> Moedas de 5 centavos
       5 -> Moedas de 1 centavo
    */
    int out[N_MOEDAS];
    calculates(input, out);
    printf("O valor consiste em %d moedas de 1 real\n"
        "O valor consiste em %d moedas de 50 centavos\n"
        "O valor consiste em %d moedas de 25 centavos\n"
        "O valor consiste em %d moedas de 10 centavos\n"
        "O valor consiste em %d moedas de 5 centavos\n"
        "O valor consiste em %d moedas de 1 centavo\n",
        out[0], out[1], out[2], out[3], out[4], out[5]);

    return 0;
}
/*
  Calcula quantidade minima de moedas de troco a partir de um
  valor de entrada em centavos.
  int aux: Valor em centavos
  int* vec: Vetor com a quantidade de cada opção de moedas.
*/
void calculates(int aux, int* vec){
    int cents[] = {100, 50, 25, 10, 5, 1};
    for(int i = 0; i < N_MOEDAS; i++){
        int mod = aux % cents[i];
        if(mod - aux != 0){
            vec[i] = (aux - mod) / cents[i];
            aux = mod % cents[i];
            mod = aux;
        }
        else vec[i] = 0;
    }
}
