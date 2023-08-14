#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct aluno {
  char nome[31];
  float nota1, nota2, nota3;
};

void preenche_dados(Aluno** alu, int num_alu) {
  int i;
  for (i = 0; i < num_alu; i++) {
    
    alu[i] = (Aluno*)malloc(sizeof(Aluno));

    printf("\n===== Aluno %d =====\n", i+1);

    printf("Insira o nome: ");
    scanf(" %30[^\n]", alu[i]->nome);
    printf("Insira a primeira nota: ");
    scanf("%f", &alu[i]->nota1);
    printf("Insira a segunda nota: ");
    scanf("%f", &alu[i]->nota2);
    printf("Insira a terceira nota: ");
    scanf("%f", &alu[i]->nota3);   
  }
}

void copia_dados(FILE *fl, Aluno **func, int num_func) {
  int i;
  fprintf(fl, "%-30s\t%-10s\t%-10s\t%-s\n", "NOME", "NOTA P1", "NOTA P2", "NOTA P3");

  for (i = 0; i < num_func; i++)  {
    fprintf(fl, "%-30s\t%-10.1f\t%-10.1f\t%-.1f\n", func[i]->nome, func[i]->nota1, func[i]->nota2, func[i]->nota3);
  }
}