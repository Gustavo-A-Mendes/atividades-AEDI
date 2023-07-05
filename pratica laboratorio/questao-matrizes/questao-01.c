#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int tamanho;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tamanho);

  int *vetor = (int*)calloc(tamanho,sizeof(int));
  if (vetor == NULL) {
    printf("Erro de alocaçao");
    exit(1); // Falha ao alocar memória
  } else {
    printf("\nAlocado com sucesso\n");
  }
  

  printf("\nInsira elementos no vetor\n");
  int contador;
  for (contador = 0; contador < tamanho; contador++) {
    printf("elemento %d: ", contador);
    scanf("%d", vetor+contador);
  }
  
  for (contador = tamanho-1; contador >= 0; contador--) {
    printf("\nelemento %d: %d", contador, *(vetor+(contador)));
  }

  free(vetor);

  return 0;
}