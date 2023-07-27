#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct frutas {
  char nome[31];
  char cor[11];
  char sabor[11];
  int quantidade;
} Frutas;


Frutas **categoriza_frutas(int tamanho) {
  
  Frutas **frutas = (Frutas**)malloc(tamanho*sizeof(Frutas*));
  if (frutas == NULL) exit(1);
  
  int i;
  for (i = 0; i < tamanho; i++) {
      frutas[i] = (Frutas*)malloc(sizeof(Frutas));
  }
  
  for (i = 0; i < tamanho; i++) {

    printf("\n========== FRUTA %d ==========\n", i+1);

    printf("Digite o nome da fruta: ");
    scanf(" %30[^\n]", frutas[i]->nome);

    printf("Digite a cor da fruta: ");
    scanf(" %10[^\n]", frutas[i]->cor);

    printf("Digite o sabor da fruta: ");
    scanf(" %10[^\n]", frutas[i]->sabor);

    printf("Qual a quantidade: ");
    scanf("%d", &frutas[i]->quantidade);
  }
  
  return frutas;
}

void imprime(Frutas **frutas, int tamanho) {

  int i = 0;
  for (i = 0; i < tamanho; i++) {
    printf("\n========== FRUTA %d ==========\n", i+1);
    printf("Nome: %s\t", frutas[i]->nome);
    printf("Cor: %s\t", frutas[i]->cor);
    printf("Sabor: %s\t", frutas[i]->sabor);
    printf("Quantidade: %d\t", frutas[i]->quantidade);
  }
}

Frutas *busca_fruta(Frutas** frutas, int tamanho) {
  
  char nome[31];

  printf("\n\nQual fruta deseja buscar: ");
  scanf(" %30[^\n]", nome);
  

  int i, j, igual;
  for (i = 0; i < tamanho; i++) {
    for (j = 0; nome[j] != '\0'; j++) {
      // printf("%c\t %c\n", nome[j], frutas[i]->nome[j]);
      if (nome[j] != frutas[i]->nome[j]) {
        igual = 0;
        break;
      }
      igual = 1;
    }
    
    if (igual) {
      return frutas[i];
    }
  }
  return NULL;
}

int main(void) {

  int qtd_fruta;
  printf("Insira quantos tipos de frutas sao: ");
  scanf("%d", &qtd_fruta);
  fflush(stdin);

  Frutas **var_frutas = categoriza_frutas(qtd_fruta);

  imprime(var_frutas, qtd_fruta);

  Frutas *fruta_escolhida = busca_fruta(var_frutas, qtd_fruta);

  if (fruta_escolhida != NULL) {
    printf("\nA fruta escolhida foi:\n");
    printf("- Nome: %s \n- Cor: %s \n- Sabor: %s \n- Quantidade: %d ", fruta_escolhida->nome, fruta_escolhida->cor, fruta_escolhida->sabor, fruta_escolhida->quantidade );
  } else {
    printf("\nA fruta nao foi encontrada.\n");
  }

  return 0;
}