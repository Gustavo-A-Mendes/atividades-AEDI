#include <stdio.h>

int main() {
  /*
  int num1, num2, sum;
  int (*p)(int, int) = soma;


  printf("Input the first number: ");
  scanf("%i", &num1);
  printf("\nInput the second number:");
  scanf("%i", &num2);

  sum = p(num1, num2);
  printf("\nThe sum of the entered numbers is : %d", sum);
  */

  int num1, num2, sum;
  int *p1 = &num1, *p2 = &num2;

  printf("Input the first number: ");
  scanf("%i", p1);
  printf("\nInput the second number: ");
  scanf("%i", p2);

  sum = *p1 + *p2;

  printf("\nThe sum of the entered numbers is : %d", sum);
   
  return 0;
}