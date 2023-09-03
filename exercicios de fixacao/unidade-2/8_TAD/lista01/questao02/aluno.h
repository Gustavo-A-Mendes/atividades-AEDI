/* TAD: aluno(nome, matricula, Disciplina, num_disciplinas) */

/* Dependência de módulos */
#include "disciplina.h"

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função alu_cria
cadastra um novo aluno, inicializando e alocando espaço na memória
*/
Aluno *alu_cria(char *nome, int matricula);

/* Função alu_matricula
matricula o aluno em uma disciplina
*/
void alu_matricula(Aluno *aluno, Disciplina *disciplina);

/* Função alu_procura
faz uma varredura nos alunos cadastrados em busca do
aluno selecionado, a partir de sua matrícula
*/
Aluno *alu_procura(Aluno **alunos, int mat, int n);

/* Função alu_lista
imprime os dados dos alunos cadastrados no sistema
*/
void alu_lista(Aluno **alunos, int n);

/* Função alu_exclui
limpa os dados de um aluno, liberando o espaço da memória.
*/
void alu_exclui(Aluno *aluno);