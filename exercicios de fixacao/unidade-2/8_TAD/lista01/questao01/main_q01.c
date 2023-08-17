#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

int main(void) {
  ContaBancaria *conta1, *conta2;

  char nome[51];
  int num_conta;
  float saldo_init;

  printf("Informe o nome do titular: ");
  scanf(" %50[^\n]", nome);
  printf("Informe o numero da conta: ");
  scanf("%d", &num_conta);
  printf("Informe o saldo inicial da conta: ");
  scanf("%f", &saldo_init);

  conta1 = cria_conta(nome, &num_conta, &saldo_init);
  
  printf("Informe o nome do titular: ");
  scanf(" %50[^\n]", nome);
  printf("Informe o numero da conta: ");
  scanf("%d", &num_conta);
  printf("Informe o saldo inicial da conta: ");
  scanf("%f", &saldo_init);
  conta2 = cria_conta(nome, &num_conta, &saldo_init);

  // deposita R$ 200.00 na conta 1
  deposita(conta1, 200);

  // saca R$ 200.00 na conta 2
  saca(conta2, 200);

  // transfere R$ 400.00 da conta 1 para a conta 2
  transfere(conta1, conta2, 400);

  // verifica o saldo da conta 1
  verifica_saldo(conta1);

  // libera a memoria
  excluir_conta(conta1);
  excluir_conta(conta2);


  return 0;
}
