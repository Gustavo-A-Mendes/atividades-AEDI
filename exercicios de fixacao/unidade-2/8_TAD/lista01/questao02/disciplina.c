#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

#define MAX_DISCIPLINA 10

struct disciplina {
  char nome[121];
  int codigo;
};

Disciplina *disciplinas[MAX_DISCIPLINA];

Disciplina *cria_disciplina(char *nome, int codigo) {
  
  Disciplina *disc = (Disciplina*)malloc(sizeof(Disciplina));
  if (disc == NULL) exit(1);
  else printf("\nDisciplina criada com sucesso!\n");

  strcpy(disc->nome, nome);
  disc->codigo = codigo;

  return disc;
}

Disciplina *procura_disciplina(Disciplina **disciplinas, int cod) {
  int i;
  for (i = 0; i < MAX_DISCIPLINA; i++) {
    if (disciplinas[i] != NULL && disciplinas[i]->codigo == cod)
      return disciplinas[i];
  }
  printf("\nNao foi encontrada nenhuma disciplina com essa codigo\n");
  return NULL;
}


void excluir_disciplina(Disciplina* disciplina) {
  free(disciplina);
}
