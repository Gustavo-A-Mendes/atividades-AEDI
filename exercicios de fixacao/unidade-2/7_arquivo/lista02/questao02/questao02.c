#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
  
  char nome[31];
  float nota1, nota2, nota3;

};

int main(void) {

  int qtd_alu;
  char nome_arquivo[100];

  printf("\nInforme o nome do arquivo: ");
  scanf(" %[^\n]", nome_arquivo);
  strcat(nome_arquivo, ".txt");

  FILE *saida = fopen(nome_arquivo, "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

  printf("Informe a quantidade de Alunos: ");
  scanf("%d", &qtd_alu);

  Aluno **var_alu = (Aluno**)malloc(qtd_alu*sizeof(Aluno*));
  if (var_alu == NULL) exit(1);

  preenche_dados(var_alu, qtd_alu);

  copia_dados(saida, var_alu, qtd_alu);

  int i;
  for (i = 0; i < qtd_alu; i++) {
    free(var_alu[i]);
  }
  free(var_alu);

  fclose(saida);

  saida = fopen(nome_arquivo, "rt");


  // Leitura do arquivo:
  int s;
  while (!feof(saida)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    s = fgetc(saida);       // lê um caracter do arquivo
    printf("%c", s);
  }
  fclose(saida);
  

  return 0;
}
