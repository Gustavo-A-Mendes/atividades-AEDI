#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/*
  O programa imprime os valores de uma matriz quadrada de tamanho definido pelo usuário.
  É alocado memória dinamicamente e preenche a matriz com valores aleatórios de 1 a 100.
*/

int linha, coluna;
int **alocaMatrizQ(int);
void imprimeMatriz(int**, int);

int main(void) {

  srand(time(0)); // muda a seed da geração aleatória a cada execução

  int n;
  printf("Digite o tamanho da matriz quadrada: ");
  scanf("%d", &n);

  // aloca memoria para criar a matriz quadrada
  int **matriz = alocaMatrizQ(n);

  // preenche a matriz com valores aleatórios entre 1 e 100
  for (linha = 0; linha < n; linha++) {
    for (coluna = 0; coluna < n; coluna++) {
      int ran = 1 + (rand() % 100);   //  % calcula o resto da divisão por 100 (retorna de 0 a 99)
      matriz[linha][coluna] = ran;
    }  
  }

  // imprime a matriz quadrada
  imprimeMatriz(matriz, n);

  // limpa memoria após o uso
  for (linha = 0; linha < n; linha++) {
    free(matriz[linha]);
  }
  free(matriz);

  return 0;
}

// Função que aloca memória dinamicamente para a matriz:
int **alocaMatrizQ(int tamanho) {

  int **m = (int**) calloc(tamanho,sizeof(int*));
  if (m == NULL) {
    printf("Erro: alocacao de memoria\n");
    exit(1); //aborta o programa com codigo 1 se nao conseguir
  }
  int i;
  for (i = 0; i < tamanho; i++) {
    m[i]=(int*) calloc(tamanho,sizeof(int));
    if (m[i]==NULL) {
      free(m);
      printf ("Erro na alocação da linha %d.\n", i+1 );
      exit(-2);// aborta o programa com codigo -2 para indicar erro interno do programador
    }
  }
  return m;
}

// Função que imprime a matriz:
void imprimeMatriz (int **m, int tamanho) {
  printf("\n");
  for (linha = 0; linha < tamanho; linha++) {
    for (int coluna = 0; coluna < tamanho; coluna++) {
      printf("%d \t", m[linha][coluna]);
      
    }
    printf("\n");
  }
  printf("\n");
}