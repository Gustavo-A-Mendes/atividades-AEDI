#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mudar cor dos textos, somente para estética
#define txtGreen "\x1b[32m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

/*
  O programa cria armazerna os nomes e a idade de até 100 pessoas em uma matriz e um vetor,
  respectivamente. Após isso, imprime as informações.
*/

// protótipo da função utilizada:
void registraPessoa(char**, int*);
void imprimeDados(char**, int*);

// variáveis globais:
int i;
int numPessoas = 0;

int main (void) {
  printf(txtReset); // reseta para a cor padrão de texto

  // adiciona um limite máximo de 100 pessoas armazenadas:
  while (1) {
    printf("Digite o numero de pessoas: ");
    scanf("%d", &numPessoas);
    if (numPessoas > 100) {
      printf("Numero invalido! Tem que ser no maximo 100.\n\n");
    } else break;
  }
  
  char **nomes = (char**)malloc(numPessoas*sizeof(char*));
  if (nomes == NULL) exit(1); // Falha ao alocar memória

  int *idades = (int*)calloc(numPessoas,sizeof(int));
  if (idades == NULL) exit(1);

  registraPessoa(nomes, idades);
  
  imprimeDados(nomes, idades);

  // limpa memória
  for (i = 0; i < numPessoas; i++) {
    free(nomes[i]);
  }
  free(nomes);
  free(idades);
  
  return 0;
}

// função que solicita dados ao usuário e armazena na matriz e no vetor
void registraPessoa(char **nome, int *idade) {
  for (i = 0; i < numPessoas; i++) {
    printf(txtGreen"\n========== USUARIO %d =========="txtReset, i+1);
    nome[i] = (char*)malloc(50*sizeof(char));  // tamanho máximo: 50 caracteres
    if (nome[i] == NULL) exit(1); // Falha ao alocar memória

    printf("\nDigite o nome completo: ");
    scanf(" %[^\n]s", nome[i]);

    // redefini a memória alocada para cada nome, tirando o excesso de espaço
    nome[i] = (char *)realloc(nome[i], (strlen(nome[i]) + 1) * sizeof(char));

    printf("Digite a idade do usuario: ");
    scanf("%d", idade + i);
    fflush(stdin);  // limpa lixo do buffer de entrada
  }

}

void imprimeDados(char **nomes, int *idades) {
  for (i = 0; i < numPessoas; i++) {
    printf(txtCyan"\n%s"txtReset" tem"txtCyan" %d"txtReset" anos de idades.\n", nomes[i], idades[i]);
  }
  printf("\n");
}