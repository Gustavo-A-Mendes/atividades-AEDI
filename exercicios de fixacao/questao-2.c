#include <stdio.h>

int main(void) {
  int x, *p;
  x = 100;
  p = &x;
  printf("\nValor de p = %p\tValor de *p = %d", p, *p);
}
