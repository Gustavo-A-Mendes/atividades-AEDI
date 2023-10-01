#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"
#include "calc.h"

struct calc {
    char f[21]; /* formato para impressão */
    Pilha *p;   /* pilha de operandos */
};

Calc *calc_cria(char *formato)
{
    Calc *c = (Calc*)malloc(sizeof(Calc));
    strcpy(c->f, formato);
    c->p = pilha_cria();
    return c;
}

void calc_operando(Calc *c, float v)
{
    /* empilhando operandos */
    pilha_push(c->p, v);
    /* imprime topo da pilha */
    printf(c->f, v);
}

void calc_operador(Calc *c, char op)
{
    float v1, v2, v = 0;
    /* desempilha operandos */
    if (pilha_vazia(c->p))
        v2 = 0.0;
    else
        v2 = pilha_pop(c->p);

    if (pilha_vazia(c->p))
        v1 = 0.0;
    else
        v1 = pilha_pop(c->p);

    /* faz operação */
    switch (op)
    {
        case '+':   v = v1+v2;  break;
        case '-':   v = v1-v2;  break;
        case '*':   v = v1*v2;  break;
        case '/':   
            if (v2 !=0) v = v1/v2;
            else {
                printf("\nErro!\n");
                return;
            } 
            break;
        default:    break;
    }

    /* empilha resultado */
    pilha_push(c->p, v);
    /* imprime topo da pilha */
    printf(c->f, v);
}

void calc_libera(Calc *c)
{
    pilha_libera(c->p);
    free(c);
}