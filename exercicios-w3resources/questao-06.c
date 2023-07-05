#include <stdio.h>

// Esse código imprime o maior valor inserido
int numeroMaximo(int *, int *);

int main(void) {
  int num1, num2, maximo;
  int *p1 = &num1, *p2 = &num2;

  printf("Digite o primeiro numero: ");
  scanf("%i", p1);
  printf("Digite o segundo numero:");
  scanf("%i", p2);

  maximo = numeroMaximo(p1, p2);

  printf("\n%d e o numero maximo", maximo);
  
  return 0;
}

int numeroMaximo(int *n1, int *n2) {
  if (*n1 > *n2) {
    return *n1;
  } else if (*n1 < *n2) {
    return *n2;
  } else {
    return *n1;
  }
}
