#include <stdio.h>

/*
  Programa que manipula dados de uma pessoa e armazena em uma struct
*/

// declaração do tipo estruturado:
typedef struct pessoa {

  char nome[20];
  int idade;
  int RG;
  float altura;

} Pessoa;


int main(void) {
  Pessoa var_pessoa[3];
  
  // laço que solicita dados para preencher struct para cada pessoa e os imprime:
  int i;
  for (i = 0; i < 3; i++) {
    printf("\n====== PESSOA %d ======\n", i+1);


    printf("Digite o nome : ");
    scanf(" %[^\n]", var_pessoa[i].nome);

    printf("Digite a idade: ");
    scanf("%d", &var_pessoa[i].idade);

    printf("Digite o numero do RG: ");
    scanf("%d", &var_pessoa[i].RG);

    printf("Digite a altura: ");
    scanf("%f", &var_pessoa[i].altura);

    printf("Os dados informados:\nIdade: %s\tIdade: %d\tMatricula: %d\tAltura: %.2f\n", var_pessoa[i].nome, var_pessoa[i].idade, var_pessoa[i].RG, var_pessoa[i].altura);
  }

  return 0;
}