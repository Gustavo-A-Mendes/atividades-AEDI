#include <stdio.h>
#include <math.h>

/*
  Esse programa calcula a área e o perímetro de um hexágono a partir do
  tamanho de sua aresta "l", escolhido pelo usuário.
*/

/*
  Função que calcula a área e o perímetro do hexagono por meio da equação do hexagono regular.
*/
void calcula_hexagono(float l, float *area, float *perimetro) {
  *area = (3 * pow(l,2) * sqrt(3))/2; // equação definida para área do hexágono
  *perimetro = 6*l; // equanção definida para perímetro de um hexágono
}

int main (void) {

  // declarando variáveis do tipo inteiro
  float L, a, per;

  printf("Digite o valor do lado do hexagono: ");
  scanf("%f", &L);

  // chama a função criada
  calcula_hexagono(L, &a, &per);

  printf("\nA area de um hexagono de lado %.2f equivale a %.2f, e seu perimetro equivale a %.2f", L, a, per);

  return 0;
}
