#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union type {
  char ALIMENTO[51];
  char BEBIDA[51];
  char ELETRONICO[51];
} Type;

typedef struct produto {

  float preco;
  Type tipo;
  
} Produto;

int main(void) {

  Produto produto;
  
  char nome[51];
  printf("Digite o nome do produto: ");
  scanf("%50[^\n]", nome);
  fflush(stdin);

  int op;
  printf("\n0 - ALIMENTO\n1 - BEBIDA\n2 - ELETRONICO");
  printf("\nInsira o tipo: ");
  scanf("%d", &op);
  fflush(stdin);
  
  char *tipo = (char*)malloc(10*sizeof(char));
  switch (op) {
    case 0:
      strcpy(produto.tipo.ALIMENTO, nome);
      tipo = "ALIMENTO";
      break;
    
    case 1:
      strcpy(produto.tipo.BEBIDA, nome);
      tipo = "BEBIDA";
      break;
    
    case 2:
      strcpy(produto.tipo.ELETRONICO, nome);
      tipo = "ELETRONICO";
      break;
    
    default:
      break;
  }

  printf("Digite o preco: ");
  scanf("%f", &produto.preco);
  
  printf("\nNome: %s\tPreco: %.2f\tTipo: %s", produto.tipo.ALIMENTO, produto.preco, tipo);

  return 0;
}