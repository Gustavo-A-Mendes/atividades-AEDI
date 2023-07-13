// Programa que manipula uma struct usando ponteiro
#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina {
  char nome[30];
  float nota;
} Disciplina;

typedef struct aluno {

  char nome[20];
  int matricula;
  Disciplina *disciplina;
  
} Aluno;


int i;
Aluno *cadastra_aluno(void);

int main(void) {
  
  Aluno *aluno = cadastra_aluno();
  
  
  printf("\nOs dados do aluno informados:\nNome: %s\tMatricula: %d", aluno->nome, aluno->matricula);
  printf("\nOs dados da disciplina informados:\n");
  for (i = 0; i < 3; i++) {
    printf("\nNome: %s\tNota: %.1f", (aluno->disciplina+i)->nome, (aluno->disciplina+i)->nota);
  }

  free(aluno);

  return 0;
}

Aluno *cadastra_aluno(void) {
  
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if (aluno==NULL) {
    printf("Erro na alocacao de memoria.\n");
    exit(1);
  }
  aluno->disciplina =(Disciplina*)malloc(3*sizeof(Disciplina));
  if (aluno->disciplina==NULL) {
    printf("Erro na alocacao de memoria.\n");
    exit(1);
  }

  printf("Digite o nome: ");
  scanf(" %[^\n]", (*aluno).nome);  // aluno->nome

  printf("Digite a matricula: ");
  scanf("%d", &aluno->matricula);
  
  for (i = 0; i < 3; i++) {
    printf("Digite o nome da disciplina %d: ", i+1);
    scanf(" %[^\n]", (aluno->disciplina+i)->nome);

    printf("Digite a nota da disciplina %d: ", i+1);
    scanf("%f", &(aluno->disciplina+i)->nota);
  }

  return aluno;
}