#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

#define MAX_ALUNO 10

struct aluno {
  char nome[31];
  float nota;
};


Aluno *aluno_cria(char *nome, float nota) {
  Aluno *alu = (Aluno*)malloc(sizeof(Aluno));
  if (alu == NULL) exit(1);

  strcpy(alu->nome, nome);
  alu->nota = nota;

  printf("\nAluno cadastrado com sucesso!\n");
  return alu;
}


void aluno_libera(Aluno* a) {
  free(a);
}


void aluno_imprime(Aluno* a) {
  printf("\nInformacoes do Aluno:\n");
  printf("Nome: %s\n", a->nome);
  printf("Nota: %.2f\n", a->nota);
  printf("\n");
}


void aluno_ordena(int n, Aluno** v) {
  Aluno *alu_teste;
  
  int i, j;
  for (i = 0; i < n; i++) {
    // alu_teste = v[i];
    for (j = 0; j < n; j++) {
      if (confere_ordem(v[j]->nome, v[i]->nome)) {
        alu_teste = v[i];
        v[i] = v[j];
        v[j] = alu_teste;
      }
    }    
  }
}


void aluno_salva(FILE* fl, int n, Aluno** v) {
  int i;
  for (i = 0; i < n; i++) {
    fprintf(fl, "%-30s\t%.2f\n", v[i]->nome, v[i]->nota);
  } 
}


int confere_ordem(char* nome1, char* nome2) {
  int i, ch1, ch2;
  for (i = 0; (nome1[i] != '\0') && (nome2[i] != '\0'); i++) {
    ch1 = toupper(nome1[i]);
    ch2 = toupper(nome2[i]);
    
    if (ch1 < ch2) return 0;        // nome1 vem antes que nome2
    else if (ch1 > ch2) return 1;   // nome2 vem antes que nome1
    // Caso contrário, o loop continua
  }
  return 0;
}
