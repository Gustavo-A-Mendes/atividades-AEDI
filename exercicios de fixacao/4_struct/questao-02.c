#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Variáveis para mudar cor dos textos:
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtYellow "\x1b[33m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

// Tipo estruturado para armazenar os dados da pessoa:
typedef struct pessoa {
  char nome[30];
  int RG;
  int idade;
} Pessoa;

// protótipo das funções criadas:
Pessoa *dadosPessoa(Pessoa *);
void imprimiDados(Pessoa *);
void atualizaDados(Pessoa *);
void idadeMaiorMenor(Pessoa *);
int checaValido(char *);

int i;
int numPessoa;

int main(void) {
  printf(txtReset);

  Pessoa *pessoa = dadosPessoa(pessoa);

  imprimiDados(pessoa);

  idadeMaiorMenor (pessoa);

  free(pessoa); // libera memória

  return 0;
}

/*
  Função que aloca espaço na memória para o tipo estruturado,
  recebe os dados e preenche nos campos de cada pessoa:
*/
Pessoa *dadosPessoa(Pessoa *p) {
  
  printf("Insira o numero de pessoas a serem cadastradas: ");
  scanf("%d", &numPessoa);

  p = (Pessoa *)malloc(numPessoa*sizeof(Pessoa));
  if (p==NULL) exit(1);
  
  for (i = 0; i < numPessoa; i++) {
    printf(txtGreen"\n====== PESSOA %d ======\n"txtReset, i+1);
    
    printf("Digite o Nome: ");
    scanf(" %30[^\n]", (p+i)->nome);
    
    printf("Digite o numero RG: ");
    scanf("%d", &(p+i)->RG);

    printf("Digite a idade: ");
    scanf("%d", &(p+i)->idade);

    atualizaDados(p+i);

  }
  return p;
}

/*
  Função que recebe como parâmetro o vetor de pessoas e
  imprime seus dados:
*/
void imprimiDados(Pessoa *p) {

  printf("\nDados recebidos:\n");
  for (i = 0; i < numPessoa; i++) {
    printf("Nome: %s\tRG: %d\tIdade: %d\n", (p+i)->nome, (p+i)->RG, (p+i)->idade);
  }
  
}

/*
  Função que pergunta ao usuário se deseja alterar algum
  dado da pessoa, antes de finalizar o cadastro:
*/
void atualizaDados(Pessoa *p) {
  
  printf(txtYellow"\nConfirma os dados inseridos? [S/N]\n"txtReset);
  
  char resposta[1];
  int valido;
  do {
    
    scanf(" %1[sSnN]", resposta);
    fflush(stdin);

    valido = checaValido(resposta);
    if (valido) printf(txtRed"Erro! Digite um valor valido: [S/N]\n"txtReset);
  } while (valido);

  if (*resposta == 'N') {
    int valor;

    printf("\nQual dado deseja alterar?\n0 - nome\n1 - RG\n2 - Idade\n");
    scanf("%d", &valor);
    while (valor > 2) {
      printf(txtRed"Erro! Digite um valor valido [1-3]: "txtReset);
      scanf("%d", &valor);
    }

    switch (valor) {
      case 0:
        printf("Digite o novo nome: ");
        scanf(" %30[^\n]", p->nome);
        printf("\nO novo nome e: %s\n", p->nome);
        break;
      case 1:
        printf("Digite o numero do RG: ");
        scanf("%d", &p->RG);
        printf("\nO novo numero do RG e: %d\n", p->RG);
        break;
      case 2:
        printf("Digite a idade: ");
        scanf("%d", &p->idade);
        printf("\nA nova idade e: %d\n", p->idade);
        break;
      default:
        break;
    }
  }
}

/*
  Função que retorna o nome e a idade da pessoa com maior
  e com menor salário:
*/
void idadeMaiorMenor (Pessoa *p) {
  int idMaior, idMenor;
  idMaior = idMenor = 0;
  for (i = 1; i<numPessoa ; ++i) {
    if ((p[i].idade > p[idMaior].idade)) {
      idMaior = i;
    }
    if (p[i].idade < p[idMenor].idade) {
      idMenor = i;
    }
  }

  printf ("\nA pessoa "txtCyan"%s"txtReset" e a pessoa mais velha, com "txtCyan"%d"txtReset" anos", p[idMaior].nome, p[idMaior].idade);
  printf ("\nA pessoa "txtCyan"%s"txtReset" e a pessoa mais nova, com "txtCyan"%d"txtReset" anos", p[idMenor].nome, p[idMenor].idade);
}

/*
  Função para verificar se o valor de resposta é valido ou não:
*/
int checaValido(char *ch1) {
  *ch1 = toupper(*ch1); 
  if (*ch1 == 'S' || *ch1 == 'N') {
    return 0;
  }
  return 1;
}