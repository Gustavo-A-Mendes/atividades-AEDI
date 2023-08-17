#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "disciplina.h"
#include "disciplina.c"
#include "aluno.h"

#define MAX_ALUNO 10

struct aluno {
  char nome[51];
  int matricula;
  Disciplina *disciplina;
  int num_disciplina;
};

Aluno *alunos[MAX_ALUNO];

Aluno *cria_aluno(char *nome, int matricula){  
  Aluno *alu = (Aluno*)malloc(sizeof(Aluno));
  if (alu == NULL) exit(1);
  else printf("\nAluno cadastrado com sucesso!\n");

  strcpy(alu->nome, nome);
  alu->matricula = matricula;

  return alu;
}

void matricula_disciplina(Aluno *alu, Disciplina *disciplina) {
  
  alu->disciplina = disciplina;
  alu->num_disciplina++;
  printf("\nAluno matriculado na disciplina de %s!\n", alu->disciplina->nome);

}

void exclui_aluno(Aluno* aluno) {


}