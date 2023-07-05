#include <stdio.h>

// Esse código troca a posição dos elementos
int i;
void misturaLista(int *);

int main(void) {
  
  int valor[3];
  for (i = 0; i < 3; i++) {
    printf("Insira o valor do 1st elemento: ");
    scanf("%d", valor+i);
  }
  
  printf("\nOs valores antes de misturar: \n");
  for (i = 0; i < 3; i++) {
    printf("Elemento %d: %d\n", i, *(valor+i));
  }

  misturaLista(valor);
  
  printf("\nOs valores depois de misturar: \n");
  for (i = 0; i < 3; i++) {
    printf("Elemento %d: %d\n", i, *(valor+i));
  }

  return 0;
}

void misturaLista(int *lista) {
  int temp;
  temp = *(lista+2);
  *(lista+2) = *(lista+1);
  *(lista+1) = *(lista+0);
  *(lista+0) = temp;
}