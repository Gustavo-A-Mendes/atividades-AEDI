#include <stdio.h>
#include <stdlib.h>


typedef enum genero {MASCULINO, FEMININO} Gen;

typedef struct pessoa {
  char nome[51];
  int idade;
  Gen genero;
} Pessoa;

int main(void) {

  Pessoa pessoa;

  printf("Digite o nome da pessoa: ");
  scanf("%50[^\n]", pessoa.nome);
  fflush(stdin);

  printf("Digite a idade: ");
  scanf("%d", &pessoa.idade);


  char *genero = (char*)malloc(10*sizeof(char));
  
  while (1) {
    printf("\n0 - MASCULINO\n");
    printf("1 - FEMININO\n");
    printf("Digite o genero: ");
    scanf("%d", &pessoa.genero);
    fflush(stdin);
    
    if (pessoa.genero == MASCULINO) {
      genero = "MASCULINO";
      break;
    } else if (pessoa.genero == FEMININO) {
      genero = "FEMININO";
      break;
    } else {
      printf("Valor Invalido!\n");
    }

  }
  
  printf("\nNome: %s\tIdade: %d\tGenero: %s", pessoa.nome, pessoa.idade, genero);

  return 0;
}