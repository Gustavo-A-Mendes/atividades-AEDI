#include <stdio.h>
#include <stdlib.h>

/*
  O programa imprime os valores de uma matriz e sua transposta. É alocado memória dinamicamente para as matrizes
  e é solicitado ao usuário o número de linhas, colunas, além dos valores para preenchê-las.
*/

// protótipo da função utilizada:
int **alocaMatriz(int, int);
int **transposta(int**, int, int);
void imprimeMatriz(int**, int, int);

// variáveis globais:
int linha, coluna;

int main(void) {

  // solicita ao usuario a quantidade de linhas e colunas
  int linhas, colunas;
  printf("Digite o numero de linhas e colunas da matriz: \n");
  printf("Linhas: ");
  scanf("%d", &linhas);
  printf("Colunas: ");
  scanf("%d", &colunas);

  // aloca memória para criar a matriz
  int **matriz = alocaMatriz(linhas, colunas);

  // solicita ao usuário para inserir os valores da tabela
  for (linha = 0; linha < linhas; linha++) {
    for (coluna = 0; coluna < colunas; coluna++) {
      printf("elemento [%d, %d]: ", linha, coluna);
      scanf("%d", &matriz[linha][coluna]);
    }  
  }

  // aloca memória e cria a matriz transposta da matriz principal
  int **matrizT = transposta(matriz, linhas, colunas);
  
  // imprime a matriz e sua transposta
  imprimeMatriz(matriz, linhas, colunas);
  imprimeMatriz(matrizT, colunas, linhas);

  // limpa memoria após o uso
  for (linha = 0; linha < linhas; linha++) {
    free(matriz[linha]);
  }
  free(matriz);

  return 0;
}


// Função que aloca memória dinamicamente:
int **alocaMatriz(int linhas, int colunas) {

  int **m = (int**) calloc(linhas,sizeof(int*));
  if (m == NULL) {
    printf("Erro: alocacao de memoria\n");
    exit(1); //aborta o programa com codigo 1 se nao conseguir
  }
  
  for (coluna = 0; coluna < linhas; coluna++) {
    m[coluna]=(int*) calloc(colunas,sizeof(int));
    if (m[coluna]==NULL) {
      free(m);
      printf ("Erro na alocação da linha %d.\n", coluna+1);
      exit(1);// aborta o programa com codigo 1 para indicar erro interno do programador
    }
  }
  return m;
}

// Função que gera a matriz transposta:
int **transposta(int **m, int L, int C) {
  
  int **mt=alocaMatriz(C, L);
  for (coluna = 0 ; coluna < C; coluna++) {
    for (linha = 0; linha <  L; linha++) {
      mt[coluna][linha] = m[linha][coluna];
    }
  }
  return mt;
}

// Função que imprime a matriz
void imprimeMatriz (int **m, int L, int C) {
  printf("\n");
  for (linha = 0; linha < L; linha++) {
    for (int coluna = 0; coluna < C; coluna++) {
      printf("%d \t", m[linha][coluna]);
      
    }
    printf("\n");
  }
  printf("\n");
}