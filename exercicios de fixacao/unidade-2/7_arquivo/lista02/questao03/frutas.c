#include <stdlib.h>
#include <ctype.h>
#include "frutas.h"

#define MAX_FRUTA 5

struct frutas {
  char nome[21];
  float preco;
};

int copia_dados(FILE *fl, Frutas** frutas) {
  int i = 0;
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
      printf("\nErro! Nao ha mais espaco para cadastro de frutas.\n");
      break;
    }
  }

  return i;
}