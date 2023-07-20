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


int main(void) {
  ContaBancaria *var_conta = (ContaBancaria *)malloc(5*sizeof(ContaBancaria));
  
  int i;
0  for (i = 0; i < 5; i++) {
    printf("\n====== PESSOA %d ======\n", i+1);


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

    printf("Os dados informados:\nNome: %s\tAgencia: %d\tConta: %d\tSenha: %d\tSaldo: R$%.2f\n", (var_conta+i)->nome, (var_conta+i)->agencia, (var_conta+i)->num_conta, (var_conta+i)->senha, (var_conta+i)->saldo);
  }

  return 0;
}