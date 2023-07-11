#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mudar cor dos textos
#define txtGreen "\x1b[32m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

/*
  O programa cria armazerna os nomes e a idade de até 100 pessoas em uma matriz e um vetor,
  respectivamente. Após isso, imprime as informações.
*/



int main (void) {
  printf(txtReset); // reseta cor

  int i;
  int numPessoas = 0;

  while (1) {
    printf("Digite o numero de pessoas: ");
    scanf("%d", &numPessoas);
    if (numPessoas > 100) {
      printf("Numero invalido! Tem que ser no maximo 100.\n\n");
    }
    break;
  }
  
  char **nomes = (char**)malloc(numPessoas*sizeof(char*));
  if (nomes == NULL) exit(1); // Falha ao alocar memória

  int *idades = (int*)calloc(numPessoas,sizeof(int));
  if (idades == NULL) exit(1);

  for (i = 0; i < numPessoas; i++) {
    printf(txtGreen"\n========== USUARIO %d =========="txtReset, i+1);
    nomes[i] = (char*)malloc(50*sizeof(char));  // tamanho máximo: 50 caracteres
    if (nomes[i] == NULL) exit(1); // Falha ao alocar memória

    printf("\nDigite o nome completo: ");
    scanf(" %[^\n]s", nomes[i]);

    // redefini a memória alocada para cada nome, tirando o excesso de espaço
    nomes[i] = (char *)realloc(nomes[i], (strlen(nomes[i]) + 1) * sizeof(char));

    printf("Digite a idade do usuario: ");
    scanf("%d", idades + i);
  }

  for (i = 0; i < numPessoas; i++) {
    printf(txtCyan"\n%s"txtReset" tem"txtCyan" %d"txtReset" anos de idades.\n", nomes[i], idades[i]);
  }
  printf("\n");

  // limpa memória
  for (i = 0; i < numPessoas; i++) {
    free(nomes[i]);
  }
  free(nomes);
  free(idades);
  
  return 0;
}
