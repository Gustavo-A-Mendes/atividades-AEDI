#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

static int N = 50; /* número máximo de elementos */

struct pilha {
    int n;          // contador de elementos da pilha
    float *vet;     // vetor de valores armazenados
};

Pilha *pilha_cria(void)
{
    // Cria a pilha
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) exit(1);
    // atribui 0 ao contador de elementos:
    p->n = 0;
    // aloca espaço do vetor de valores:
    p->vet = (float*)malloc(N*sizeof(float));
    return p;
}

void pilha_push(Pilha *p, float v)
{
    if (p->n == N) { /* capacidade esgotada */
        p->vet = (float*)realloc(p->vet, (2*p->n)*sizeof(float));
        N = 2*N;
    }
    /* insere elemento na próxima posição */
    p->vet[p->n] = v;
    p->n++;
}

float pilha_pop(Pilha *p)
{
    float v;
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);    /* aborta o programa */
    }
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;

    return v;
}

int pilha_vazia(Pilha *p)
{
    return (p->n == 0);
}

void pilha_libera(Pilha *p)
{
    free(p->vet);
    free(p);
}

void pilha_imprime(Pilha *p)
{   
    int i;
    for (i = p->n-1; i >= 0; i--) {
        printf("valor %d: %.1f\n", i, p->vet[i]);
    }
}