#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
  char nome[51];
  char nome_saida[121];

  float nota1, nota2, nota3, media;
  
  FILE * arquivo_notas = fopen("entrada_q1.txt", "rt");
  if (arquivo_notas == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

  printf("Digite o nome do arquivo de saida: ");
  scanf("%120s", nome_saida);
  strcat(nome_saida, ".txt");    // concatena a extensão ".txt"

  FILE * saida = fopen(nome_saida, "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  }

  // Leitura dos dados do arquivo e impressão deles em tela:
  while (!feof(arquivo_notas)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    fscanf(arquivo_notas, "%50[^\t]\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3);
    media = (nota1 + nota2 + nota3) / 3;

    fprintf(saida, "%s\t%.1f\t %s", nome, media, (media>=7.0)? "Aprovado" : "Reprovado"); // escreve strings e variáveis em qualquer formatação

    // printf("%s\t%.2f\t%.2f\t%.2f\t\t%.2f", nome, nota1, nota2, nota3);
  }
  
  fclose(arquivo_notas);
  fclose(saida);

  printf("\n");

  saida = fopen(nome_saida, "rt");
  int s;
  while (!feof(saida)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    s = fgetc(saida);       // lê um caracter do arquivo
    printf("%c", s);
  }
  
  return 0;
}
