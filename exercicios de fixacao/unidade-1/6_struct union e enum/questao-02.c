#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Esse programa implementa uma struct Produto com parâmeros "preco" e "tipo",
  sendo tipo armazena numa union com três categorias, onde armazenam o nome do produto.
  Por fim, o programa imprime os dados do produto.
*/

// declaração do tipo unificado para o tipo: 
typedef union type {
  char ALIMENTO[51];
  char BEBIDA[51];
  char ELETRONICO[51];
} Type;

// declaração do tipo estruturado para o produto:
typedef struct produto {

  float preco;
  Type tipo;
  
} Produto;


int main(void) {

  // declara variável do tipo Produto:
  Produto produto;
  
  // declara variável que armazena o nome do produto:
  char nome[51];

  printf("Digite o nome do produto: ");
  scanf("%50[^\n]", nome);
  fflush(stdin);

  // verificação do tipo selecionado:
  int op;
  printf("\n0 - ALIMENTO\n1 - BEBIDA\n2 - ELETRONICO");
  printf("\nInsira o tipo: ");
  scanf("%d", &op);
  fflush(stdin);
  
  char *tipo = (char*)malloc(10*sizeof(char));
  if (tipo == NULL) exit(1);
  
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
  
  // imprime os dados do produto:
  printf("\nNome: %s\tPreco: %.2f\tTipo: %s", produto.tipo.ALIMENTO, produto.preco, tipo);

  // libera memória alocada
  free(tipo);

  return 0;
}