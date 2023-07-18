// Programa que manipula dados de uma pessoa e armazena em uma struct, utilizando ponteiros
#include <stdio.h>
#include <stdlib.h>

typedef struct conta {

  char nome[20];
  int agencia;
  int num_conta;
  int senha;
  float saldo;

} ContaBancaria;

ContaBancaria *cadastraConta(ContaBancaria *);
void imprimeConta(ContaBancaria *);

int i;
int numConta;

int main(void) {
  
  printf("Insira o numero de contas bancarias a cadastrar: ");
  scanf("%d", &numConta);

  ContaBancaria *conta = cadastraConta(conta);

  imprimeConta(conta);

  return 0;
}

ContaBancaria *cadastraConta(ContaBancaria *var_conta) {

  var_conta = (ContaBancaria *)malloc(numConta*sizeof(ContaBancaria));
  
  for (i = 0; i < numConta; i++) {
    printf("\n====== CONTA %d ======\n", i+1);

    printf("Digite o nome : ");
    scanf(" %[^\n]", (var_conta+i)->nome);

    printf("Digite o numero da agencia: ");
    scanf("%d", &(var_conta+i)->agencia);

    printf("Digite o numero da conta: ");
    scanf("%d", &(var_conta+i)->num_conta);

    printf("Digite a senha: ");
    scanf("%d", &(var_conta+i)->senha);

    printf("Digite o saldo: ");
    scanf("%f", &(var_conta+i)->saldo);
  }

  return var_conta;
}

void imprimeConta(ContaBancaria *var_conta) {
  printf("Os dados informados:\n");
  for (i = 0; i < numConta; i++) {
    printf("Nome: %s\tAgencia: %d\tConta: %d\tSenha: %d\tSaldo: R$%.2f\n", (var_conta+i)->nome, (var_conta+i)->agencia, (var_conta+i)->num_conta, (var_conta+i)->senha, (var_conta+i)->saldo);
  }
}