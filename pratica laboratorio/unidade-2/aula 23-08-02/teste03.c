#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  int c;
  
  char entrada[121];
  char saida[121];
  FILE * e;
  FILE * s;

  printf("Digite o nome do arquivo de entrada: ");
  scanf("%120s", entrada);
  strcat(entrada, ".txt");    // concatena a extensão ".txt"
  
  printf("Digite o nome do arquivo de saida: ");
  scanf("%120s", saida);
  strcat(saida, ".txt");    // concatena a extensão ".txt"

  e = fopen(entrada, "rt");
  if (e == NULL) {
    printf("Não foi possível abrir o arquivo!");
    return 1;
  }

  s = fopen(saida, "wt");
  if (s == NULL) {
    printf("Não foi possível abrir o arquivo!");
    fclose(e);
    return 1;
  }

  while ((c = fgetc(e)) != EOF) {
    fputc(toupper(c), s);
  }

  fclose(e);
  fclose(s);
  
  s = fopen(saida, "rt");

  int d;
  while (!feof(s)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    d = fgetc(s);       // lê um caracter do arquivo
    printf("%c", d);
  }

  

  return 0;
}