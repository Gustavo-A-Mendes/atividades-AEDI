// Programa que manipula uma struct
#include <stdio.h>

typedef struct aluno {

  char nome[20];
  int idade;
  int matricula;
  
} Aluno;

// typedef struct aluno Aluno;

int main(void) {
  Aluno var_aluno;

  printf("Digite o nome: ");
  scanf(" %[^\n]", var_aluno.nome);

  printf("Digite a idade: ");
  scanf(" %d", &var_aluno.idade);

  printf("Digite a matricula: ");
  scanf(" %d", &var_aluno.matricula);

  printf("Os dados informados:\nIdade: %s\tIdade: %d\tMatricula: %d", var_aluno.nome, var_aluno.idade, var_aluno.matricula);


  return 0;
}