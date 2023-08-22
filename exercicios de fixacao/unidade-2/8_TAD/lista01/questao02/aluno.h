/* TAD: aluno(nome, matricula, Disciplina, num_disciplinas) */

/* Dependência de módulos */
#include "disciplina.h"

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função cria_aluno
  cadastra um novo aluno, inicializando e alocando espaço na memória
*/
Aluno *cria_aluno(char *nome, int matricula);

/* Função matricula_disciplina
  matricula o aluno em uma disciplina
*/
void matricula_disciplina(Aluno *aluno, Disciplina *disciplina);

/* Função procura_aluno
  faz uma varredura nos alunos cadastrados em busca do
  aluno selecionado, a partir de sua matrícula
*/
Aluno *procura_aluno(Aluno **alunos, int mat, int n);

/* Função lista_alunos
  imprime os dados dos alunos cadastrados no sistema
*/
void lista_alunos(Aluno **alunos, int n);

/* Função exclui_aluno
  limpa os dados de um aluno, liberando o espaço da memória.
*/
void exclui_aluno(Aluno* aluno);