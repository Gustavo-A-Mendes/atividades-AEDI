#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

int main(void) {

  int qtd_func;
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

  printf("Informe a quantidade de funcionarios: ");
  scanf("%d", &qtd_func);

  Funcionario **var_func = (Funcionario**)malloc(qtd_func*sizeof(Funcionario*));
  if (var_func == NULL) exit(1);

  preenche_dados(var_func, qtd_func);

  copia_dados(saida, var_func, qtd_func);
  
  int i = 0;
  for (i = 0; i < qtd_func; i++) {
    free(var_func[i]);
  }
  free(var_func);

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