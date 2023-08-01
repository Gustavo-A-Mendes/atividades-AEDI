#include <stdio.h>

int soma(int valor1, int valor2) {
  /*
    Função que soma dois valores
    int valor1: valor inteiro  
    int valor2: valor inteiro  
  */
  int sum = (valor1 + valor2);
  return sum;
}

int main(void) {
  /* Declarar
     tipo (* nome_do_ponteiro_para_funcao)(lista_de_tipo_de_argumentos_que_a_funcao_espera)
  */
  
  int (*p)(int, int) = soma;

  int resultado = p(2,3);
  printf("Valor do resultado = %d", resultado);

  return 0;
}