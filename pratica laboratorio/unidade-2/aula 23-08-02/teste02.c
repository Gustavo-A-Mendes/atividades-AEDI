#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char nome_arquivo[20];

  float pi = 3.14;
  printf("Informe o nome do arquivo: ");
  scanf(" %[^\n]", nome_arquivo);   // ex.: arquivo.txt
  
  strcat(nome_arquivo, ".txt");    // concatena a extensão ".txt"

  FILE * arquivo = fopen(nome_arquivo, "wt");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  } 
  else printf("Arquivo criado com sucesso!\n");

  fputs("Hello World!!!", arquivo);   // escreve uma string no arquivo
  fputc('A', arquivo);                // escreve um caracter no arquivo
  fprintf(arquivo, "\nAlgoritmo e Estrutura de dados I: %.2f\n", pi); // escreve strings e variáveis em qualquer formatação


  fclose(arquivo);  // fecha o arquivo aberto

  arquivo = fopen(nome_arquivo, "rt");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  } 


  int c;
  while (!feof(arquivo)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    c = fgetc(arquivo);       // lê um caracter do arquivo
    printf("%c", c);
  }
  

  fclose(arquivo);  // fecha o arquivo aberto
  
  return 0;
}