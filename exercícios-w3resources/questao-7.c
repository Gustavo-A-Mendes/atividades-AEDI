#include <stdio.h>

// Esse codigo armazena e envia os elementos de uma array

int main(void) {
  int n, num[20], *p = num;
  printf("Insira o numero de elementos para armazenar na array: ");
  scanf("%d", &n);
  
  printf("Insira %d elementos na array: \n", n);
  for (int i = 0; i < n; i++) {
    printf("Elemento - %d : ", i);
    scanf("%d", p+i);
  }
  
  printf("\nOs elementos que voce inseriu são: \n");  
  for (int i = 0; i < n; i++) {
    printf("Elemento - %d : %d \n", i, *(p+i));

  }
  
  return 0;
}