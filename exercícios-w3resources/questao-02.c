#include <stdio.h>

int main(void) {
  int m = 29;
  printf("\nEndereco de m : %p\n", &m);
  printf("Valor de m : %i\n\n", m);
  
  int *ab = &m;
  printf("Endereco do ponteiro ab : %p\n", &ab);
  printf("Valor do ponteiro ab : %i\n\n", *ab);
  
  m = 34;
  printf("Endereco do ponteiro ab : %p\n", &ab);
  printf("Valor do ponteiro ab : %i\n\n", *ab);

  *ab = 7;
  printf("Endereco do ponteiro m : %p\n", &m);
  printf("Valor do ponteiro m : %i\n\n", m);   

  return 0;
}
