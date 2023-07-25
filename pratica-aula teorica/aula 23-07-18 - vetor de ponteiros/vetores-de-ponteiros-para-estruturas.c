#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct aluno {
  int mat;
  char nome[81];
  char end[121];
  char tel[21];
} Aluno;

void inicializa(int, Aluno**);
void preenche (int, Aluno **, int);
void retira(int, Aluno **, int);
void imprime(int, Aluno **, int);
void imprime_tudo(int, Aluno **);

/*
  Na função principal, o programa aloca memória para o vetor de ponteiros Aluno
  e inicializa todos os pontos com NULL. Após isso, ele preenche o cadastro de
  três alunos, imprimindo-os e depois liberando o espaço de memória reservado.
*/
int main(void) {
  Aluno **tab = (Aluno **)malloc(10*sizeof(Aluno *));
  inicializa(10, tab);

  preenche(10, tab, 0);
  preenche(10, tab, 1);
  preenche(10, tab, 2);
  imprime_tudo(10, tab);
  retira(10, tab, 0);
  retira(10, tab, 1);
  retira(10, tab, 2);

  return 0;
}

/*
  Essa função inicializa cada ponteiro para estrutura com o valor NULL:
*/
void inicializa (int n, Aluno ** tab) {
  int i;
  for (i = 0; i < n; i++) {
    tab[i] = NULL;
  }
}

/*
  Essa função solicita ao usuário as informação para cada parâmetro
  da estrutura:
*/
void preenche (int n, Aluno **tab, int i) {
  if (i < 0 || i > n) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }
  if (tab[i] == NULL) {
    tab[i] = (Aluno*)malloc(sizeof(Aluno));
  }

  printf("\n========== CADASTRO %d ==========\n", i+1);

  printf("Entre com a matricula: ");
  scanf("%d", &tab[i]->mat);
  printf("Entre com o nome: ");
  scanf(" %80[^\n]", tab[i]->nome);
  printf("Entre com o endereco: ");
  scanf(" %120[^\n]", tab[i]->end);
  printf("Entre com o telefone: ");
  scanf(" %20[^\n]", tab[i]->tel);
}

/*
  Essa função libera a memória reservada para o tipo estruturado
  e em seguida inicializa com NULL:
*/
void retira(int n, Aluno ** tab, int i) {
  if (i < 0 || i > n) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }
  if (tab[i] == NULL) {
    free(tab[i]);
    tab[i] = NULL;
  }
}

/*
  Essa função imprime os parâmetros de um tipo estruturado,
  caso haja conteudo alem de NULL:
*/
void imprime(int n, Aluno **tab, int i) {
  if (i < 0 || i > n) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }
  if (tab[i] != NULL) {
    printf("\n========== CADASTRO %d ==========\n", i+1);

    printf("Matricula: %d\n", tab[i]->mat);
    printf("Nome: %s\n", tab[i]->nome);
    printf("Endereco: %s\n", tab[i]->end);
    printf("Telefone: %d\n", tab[i]->tel);
  }
}

/*
  Utiliza a função imprime() em todo o vetor de ponteiros
*/
void imprime_tudo(int n, Aluno **tab) {
  int i;
  for (i = 0; i < n; i++) {
    imprime(n, tab, i);
  }
}