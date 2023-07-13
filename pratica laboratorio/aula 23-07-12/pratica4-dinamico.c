// Programa que manipula dados de uma pessoa e armazena em uma struct, utilizando ponteiros
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {

  char nome[20];
  int idade;
  int RG;
  float altura;

} Pessoa;


int main(void) {
  Pessoa *var_pessoa = (Pessoa *)malloc(3*sizeof(Pessoa));
  
  int i;
  for (i = 0; i < 3; i++) {
    printf("\n====== PESSOA %d ======\n", i+1);


    printf("Digite o nome : ");
    scanf(" %[^\n]", (var_pessoa+i)->nome);

    printf("Digite a idade: ");
    scanf("%d", &(var_pessoa+i)->idade);

    printf("Digite o numero do RG: ");
    scanf("%d", &(var_pessoa+i)->RG);

    printf("Digite a altura: ");
    scanf("%f", &(var_pessoa+i)->altura);

    printf("Os dados informados:\nIdade: %s\tIdade: %d\tMatricula: %d\tAltura: %.2f\n", (var_pessoa+i)->nome, (var_pessoa+i)->idade, (var_pessoa+i)->RG, (var_pessoa+i)->altura);
  }

  return 0;
}