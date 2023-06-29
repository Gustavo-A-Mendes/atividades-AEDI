#include <stdio.h>

long soma (int *, int *); // por que usar ?

int main(void) {
  int num1, num2, sum;
  int *p1 = &num1, *p2 = &num2;

  printf("Input the first number: ");
  scanf("%i", p1);
  printf("Input the second number:");
  scanf("%i", p2);

  sum = soma(p1, p2);

  printf("\nThe sum of %d and %d is : %d", num1, num2, sum);
  
  return 0;
}

long soma (int *n1, int *n2) {
  long sum = *n1 + *n2;
  return sum;
}
