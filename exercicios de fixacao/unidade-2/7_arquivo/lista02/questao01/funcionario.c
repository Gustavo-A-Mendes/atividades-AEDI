#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

struct funcionario {
  int id;
  char nome[31];
  float salario;
};

void preenche_dados(Funcionario** func, int num_func) {
  int i;
  for (i = 0; i < num_func; i++) {
    
    func[i] = (Funcionario*)malloc(sizeof(Funcionario));

    printf("\n===== FUNCIONARIO %d =====\n", i+1);

    printf("Insira o ID: ");
    scanf("%d", &func[i]->id);
    printf("Insira o nome: ");
    scanf(" %30[^\n]", func[i]->nome);
    printf("Insira o salario do funcionario: ");
    scanf("%f", &func[i]->salario);
  }
}

void copia_dados(FILE *fl, Funcionario **func, int num_func) {
  int i;
  fprintf(fl, "%-5s\t%-35s\t%-s\n", "ID", "NOME", "SALARIO");
  for (i = 0; i < num_func; i++)  {
    fprintf(fl, "%-5d\t%-35s\t%-.2f\n", func[i]->id, func[i]->nome, func[i]->salario);
  }
}