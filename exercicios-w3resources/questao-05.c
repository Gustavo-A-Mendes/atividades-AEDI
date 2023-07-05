#include <stdio.h>

long soma (long *, long *); // protótipo da função declarada após o main

long main(void) {
  long num1, num2, sum;
  long *p1 = &num1, *p2 = &num2;

  printf("Digite o primeiro numero: ");
  scanf("%d", p1);
  printf("Digite o segundo numero: ");
  scanf("%d", p2);

  sum = soma(p1, p2);

  printf("\nA soma de %d e %d e igual : %d", num1, num2, sum);
  
  return 0;
}

long soma (long *n1, long *n2) {
  long sum = *n1 + *n2;

  return sum;
}
