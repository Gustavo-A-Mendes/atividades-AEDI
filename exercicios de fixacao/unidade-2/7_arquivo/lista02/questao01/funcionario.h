/* TAD: Funcionario(id, nome, salario) */

/* Dependência de módulos */
#include <stdio.h>

/* Tipo exportado */
typedef struct funcionario Funcionario;

/* Funções exportadas */

/* Função preenche_dados
  cadastras dados do funcionario na struct
*/
void preenche_dados(Funcionario** func, int num_func);

/* Função copia_dados
  escreve os dados nos arquivos
*/
void copia_dados(FILE* fl, Funcionario** func, int num_func);
