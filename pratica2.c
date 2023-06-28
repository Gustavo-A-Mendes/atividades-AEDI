#include <stdio.h>

int main(void) {

  float var = 2.5;

  // Declaração de ponteiro
  float *ponteiro;
  ponteiro = &var;

  printf("Var = %f \nPonteiro = %p\n", var, ponteiro);

  // Modificar o valor da variável var através do ponteiro
  *ponteiro = 3.7;

  printf("Var = %f \nPonteiro = %p", var, ponteiro);


}