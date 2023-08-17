#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

#define MAX_ALUNO 10

int main(void) {
  int i, count_alu=0;
  char nome_alu[31];
  float nota_alu;

  Aluno **alunos = (Aluno**)malloc(MAX_ALUNO*sizeof(Aluno*));
  if (alunos == NULL) exit(1);

  do {
    printf("\nInforme o nome do aluno: ");
    scanf(" %30[^\n]", nome_alu);
    fflush(stdin);

    printf("Informe a nota do aluno: ");
    scanf("%f", &nota_alu);
    fflush(stdin);

    alunos[count_alu] = aluno_cria(nome_alu, nota_alu);
    count_alu++;
    printf("%d\n",count_alu);
    char test[2];
    printf("\nDeseja continuar [S/N]? ");
    scanf(" %1c", test);
    fflush(stdin);

    if (toupper(test[0]) == 'N') break;

  } while (count_alu < MAX_ALUNO);
  
  for (i = 0; i < count_alu; i++) {
    aluno_imprime(alunos[i]);
  }
  
  aluno_ordena(count_alu, alunos);
  
  char nome_arquivo[51];
  printf("\nInforme o nome do arquivo: ");
  scanf(" %50[^\n]", nome_arquivo);
  fflush(stdin);
  
  strcat(nome_arquivo, ".txt");

  FILE *saida = fopen(nome_arquivo, "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  }

  aluno_salva(saida, count_alu, alunos);

  for (i = 0; i < count_alu; i++){
    free(alunos[i]);
  }
  free(alunos);

  return 0;
}