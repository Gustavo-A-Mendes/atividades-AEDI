#include <stdio.h>

/*
  Esse programa é um estudo usando ponteiros de ponteiros
*/

int main(void) {

  // declarando variáveis do tipo inteiro
  int a, b, c, d;
  int *p1;        // declara ponteiro "p1"
  int *p2 = &a;   // declara novo ponteiro "p2" que aponta para o endereço de "a".
  int *p3 = &c;   // declara novo ponteiro "p3" que aponta para o endereço de "c".
  p1 = p2;        // p1 recebe o mesmo endereço que "p2", apontando para "a".
  *p2 = 10;       // valor de "a" recebe 10, que é valor contido no endereço que "p2" aponta recebe.
  b = 20;         // "b" recebe 20.
  int **pp;       // novo ponteiro de ponteiro "pp" declarado.
  pp = &p1;       // "pp" aponta para o ponteiro "p1", que aponta para "a".
  *p3 = **pp;     // valor que "p3" aponta recebe o valor apontado por "pp", ou seja, (c = a = 10)
  int *p4 = &d;   // novo ponteiro "p4" é declarado e aponta para o endereço de "d"
  *p4 = b + (*p1)++;    // "d" recebe o (b + a) -> (20 + 10), enquanto "a" é incrementado em 1 logo em seguida
  
  printf("%d\t%d\t%d\t%d\n", a, b, c, d);
  // ... a=11; b=20; c=10; d=31

  return 0;
}