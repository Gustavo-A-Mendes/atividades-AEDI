#include <stdio.h>
#include <stdlib.h>
#include "lista.c"
#include "fila.h"

struct _fila {
    Lista *ini;
    Lista *fim;
};

Fila* fila_cria(void)
{
    Fila *Q = (Fila*)malloc(sizeof(Fila));

    Q->ini = NULL;
    Q->fim = NULL;
    // Q->ini->prox = Q->fim->prox = NULL;

    return Q;
}

void fila_libera(Fila **Q)
{
    Fila *Qaux = *Q;
    lst_libera((Qaux)->ini);
    lst_libera((Qaux)->fim);
    free(Qaux);
    *Q = NULL;
}

void fila_insere(Fila *Q, int elem)
{
    Lista *Laux = (Lista*)calloc(1,sizeof(Lista));
    Laux->info = elem;
    Laux->prox = NULL;

    if (Q->ini == NULL) {
        Q->fim = Laux;
        Q->ini = Q->fim;
    } else {
        Q->fim->prox = Laux;
        Q->fim = Laux;
    }
}

float fila_retira(Fila *Q)
{
    if (Q->ini == NULL)
    {
        printf("Warning: Fila esta vazia.\n");
        return 0;   // falha na remoção
    }
    Lista *t = Q->ini;
    float v;

    v = t->info;
    Q->ini = t->prox;
    free(t);
    return v;   // sucesso na remoção
}

int fila_consulta(Fila *Q, int *elem)
{
    if (Q->ini == NULL)
    {
        printf("Warning: Fila esta vazia.\n");
        return 0;   // falha ao consultar fila
    }
    else
    {
        *elem = Q->ini->info;
        return 1;   // sucesso ao consultar fila
    } 
}

void fila_imprime(Fila *Q)
{
    printf("\nInicio da Fila\n-->\n");
    Lista *l;
    for (l = Q->ini; l != NULL; l = l->prox) {
        printf("%.2f\n", l->info);
    }
    printf("<--\nFim da Fila\n");
    
}