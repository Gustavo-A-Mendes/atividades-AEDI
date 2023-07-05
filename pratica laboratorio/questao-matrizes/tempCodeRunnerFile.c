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