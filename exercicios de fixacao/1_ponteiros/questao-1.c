#include <stdio.h>

/*
  Esse programa é um estudo de ponteiro
*/

int main (void) {

  // declarando variáveis do tipo inteiro
  int x, y;
  // declarando variáveis do tipo ponteiro para inteiro.
  int *p;

  
  y = 0;
  p = &y;   // p armazena o endereço de y
  x = *p;   // x recebe o valor contido no endereço que p armazena (y = 0)
  x = 4;    // o valor de x é alterado
  (*p)++;   // o valor contido no endereço apontado por p é incrementado
  --x;      // o valor de x é decrementado
  (*p) += x;  // o valor contido no endereço apontado por p é incrementado com o valor de x

  printf("\n%d\t%d\t%d", x, y, *p);
  // ... x=3; y=4; *p=4
}