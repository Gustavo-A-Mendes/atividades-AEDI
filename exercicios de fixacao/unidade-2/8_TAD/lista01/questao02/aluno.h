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
void matricula_disciplina(Aluno *conta, Disciplina *disciplina);

/* Função exclui_aluno
*/
void exclui_aluno(Aluno* aluno);