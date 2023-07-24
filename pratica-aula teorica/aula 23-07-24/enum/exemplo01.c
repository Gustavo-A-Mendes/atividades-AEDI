#include <stdio.h>

// #define TRUE 1
// #define FALSE 0

/* Enumeração (Enum) */

typedef enum bool {
  false,
  true
} Bool;

int main(void) {

  Bool val;
  printf("Digite 0 ou 1: ");
  scanf("%d", &val);

  if (val == true) {
    printf("\nVerdadeiro.\n");
  } else if (val == false) {
    printf("\nFalso.\n");
  } else {
    printf("\nValor invalido!\n"); // Nunca deve acontecer!
  }

  return 0;
}