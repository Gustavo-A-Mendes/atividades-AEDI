#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro) {
  // calcula a área e o perímetro do hexagono por meio da equação do hexagono regular
  *area = (3 * pow(l,2) * sqrt(3))/2;
  *perimetro = 6*l;
}

int main (void) {
  float L, a, per;
  printf("Digite o valor do lado do hexagono: ");
  scanf("%f", &L);

  calcula_hexagono(L, &a, &per);

  printf("\nA area de um hexagono de lado %.2f equivale a %.2f, e seu perimetro equivale a %.2f", L, a, per);

  return 0;
}
