/* TAD: Aluno(nome, nota1, nota2, nota3) */

/* Dependência de módulos */
#include <stdio.h>

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função preenche_dados
  cadastras dados do aluno na struct
*/
void preenche_dados(Aluno** alu, int num_alu);

/* Função copia_dados
  escreve os dados nos arquivos
*/
void copia_dados(FILE* fl, Aluno** alu, int num_alu);
