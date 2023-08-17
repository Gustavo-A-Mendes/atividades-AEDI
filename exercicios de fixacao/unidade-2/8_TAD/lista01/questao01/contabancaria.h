/* TAD: contabancaria(titular, numero, saldo) */

/* Dependência de módulos */
#include <stdio.h>

/* Tipo exportado */
typedef struct contaBancaria ContaBancaria;

/* Funções exportadas */

/* Função cria_conta
  cria uma nova conta no banco, alocando espaço na memória e
  preenchendo os parâmetros
*/
ContaBancaria *cria_conta(char *titular, int *numero, float *saldo);

/* Função deposita
  deposita o valor informado na conta selecionada
*/
void deposita(ContaBancaria *conta, float valor);

/* Função saca
  saca o valor informado na conta selecionada
*/
void saca(ContaBancaria *conta, float valor);

/* Função transfere
  realiza a transferência do valor informado entre duas contas
*/
void transfere(ContaBancaria *conta1, ContaBancaria *conta2, float valor);

/* Função verifica_saldo
  verifica o saldo da conta selecionada
*/
float verifica_saldo(ContaBancaria *conta);

/* Função excluir_conta
  exclui a conta, liberando espaço alocado da memória
*/
void excluir_conta(ContaBancaria* conta);