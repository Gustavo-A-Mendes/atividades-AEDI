#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// mudar cor dos textos
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtYellow "\x1b[33m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

typedef struct pessoa {
  char nome[30];
  int RG;
  int idade;
} Pessoa;

int i;
int numPessoa;
int checaValido(char *);
void imprimiDados(Pessoa *);
void atualizaDados(Pessoa *);
void idadeMaiorMenor(Pessoa *);
Pessoa *dadosPessoa(Pessoa *);

int main(void) {
  printf(txtReset);

  Pessoa *pessoa = dadosPessoa(pessoa);

  imprimiDados(pessoa);

  idadeMaiorMenor (pessoa);

  free(pessoa);

  return 0;
}

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

void imprimiDados(Pessoa *p) {

  printf("\nDados recebidos:\n");
  for (i = 0; i < numPessoa; i++) {
    printf("Nome: %s\tRG: %d\tIdade: %d\n", (p+i)->nome, (p+i)->RG, (p+i)->idade);
  }
  
}

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

void idadeMaiorMenor (Pessoa *p) {
  int idMaior, idMenor;
  int maior, menor;
  idMaior = idMenor = 0;
  maior = menor = p[0].idade;
  for (i = 1; i<numPessoa ; ++i) {
    if ((maior < p[i].idade)) {
      maior = p[i].idade;
      idMaior = i;
    }
    if (menor > p[i].idade) {
      menor = p[i].idade;
      idMenor = i;
    }
  }

  printf ("\nO funcionario "txtCyan"%s"txtReset" e a pessoa mais velha, com "txtCyan"%d"txtReset" anos", p[idMaior].nome, maior);
  printf ("\nO funcionario "txtCyan"%s"txtReset" e a pessoa mais nova, com "txtCyan"%d"txtReset" anos", p[idMenor].nome, menor);
}

int checaValido(char *ch1) {
  *ch1 = toupper(*ch1); 
  if (*ch1 == 'S' || *ch1 == 'N') {
    return 0;
  }
  return 1;
}