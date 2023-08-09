#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_FRUTA 5

typedef struct frutas {
  char nome[21];
  float preco;
} Frutas;


int copia_dados(FILE*, Frutas**);

int i, count;

int main(void) {

  Frutas** var_frutas = (Frutas**)malloc(MAX_FRUTA*sizeof(Frutas*));

  FILE *saida = fopen("frutas.txt", "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

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


int copia_dados(FILE *fl, Frutas** frutas) {
  
  fprintf(fl, "%s,%s\n", "NOME", "PRECO");

  while (1) {
    if (i < MAX_FRUTA) {
      int count_fruta = 0;
      char resp[2];

      frutas[i] = (Frutas*)malloc(sizeof(Frutas));

      printf("\n===== Fruta %d =====\n", i+1);
      printf("Insira o nome: ");
      scanf(" %20[^\n]", frutas[i]->nome);
      printf("Insira o preco: ");
      scanf("%f", &frutas[i]->preco);

      fprintf(fl, "%s,%-.2f\n", frutas[i]->nome, frutas[i]->preco);
      i++;
      // printf("%d\n", i);
      if (i < MAX_FRUTA) {
        printf("\nDeseja continuar? [S / N]\n");
        scanf(" %1[^\n]", resp);
        resp[0] = toupper(resp[0]);
        if (resp[0] == 'N') break;
      } else {
        printf("\nNumero maximo de Frutas cadastradas\n");
        break;
      }
    } else {
      printf("\nErro! Não há mais espaço para cadastro de frutas.\n");
      break;
    }
  }

  return i;
}