#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// mudar cor dos textos
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtYellow "\x1b[33m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

typedef struct funcionarios {
  char nome[30];
  float salario;
  int id;
  char cargo[30];
} Funcionario;

Funcionario *cadastro(Funcionario *);
void imprimiDados(Funcionario *);
void alteraSalario (Funcionario *);
void salarioMaiorMenor(Funcionario *);
int checaValido(char *);

int i;
int numFuncionarios;

int main(void) {
  printf(txtReset); // reseta cor

  Funcionario *funcionario = cadastro(funcionario);
  
  imprimiDados(funcionario);

  salarioMaiorMenor(funcionario);

  free(funcionario);  // Limpa memória

  return 0;
}

Funcionario *cadastro(Funcionario *f) {
  
  printf("Insira o numero de funcionarios: ");
  scanf("%d", &numFuncionarios);

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

void imprimiDados(Funcionario *f) {

    printf("\nDados recebidos:\n");
  for (i = 0; i < numFuncionarios; i++) {
    printf("Nome: %s\tID: %d\tCargo: %s\tSalario: R$%.2f\n", (f+i)->nome, (f+i)->id, (f+i)->cargo, (f+i)->salario);
  }
  
}

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

int checaValido(char *ch1) {
  *ch1 = toupper(*ch1); 
  if (*ch1 == 'S' || *ch1 == 'N') {
    return 0;
  }
  return 1;
}