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

int count_alu = 0;

Aluno *cria_aluno(char *nome, int matricula){  
  Aluno *alu = (Aluno*)calloc(1,sizeof(Aluno));
  if (alu == NULL) exit(1);
  else printf("\nAluno cadastrado com sucesso!\n");

  strcpy(alu->nome, nome);
  alu->matricula = matricula;

  return alu;
}

void matricula_disciplina(Aluno *aluno, Disciplina *disciplina) {
  int i, jaCursado = 0;
  for (i = 0; i < aluno->num_disciplina; i++) {
    if (disciplina->codigo == aluno->disciplina[i].codigo) {
      printf("Disciplina ja foi cursada!\n");
      jaCursado = 1;
      break;
    }
    jaCursado = 0;
  }

  if (!jaCursado) {
    aluno->disciplina = disciplina;
    aluno->num_disciplina++;
    printf("\nAluno matriculado na disciplina de %s!\n", aluno->disciplina->nome);
  }
}


Aluno *procura_aluno(Aluno **alunos, int mat, int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (alunos[i] != NULL && alunos[i]->matricula == mat)
      return alunos[i];
  }
  return NULL;
}


void lista_alunos(Aluno **alunos, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("\n===== ALUNO %d =====\n", i);
    printf("Nome: %s\nMatricula: %d\nNumero de Disciplinas: %d\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->num_disciplina);
  }
  
}


void exclui_aluno(Aluno* aluno) {


}