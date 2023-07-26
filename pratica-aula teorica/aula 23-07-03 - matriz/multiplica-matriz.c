#include <stdio.h>
#include <stdlib.h>

/*
  Estudo utilizando ponteiro de ponteiros para construir matrizes
*/

// protótipos das funções usadas:
int **alocaMatriz(int, int);
void limpaMemoria(int**, int);


int main(void) {

  int linhas = 5, colunas = 5;

  int **matrizA = (int **)alocaMatriz(linhas, colunas);

  // preenchimento das células da matriz
  int linha, coluna;
  
  printf("\n");
  for (linha = 0; linha < linhas; linha++) {
    for (coluna = 0; coluna < colunas; coluna++) {
      matrizA[linha][coluna] = 5*linha + coluna;
      printf("%d\t", matrizA[linha][coluna]);
    }
    printf("\n");
  }

  limpaMemoria(matrizA, linhas);

  return 0;
}

// função que realiza a alocação de memória dinâmica
int **alocaMatriz(int Ls, int Cs) {
  // Aloca espaço na memória para a matriz
  int (**matriz) = (int **)malloc(Ls * sizeof(int *));
  if (matriz == NULL) {
    printf("Erro: Memória insuficiente.\n");
    exit(1);
  }
  int l;
  
  for (l = 0; l < Ls; l++) {
    matriz[l] = (int *)malloc(Cs * sizeof(int));
    if (matriz[Ls] == NULL) {
    printf("Erro: Memória insuficiente.\n");
    exit(1);
    }
  }
  return matriz;
}

// função usada para liberar o espaço de memória alocada
void limpaMemoria(int **mat, int Ls) {
  int l;
  for (l = 0; l < Ls; l++) {
    free(mat[l]);
  }
  free(mat);

}
