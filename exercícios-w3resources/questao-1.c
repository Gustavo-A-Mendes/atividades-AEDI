#include <stdio.h>

int main(void) {
  int m = 10, n, o;
  int *z = &m;
  
  printf("\nPointer : Mostra a declaracao basica de um ponteiro:\n");
  printf("-------------------------------------------------------\n");
  printf("Aqui m=10, n e o sao duas variaveis inteiras e *z e inteiro\n\n");
  printf("z armazena o endereco de m = %p\n\n", z); // z e um ponteiro entao %p deve imprimir o endereco
  printf("*z armazena o valor de m = %d\n\n", *z);
  printf("&m e o endereco de m = %p\n\n", &m);  // &m da o endereco da variavel inteira m
                             // entao %p e specifier para esse endereco
  printf("&n armazena o endereco de n = %p\n\n", &n);
  printf("&o armazena o endereco de o = %p\n\n", &o);                                                           
  printf("&z armazena o endereco de z = %p\n\n", &z);  // &z da o entedereco, onde o ponteiro z e 
                             // armazenado -> ainda um endereco -> %p e o specifier correto
  return 0;
}