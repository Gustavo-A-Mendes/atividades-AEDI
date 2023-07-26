#include <stdio.h>
#include <stdlib.h>

/*
  Esse programa implementa uma struct Pessoa com parâmetros "nome", "idade" e "genero",
  sendo genero armazenado num tipo enum com valores para MASCULINO e FEMININO.
  O programa, então, lê os dados da pessoa e os imprime.
*/

// declaração do tipo enumerado para o genero: 
typedef enum genero {MASCULINO, FEMININO} Gen;

// declaração do tipo estruturado para pessoa:
typedef struct pessoa {
  char nome[51];
  int idade;
  Gen genero;
} Pessoa;


int main(void) {

  // declara variável do tipo Pessoa:
  Pessoa pessoa;

  // solicita os dados da pessoa:
  printf("Digite o nome da pessoa: ");
  scanf("%50[^\n]", pessoa.nome);
  fflush(stdin); // limpa o buffer de entrada

  printf("Digite a idade: ");
  scanf("%d", &pessoa.idade);

  // compara o genero selecinado com o tipo enum:
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
  
  // imprime os dados da pessoa:
  printf("\nNome: %s\tIdade: %d\tGenero: %s", pessoa.nome, pessoa.idade, genero);

  //libera memória alocada:
  free(genero);

  return 0;
}