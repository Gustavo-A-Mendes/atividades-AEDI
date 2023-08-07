#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNC 10

typedef struct funcionario {
  char funcional[3];
  char nome[21];
  char departamento;
  float salario;

} Funcionario;

Funcionario *pessoal[MAX_FUNC];

// protótipo das funções:
void copia_dados(FILE*, int, Funcionario**);
void imprime_folha_pagamento(int, Funcionario**, char);

// variáveis globais:
int i;

int main(void) {
  
  FILE *func = fopen("funcionarios.txt", "rt");
  if (func == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }


  for (i = 0; i < MAX_FUNC; i++) {
    pessoal[i] = (Funcionario*)malloc(sizeof(Funcionario));
  }
  
  copia_dados(func, MAX_FUNC, pessoal);

  imprime_folha_pagamento(3, pessoal, 'A');
  imprime_folha_pagamento(4, pessoal, 'B');
  imprime_folha_pagamento(3, pessoal, 'C');

  // printf("oi\n");
  // for (i = 0; i < MAX_FUNC; i++) {
  //   printf("%s\t%s\t%c\t%.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
  // }
  // float nota1, nota2, nota3, media;
  
  fclose(func);
  
  return 0;
}

void copia_dados(FILE *fl, int n, Funcionario **pessoal) {

  i = 0;
  // Leitura dos dados do arquivo:
  while (!feof(fl)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 

    fscanf(fl, "%s\t%s\t%c\t%f", pessoal[i]->funcional, pessoal[i]->nome, &pessoal[i]->departamento, &pessoal[i]->salario);
    // printf("%d\n", valor[i]);
    i++;

  }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto) {

  float soma = 0;

  printf("FOLHA DE PAGAMENTO DEPTO %c\n", depto);
  printf("%-15s%-15s%-15s%-s\n", "FUNCIONAL", "NOME", "DEPTO", "SALARIO");
  for (i = 0; i < MAX_FUNC; i++) {
    if (pessoal[i]->departamento == depto) {
      printf("%-15s%-15s%-15c%-.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
      soma = soma + pessoal[i]->salario;
    }
  }
  printf("VALOR TOTAL PAGAMENTO: R$ %.2f\n\n", soma);
}