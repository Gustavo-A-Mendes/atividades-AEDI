#include <stdio.h>
#include "pilha.h"

int main(void) {

    Pilha *pilha = pilha_cria();

    int i;
    for (i = 0; i < 50; i++)
    {
        pilha_push(pilha, i);
    }
    
    pilha_imprime(pilha, 50);

    float valor_pop = pilha_pop(pilha);

    printf("\nValor retirado: %.2f\n", valor_pop);
    
    pilha_imprime(pilha, 50);


    return 0;
}