#include <stdio.h>
#include <stdlib.h>

int main(void) {

  FILE * arquivo = fopen("entrada.txt", "wt");  // abre um arquivo
  if(arquivo == NULL) {
    printf("\nNao foi possivel abrir o arquivo!\n\n");
    exit(1);
  } else {
    printf("\nArquivo criado!\n");
  }

  // int fclose(FILE *fp) fecha um arquivo aberto, e retorna 0 se bem sucedido:
  if (!fclose(arquivo)) {
    printf("\nArquivo fechado com sucesso!");
  }
  
  return 0;
}