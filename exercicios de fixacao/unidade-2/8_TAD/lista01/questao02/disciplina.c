#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

#define MAX_DISCIPLINA 10

struct disciplina {
  char nome[121];
  int codigo;
};

int count_disc = 0;

Disciplina *cria_disciplina(char *nome, int codigo) {
  
  Disciplina *disc = (Disciplina*)calloc(1,sizeof(Disciplina));
  if (disc == NULL) exit(1);
  else printf("\nDisciplina criada com sucesso!\n");

  strcpy(disc->nome, nome);
  disc->codigo = codigo;

  return disc;
}

Disciplina *procura_disciplina(Disciplina **disciplinas, int cod, int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (disciplinas[i] != NULL && disciplinas[i]->codigo == cod)
      return disciplinas[i];
  }
  return NULL;
}


void excluir_disciplina(Disciplina* disciplina) {
  free(disciplina);
}
