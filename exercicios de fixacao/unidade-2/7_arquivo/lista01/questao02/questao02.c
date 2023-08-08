#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// protótipo das funções:
void maiorMenorElemento(int*, int*, int*);

int i = 0;


int main(void) {
  
  char nome_saida[31];

  int valor[10];
  int maior, menor;
  float media = 0;
  
  FILE * arquivo_notas = fopen("entrada_q2.txt", "rt");
  if (arquivo_notas == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

  printf("Digite o nome do arquivo de saida: ");
  scanf("%30s", nome_saida);
  strcat(nome_saida, ".txt");    // concatena a extensão ".txt"

  FILE * saida = fopen(nome_saida, "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  }

  // Leitura dos dados do arquivo:
  while (!feof(arquivo_notas)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 

    fscanf(arquivo_notas, "%d\n", valor+i);
    media = media + valor[i];
        
    // printf("%d\n", valor[i]);
    i++;

  }
  
  media = media / 10;
  
  for (i = 0; i < 10; i++) {
    maiorMenorElemento(valor, &maior, &menor);
  }

  fprintf(saida, "menor elemento: %d\nmaior elemento: %d\nmedia dos elementos: %.2f", menor, maior, media);
  
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

void maiorMenorElemento(int *valores, int *valor_maior, int *valor_menor) {
  int maior = valores[0];
  int menor = valores[0];
  for (i = 0; i < 10; i++) {
    if (valores[i] > maior) maior = valores[i];
    if (valores[i] < menor) menor = valores[i];
  }

  *valor_maior = maior;
  *valor_menor = menor;
}