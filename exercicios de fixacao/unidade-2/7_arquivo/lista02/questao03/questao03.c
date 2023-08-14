#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "frutas.h"
// #include "frutas.c"

int main(void) {

  Frutas** var_frutas = (Frutas**)malloc(5*sizeof(Frutas*));

  FILE *saida = fopen("frutas.txt", "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

  int i, count;
  
  count = copia_dados(saida, var_frutas);
  for (i = 0; i < count; i++) free(var_frutas[i]);
  free(var_frutas);

  fclose(saida);



  // Leitura do arquivo:
  printf("\n");
  
  saida = fopen("frutas.txt", "rt");
  int s;
  while (!feof(saida)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    s = fgetc(saida);       // lê um caracter do arquivo
    printf("%c", s);
  }
  
  printf("\nTodas as frutas foram cadastradas.\nObrigado por usar nosso programa.\n");
  
  fclose(saida);
  
  return 0;
}