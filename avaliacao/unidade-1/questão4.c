#include <stdio.h>
#include <stdlib.h>

typedef struct professor {
  char nome[81];
  char disciplina[121];
  int horas_trabalho;
} Professor;

Professor *preenche_dados(Professor *dados) {
  
  printf("Digite o nome do professor: ");
  scanf (" %80[^\n]", dados->nome);

  printf("Digite o nome da disciplina: ");
  scanf (" %120[^\n]", dados->disciplina);

  printf("Digite a quantidade de horas de trabalho: ");
  scanf ("%d", &dados->horas_trabalho);

  return dados;
}

void imprime_dados(Professor *dados) {

  printf("Nome: %s\tDisciplina: %s\t Regime de Trabalho: %d\n", dados->nome, dados->disciplina, dados->horas_trabalho);
}


int main(void) {

  Professor *dados_professor = (Professor*)malloc(sizeof(Professor));
  if(dados_professor == NULL) exit(1);
  
  dados_professor = preenche_dados(dados_professor);  

  imprime_dados(dados_professor);

  free(dados_professor);

  return 0;
}
