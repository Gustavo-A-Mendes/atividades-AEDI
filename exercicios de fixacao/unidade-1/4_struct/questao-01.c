#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  Esse programa cria um tipo estruturado para cadastrar dados de funcionários.
  O programa deve imprimir esses dados, permitir que alteremos o valor de salário
  e verificar o cargo do funcionário de maior e menor salário.
*/

// Variáveis para mudar cor dos textos
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtYellow "\x1b[33m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

// Tipo estruturado para armazenar os dados do funcionário:
typedef struct funcionarios {
  char nome[30];
  float salario;
  int id;
  char cargo[30];
} Funcionario;

// protótipo das funções criadas:
Funcionario *cadastro(Funcionario *);
void imprimiDados(Funcionario *);
void alteraSalario (Funcionario *);
void salarioMaiorMenor(Funcionario *);
int checaValido(char *);

int i;
int numFuncionarios;

int main(void) {
  printf(txtReset); // reseta cor
  
  printf("Insira o numero de funcionarios: ");
  scanf("%d", &numFuncionarios);

  Funcionario *funcionario = cadastro(funcionario);
  
  imprimiDados(funcionario);

  salarioMaiorMenor(funcionario);

  free(funcionario);  // Limpa memória

  return 0;
}

/*
  Função que aloca espaço na memória para o tipo estruturado,
  recebe os dados e preenche nos campos de cada funcionário:
*/
Funcionario *cadastro(Funcionario *f) {
  
  f = (Funcionario *)malloc(numFuncionarios*sizeof(Funcionario));
  if (f==NULL) exit(1);
  
  for (i = 0; i < numFuncionarios; i++) {
    printf(txtGreen"\n====== FUNCIONARIO %d ======\n"txtReset, i+1);
    
    printf("Digite o Nome do funcionario: ");
    scanf(" %30[^\n]", (f+i)->nome);
    
    printf("Digite o ID: ");
    scanf("%d", &(f+i)->id);

    printf("Digite o nome do Cargo: ");
    scanf(" %30[^\n]", (f+i)->cargo);

    printf("Digite o valor do Salario: ");
    scanf("%f", &(f+i)->salario);

    alteraSalario(f+i);
  }
  return f;
}

/*
  Função que recebe como parâmetro o vetor de funcionários e
  imprime seus dados:
*/
void imprimiDados(Funcionario *f) {

    printf("\nDados recebidos:\n");
  for (i = 0; i < numFuncionarios; i++) {
    printf("Nome: %s\tID: %d\tCargo: %s\tSalario: R$%.2f\n", (f+i)->nome, (f+i)->id, (f+i)->cargo, (f+i)->salario);
  }
  
}

/*
  Função que pergunta ao usuário se deseja alterar o salário
  do funcionário, antes de finalizar o cadastro:
*/
void alteraSalario (Funcionario *f) {
  
  printf(txtYellow"\nEsse valor de Salario esta correto? [S/N]\n"txtReset);
  
  char resposta[1];
  int valido;
  do {
    
    scanf(" %1[sSnN]", resposta);
    fflush(stdin);

    valido = checaValido(resposta);
    if (valido) printf(txtRed"Erro! Digite um valor valido: [S/N]\n"txtReset);
  } while (valido);

  if (*resposta == 'N') {
    printf("\nInsira o novo salario: ");
    scanf("%f", &f->salario);
    printf("\nO novo salario e: R$%.2f\n", f->salario);
  }
}

/*
  Função que retorna o nome e cargo do funcionário com maior
  e com menor salário:
*/
void salarioMaiorMenor (Funcionario *f) {
  int idMaior, idMenor;
  idMaior = idMenor = 0;
  for (i = 1; i<numFuncionarios ; ++i) {
    if ((f[i].salario > f[idMaior].salario)) {
      idMaior = i;
    }
    if (f[i].salario < f[idMenor].salario) {
      idMenor = i;
    }
  }

  printf ("\nO funcionario "txtCyan"%s"txtReset", "txtCyan"%s"txtReset", possui o maior salario, de "txtCyan"R$ %.2f\n"txtReset, f[idMaior].nome, f[idMaior].cargo, f[idMaior].salario);
  printf ("\nO funcionario "txtCyan"%s"txtReset", "txtCyan"%s"txtReset", possui o menor salario, de "txtCyan"R$ %.2f\n"txtReset, f[idMenor].nome, f[idMenor].cargo, f[idMenor].salario);
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