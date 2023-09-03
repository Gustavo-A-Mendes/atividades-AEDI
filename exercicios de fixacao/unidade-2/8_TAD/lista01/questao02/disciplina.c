#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

#define MAX_DISCIPLINA 3

struct disciplina {
    char nome[121];
    int codigo;
};

// int count_disc = 0;

Disciplina *disc_cria(char *nome, int codigo)
{
    Disciplina *disc = (Disciplina *)calloc(1, sizeof(Disciplina));
    if (disc == NULL)
        exit(1);
    else
        printf("\nDisciplina criada com sucesso!\n");

    strcpy(disc->nome, nome);
    disc->codigo = codigo;

    return disc;
}

int disc_codigo(Disciplina *disc)
{
    return disc->codigo;
}

Disciplina *disc_procura(Disciplina **disciplinas, int cod, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (disciplinas[i] != NULL && disciplinas[i]->codigo == cod)
            return disciplinas[i];
    }
    return NULL;
}

void disc_lista(Disciplina **disc, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        printf("\n===== DISCIPLINA %d =====\n", i+1);
        printf("Nome: %s\nCodigo: %d\n", disc[i]->nome, disc[i]->codigo);
    }
}

void disc_exclui(Disciplina *disciplina)
{ 
    free(disciplina);
}
