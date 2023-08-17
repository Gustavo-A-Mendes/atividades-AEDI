#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct contaBancaria {
  char titular[51];
  int numero;
  float saldo;
};

ContaBancaria *cria_conta(char *titular, int *numero, float *saldo) {
  ContaBancaria *conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
  if (conta == NULL) exit(1);
  else printf("\nConta criada com sucesso!\n");

  strcpy(conta->titular, titular);
  conta->numero = *numero;
  conta->saldo = *saldo;

  return conta;
}

void deposita(ContaBancaria *conta, float valor) {
  conta->saldo += valor;
  printf("\nValor de R$ %.2f adicionado! Saldo atual: %.2f\n", valor, conta->saldo);
}

void saca(ContaBancaria *conta, float valor) {
  if (conta->saldo > valor) {
    conta->saldo -= valor;
    printf("\nSaque de R$ %.2f realizado! Saldo atual: %.2f\n", valor, conta->saldo);
  } else {
    printf("Conta %d nao possui saldo suficiente!", conta->numero);
  }
}

void transfere(ContaBancaria *conta1, ContaBancaria *conta2, float valor) {
  if (conta1->saldo > valor) {
    conta1->saldo -= valor;
    conta2->saldo += valor;
    printf("\nTransferencia de R$ %.2f realizada!\n", valor);
    printf("Saldo conta %d: %.2f\n", conta1->numero, conta1->saldo);
    printf("Saldo conta %d: %.2f\n", conta2->numero, conta2->saldo);
  } else {
    printf("\nConta %d nao possui saldo suficiente!\n", conta1->numero);
  }
}

float verifica_saldo(ContaBancaria *conta) {
  return conta->saldo;
}

void excluir_conta(ContaBancaria* conta) {
  free(conta);
}





