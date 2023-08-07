#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
  char funcional[3];
  char nome[20];
  char departamento;
  float salario;

} Funcionario;


// protótipo das funções:
void copia_dados(FILE*, int, Funcionario**);
void imprime_folha_pagamento(int, Funcionario**, char);

// variáveis globais:
int i;

int main(void) {
  
  int num_func;

  FILE *func = fopen("funcionarios.txt", "rt");
  if (func == NULL) exit(1);

  fscanf(func, "%d", &num_func);
  // printf("%d\n", num_func);

  Funcionario **pessoal = (Funcionario**)malloc(num_func*sizeof(Funcionario*));
  if (pessoal == NULL) exit(1);
  
  copia_dados(func, num_func, pessoal);

  imprime_folha_pagamento(num_func, pessoal, 'A');
  imprime_folha_pagamento(num_func, pessoal, 'B');
  imprime_folha_pagamento(num_func, pessoal, 'C');

  fclose(func);

  for (i = 0; i < num_func; i++) {
    free(pessoal[i]);
  }
  free(pessoal);
  
  return 0;
}

void copia_dados(FILE *fl, int n, Funcionario **pessoal) {
  i = 0;
  while (i < n) {
    // Leitura dos dados do arquivo:
    pessoal[i] = (Funcionario*)malloc(sizeof(Funcionario));
    if (pessoal[i] == NULL) exit(1);
    fscanf(fl, "%3[^\t]\t%21[^\t]\t%c\t%f", pessoal[i]->funcional, pessoal[i]->nome, &pessoal[i]->departamento, &pessoal[i]->salario);
    i++;
  }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto) {

  float soma = 0;

  printf("FOLHA DE PAGAMENTO DEPTO %c\n", depto);
  printf("%-10s\t%-20s\t%-10s\t%-s", "FUNCIONAL", "NOME", "DEPTO", "SALARIO");
  for (i = 0; i < n; i++) {
    if (pessoal[i]->departamento == depto) {
      printf("%-10s\t%-20s\t%-10c\t%-.2f", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
      soma = soma + pessoal[i]->salario;
    }
  }
  printf("\nVALOR TOTAL PAGAMENTO: R$ %.2f\n\n", soma);
}