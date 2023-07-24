#include <stdio.h>


typedef union documentos {
  long int cpf;
  long int rg;
  long int cnh;
} Docs;


int main(void) {
  Docs documento;

  printf("\nDigite o CPF: ");
  scanf("%ld", &documento.cpf);
  printf("Digite o RG: ");
  scanf("%ld", &documento.rg);
  printf("Digite a CNH: ");
  scanf("%ld", &documento.cnh);
  printf("CPF: %ld\tRG: %ld\tCNH: %ld", documento.cpf, documento.rg, documento.cnh);

  return 0;
}