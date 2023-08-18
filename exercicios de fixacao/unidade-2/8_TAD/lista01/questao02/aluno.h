/* TAD: aluno(nome, matricula, Disciplina, num_disciplinas) */

/* Dependência de módulos */
#include "disciplina.h"

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função cria_aluno
*/
Aluno *cria_aluno(char *nome, int matricula);

/* Função matricula_disciplina
*/
void matricula_disciplina(Aluno *aluno, Disciplina *disciplina);

/* Função procura_aluno
  
*/
Aluno *procura_aluno(Aluno **alunos, int mat, int n);

/* Função lista_alunos

*/
void lista_alunos(Aluno **alunos, int n);

/* Função exclui_aluno
*/
void exclui_aluno(Aluno* aluno);