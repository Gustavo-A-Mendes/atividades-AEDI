#include <stdio.h>
#include "pilha.c"

int main(void) {

    Pilha *pilha = pilha_cria();
    int n;

    printf("Insira quantos numeros deseja armazenar na pilha: ");
    scanf("%d", &n);
    while (getchar() != '\n');
    
    int i;
    for (i = 0; i < n; i++)
    {
        pilha_push(pilha, i);
    }
    
    pilha_imprime(pilha, 50);

    float valor_pop = pilha_pop(pilha);

    printf("\nValor retirado: %.2f\n", valor_pop);
    
    pilha_imprime(pilha, 50);

    pilha_libera(pilha);

    return 0;
}