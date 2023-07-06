#include <stdio.h>
#include <stdlib.h>


int main (void) {

  // solicita ao usuario o número de pessoas
  int n;
  printf("Digite o numero de pessoas: ");
  scanf("%d", &n);

  int i;
  // aloca memoria para o vetor referente ao nome
  char **nome = (char**)calloc(n,sizeof(char*));
  if (nome == NULL) exit(1); // Falha ao alocar memória
  // for (i = 0; i < n; i++) {
  //   nome[i] = (char*)calloc(n,sizeof(char));
  // }


  // aloca memoria para o vetor referente a idade
  int *idade = (int*)calloc(n,sizeof(int));
  if (idade == NULL) exit(1); // Falha ao alocar memória

  int i;
  for (i = 0; i < n; i++) {
    printf("Digite o nome completo do usuario: \n");
    scanf("%s[^\n]", nome + i);
    printf("Digite a idade do usuario: ");
    scanf("%d", idade + i);
  }

  for (i = 0; i < n; i++) {
    printf("\n\n%s tem %d anos de idade", *(nome+i), *(idade+i));
  }
  


  return 0;
}
