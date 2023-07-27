#include <stdio.h>
#include <stdlib.h>

int i;

int *soma_vetor(int* v1, int* v2, int tamanho) {

  int *v_result = (int*)malloc(tamanho*sizeof(int));

  for (i = 0; i < tamanho; i++) {
    v_result[i] = v1[i] + v2[i];

  }


  return v_result;
}


int main(void) {

  int v1[3] = {0, 1, 2};
  int v2[3] = {7, 2, 6};

  int *v3 = soma_vetor(v1, v2, 3);

  for (i = 0; i < 3; i++) {
    printf("%d\t", v3[i]);
  }
  

  return 0;
}