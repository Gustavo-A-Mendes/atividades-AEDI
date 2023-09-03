#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

#define MAX_ALUNO 10

struct aluno {
  char nome[31];
  float nota;
};

Aluno *aluno_cria(char *nome, float nota)
{
  Aluno *alu = (Aluno*)malloc(sizeof(Aluno));
  if (alu == NULL) exit(1);

  strcpy(alu->nome, nome);
  alu->nota = nota;

  printf("\nAluno cadastrado com sucesso!\n");
  return alu;
}

void aluno_libera(Aluno* a)
{
  free(a);
}

void aluno_imprime(Aluno* a)
{
  printf("\nInformacoes do Aluno:\n");
  printf("Nome: %s\n", a->nome);
  printf("Nota: %.2f\n", a->nota);
  printf("\n");
}

int confere_ordem(char* nome1, char* nome2)
{
  return strcmp(strupr(nome1), strupr(nome2));
}

void aluno_ordena(int n, Aluno** v)
{
  Aluno *alu_teste;
  
  int i, j;
  for (i = 1; i < n; i++) {
    alu_teste = v[i];
    j = i - 1;

    while (j >= 0 && confere_ordem(v[j]->nome, alu_teste->nome) == 1) {
        v[j+1] = v[j];
        j -= 1;
    }
    v[j + 1] = alu_teste;
  }
}

void aluno_salva(FILE* fl, int n, Aluno** v)
{
  int i;
  for (i = 0; i < n; i++) {
    fprintf(fl, "%-30s\t%.2f\n", v[i]->nome, v[i]->nota);
  } 
}
