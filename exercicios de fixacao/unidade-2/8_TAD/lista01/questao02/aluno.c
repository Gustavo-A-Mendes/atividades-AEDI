#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"

#define MAX_ALUNO 3
#define MAX_DISCIPLINA 3

struct aluno
{
    char nome[51];
    int matricula;
    Disciplina *disciplina[MAX_DISCIPLINA];
    int num_disciplina;
};

// int count_alu = 0;

Aluno *alu_cria(char *nome, int matricula)
{
    Aluno *alu = (Aluno *)calloc(1, sizeof(Aluno));
    if (alu == NULL)
        exit(1);
    else
        printf("\nAluno cadastrado com sucesso!\n");

    strcpy(alu->nome, nome);
    alu->matricula = matricula;

    return alu;
}

void alu_matricula(Aluno *aluno, Disciplina *disciplina)
{
    int cod = disc_codigo(disciplina);
    
    if (aluno->num_disciplina < MAX_DISCIPLINA) {
        if (disc_procura(aluno->disciplina, cod, aluno->num_disciplina) == NULL) {
            printf("\noi\n");
            aluno->disciplina[aluno->num_disciplina] = disciplina;
            aluno->num_disciplina++;
            printf("\nAluno matriculado na disciplina %d com sucesso!\n", cod);

        } else {
            printf("\nAluno ja matriculado!\n");
        }
    } else {
        printf("\nAluno ja possui o numero maximo de disciplinas.\n");
    }    
}

Aluno *alu_procura(Aluno **alunos, int mat, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (alunos[i] != NULL && alunos[i]->matricula == mat)
            return alunos[i];
    }
    return NULL;
}

void alu_lista(Aluno **alunos, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        printf("\n===== ALUNO %d =====\n", i+1);
        printf("Nome: %s\nMatricula: %d\nNumero de Disciplinas: %d\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->num_disciplina);
    }
}

void alu_exclui(Aluno *aluno)
{   
    int i;
    for (size_t i = 0; i < aluno->num_disciplina; i++)
    {
        disc_exclui(aluno->disciplina[i]);
    }
    free(aluno);    
}