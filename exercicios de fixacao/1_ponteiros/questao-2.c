#include <stdio.h>

/*
  Esse programa é um estudo utilizando ponteiros
*/

int main(void) {
  
  // declarando variáveis e ponteiro do tipo inteiro
  int x, *p;

  x = 100;  // x é inicializado com valor 100
  p = &x;   // p recebe o endereço de x.

  printf("\nValor de p = %p\tValor de *p = %d", p, *p);
  // ... p = &x;  *p = 100
}
