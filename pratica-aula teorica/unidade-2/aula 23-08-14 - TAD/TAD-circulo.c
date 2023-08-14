#include <stdio.h>
#include "circulo.h"
// #include "circulo.c"
#include "ponto.h"
// #include "ponto.c"

int main(void) {
  Circulo * c = circ_cria (2.0, 1.0, 3.0);
  Ponto * p = pto_cria (5.2, 1.7);
  
  float a = circ_area(c);
  printf("A area do circulo e %.2f\n", a);

  if (circ_interior(c, p)) {
    printf("O ponto esta dentro da circunferencia");
  } else {
    printf("O ponto nao esta dentro da circunferencia");
  }


  circ_libera(c);

  return 0;
}