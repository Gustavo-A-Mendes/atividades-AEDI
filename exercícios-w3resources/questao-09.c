#include <stdio.h>
#include <stdlib.h>

int maiorElemento(int *, int);

// Esse código verifica o maior valor de uma lista, com tamanho dinâmico
int main(void) {

  int n = 0;

  printf("Insira o numero total de elementos (de 1 a 100): ");
  scanf("%d", &n);

  float *lista = (float*)calloc(n, sizeof(float));
  if (lista == NULL) {
    printf("Erro: Memória insuficiente.\n");
    exit(1); // termina com erro (1)
  }

  for (int i = 0; i < n; i++) {
    printf("\nNumero %d: ", (i+1));
    scanf("%d", lista+i);
  }

  int valorMaior = maiorElemento(lista, n);
  
  printf("O maior elemento e: %d", valorMaior);

  return 0;
}


int maiorElemento(int *vetor, int tamanho) {
  int maior = 0;
  for (int i = 0; i < tamanho; i++) {
    if (*(vetor+i) > maior) {
      maior = *(vetor + i);
    }
  }
  return maior;
}
