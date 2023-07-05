#include <stdio.h>

// Esse código encontra o fatorial de um número usando ponteiros
int i;
void fact(int *, int);

int main(void) {

  int num, fatorial;

  printf("Insira um numero: ");
  scanf("%d", &num);
  
  fact(&fatorial, num);

  printf("O fatorial de %d: %d", num, fatorial);
  
  return 0;
}

void fact(int *fat, int n) {
  int i;
  
  *fat = 1;
  for (i = 1; i <= n; i++) {
    *fat *= i;
  }
}