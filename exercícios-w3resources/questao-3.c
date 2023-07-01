#include <stdio.h>

int main(void) {
  int m = 300, *pm = &m;
  float fx = 300.600006, *pf = &fx;
  char cht = 'z', *pc = &cht;

  printf("\nPointer : Demonstra o uso do operador & e * : \n");   
  printf("--------------------------------------------------------\n");
  printf("m = %d\n", m);
  printf("fx = %f\n", fx);
  printf("cht = %c\n\n", cht);
  
  printf("Usando o operador & :\n");
  printf("-----------------------\n");
  printf("Endereco de m = %p\n", &m);
  printf("Endereco de fx = %p\n", &fx);
  printf("Endereco de cht = %p\n\n", &cht);
  
  printf("Usando o operador & e * :\n");
  printf("-----------------------------\n");
  printf("Valor do endereco de m = %d\n", *(&m));
  printf("Valor do endereco de fx = %f\n", *(&fx));
  printf("Valor do endereco de cht = %c\n\n", *(&cht));

  printf("Usando apenas a variavel ponteiro :\n");
  printf("----------------------------------\n");
  printf("Endereco de m = %p\n", pm);
  printf("Endereco de fx = %p\n", pf);
  printf("Endereco de cht = %p\n\n", pc);

  printf("Usando apenas o operador do ponteiro :\n");
  printf("----------------------------------\n");
  printf("Endereco de m = %p\n", *pm);
  printf("Endereco de fx = %p\n", *pf);
  printf("Endereco de cht = %p\n\n", *pc);
  return 0;
}
