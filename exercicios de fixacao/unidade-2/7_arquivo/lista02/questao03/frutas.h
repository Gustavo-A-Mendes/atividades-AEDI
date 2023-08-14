/* TAD: Frutas(nome, preco) */

/* Dependência de módulos */
#include <stdio.h>

/* Tipo exportado */
typedef struct frutas Frutas;

/* Funções exportadas */

/* Função copia_dados
  escreve os dados nos arquivos
*/
int copia_dados(FILE* fl, Frutas** frutas);
