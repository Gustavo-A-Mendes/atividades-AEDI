#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int n = 5;
  
  int linhas = 2, colunas = n;
  char **matrizPerguntas = (char **)malloc(linhas * sizeof(char*));
  int coluna;
  for (coluna = 0; coluna < colunas; coluna++) {
    matrizPerguntas[coluna] = (char*)malloc(colunas * sizeof(char));
  }
  
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("genero [M/F]: ");
    scanf("%s", &(matrizPerguntas[0][i]));
    // printf("opiniao sobre o produto [gostou/nao gostou]: ");
    // scanf("%s[^\n]", &(matrizPerguntas[1][i]));
  }

  int len = strlen(matrizPerguntas[0]);
  for (int i = 0; i < colunas; i++) {
    char teste = *(matrizPerguntas[0]+i);
    printf("%s \t", matrizPerguntas[0][i]);
  }
  
  // for (int i = 0; i < n; i++) { 
  //   printf("opiniao sobre o produto [gostou/nao gostou]: ");
  //   scanf("%[^\n]s", (gostou+i));
  // }

  return 0;
}

// int **alocaMatriz(int Ls, int Cs) {
//   // Aloca espaço na memória para a matriz
//   int (**matriz) = (int **)malloc(Ls * sizeof(int *));
//   if (matriz == NULL) {
//     printf("Erro: Memória insuficiente.\n");
//     exit(1);
//   }
//   int l;
  
//   for (l = 0; l < Ls; l++) {
//     matriz[l] = (int *)malloc(Cs * sizeof(int));
//     if (matriz[Ls] == NULL) {
//     printf("Erro: Memória insuficiente.\n");
//     exit(1);
//     }
//   }
//   return matriz;
// }

