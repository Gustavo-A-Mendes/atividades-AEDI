#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef union indice {
  float IG, IRA, IRT;
} Indices;

typedef struct aluno {
  char nome[81];
  long int mat;
  char curso[121];
  Indices indice;
} Aluno;


int main(void) {
  
  Aluno * var_aluno = (Aluno*)malloc(sizeof(Aluno));

  printf("\nDigite o nome do aluno: ");
  scanf(" %80[^\n]", var_aluno->nome);
  printf("Digite a matricula: ");
  scanf(" %ld", &var_aluno->mat);
  printf("Digite o nome do curso: ");
  scanf(" %120[^\n]", var_aluno->curso);

  int op;
  printf("\n0 - IG\n1 - IRA\n2 - IRT");
  printf("\nEscolha um dos indices: ");
  scanf("%d", &op);

  switch (op) {
  case 0:
    printf("Digite o IG: \n");
    scanf(" %f", &var_aluno->indice.IG); break;
  case 1:
    printf("Digite o IRA: \n");
    scanf(" %f", &var_aluno->indice.IRA); break;
  case 2:
    printf("Digite o IRT: \n");
    scanf(" %f", &var_aluno->indice.IRT); break;
  default:
    break;
  }

  printf("\nAluno: %s\tMatricula: %ld\tCurso: %s\tIndice: %.2f\n\n", var_aluno->nome, var_aluno->mat, var_aluno->curso, var_aluno->indice.IG);

  free(var_aluno);
  
  return 0;
}