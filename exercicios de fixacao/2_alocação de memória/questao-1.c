#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 5;

  char *genero = (char*) malloc(n*sizeof(char));
  char *gostou = (char*) malloc(n*sizeof(char));
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("genero [M/F]: ");
    scanf("%s[^\n]", (genero+i));
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

