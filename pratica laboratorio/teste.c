#include <stdio.h>
#include <stdlib.h>

typedef struct coordenadas {
  float x;
  // float y;
} Coordenada;

int main(void) {
  Coordenada *p;
  
  // (*p).x = 12.0;
  // p->x = 13.0;
  printf("\nDigite x: ");
  scanf("%f", &p->x);
  printf("%f\n\n", p->x);
  
  // printf("\nDigite y: ");
  // scanf("%f", &p->y);


  printf("%f\n\n", p->x);

  return 0;
}