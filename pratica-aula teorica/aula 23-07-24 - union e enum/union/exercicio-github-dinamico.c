#include <stdio.h>
#include <stdlib.h>

/*
  Estudo com o tipo union (unificado)
*/

// declara constante
#define MAX 100

// declara o tipo unificado para os indices acadêmicos:
typedef union indice {
  float IG, IRA, IRT;
} Indices;

// declara o tipo estruturado para aluno:
typedef struct aluno {
  char nome[81];
  long int mat;
  char curso[121];
  Indices indice;
} Aluno;


int main(void) {

  // aloca memória para variável do tipo Aluno:
  Aluno * var_aluno = (Aluno*)malloc(sizeof(Aluno));

  // solicita os dados do aluno
  printf("\nDigite o nome do aluno: ");
  scanf(" %80[^\n]", var_aluno->nome);
  printf("Digite a matricula: ");
  scanf(" %ld", &var_aluno->mat);
  printf("Digite o nome do curso: ");
  scanf(" %120[^\n]", var_aluno->curso);

  // verifica o índice escolhido:
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

  // imprime os dados:
  printf("\nAluno: %s\tMatricula: %ld\tCurso: %s\tIndice: %.2f\n\n", var_aluno->nome, var_aluno->mat, var_aluno->curso, var_aluno->indice.IG);

  free(var_aluno);
  
  return 0;
}