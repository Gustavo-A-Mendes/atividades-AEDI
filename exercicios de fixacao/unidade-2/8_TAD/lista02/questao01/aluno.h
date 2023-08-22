/* Arquivo aluno.h */

/* Dependência de módulos */
#include <stdio.h>

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função aluno_cria
  inicializa uma nova struct do tipo Aluno, alocando espaço na memória
*/
Aluno *aluno_cria(char *nome, float nota);

/* Função aluno_libera
  limpa a struct do tipo Aluno selecionada, liberando o espaço na memória alocado
*/
void aluno_libera(Aluno* a);

/* Função aluno_imprime
  imprime os valores de um aluno
*/
void aluno_imprime(Aluno* a);

/* Função confere_ordem
  compara duas strings e verifica quem vem primeiro, pela ordem alfabética
*/
int confere_ordem(char* nome1, char* nome2);

/* Função aluno_ordena
  ordena os alunos dentro de um vetor de ponteiros para o tipo Aluno,
  em ordem alfabética, a partir dos nomes dos alunos
*/
void aluno_ordena(int n, Aluno** v);

/* Função aluno_salva
  salva os dados dos alunos em um arquivo de saída
*/
void aluno_salva(FILE* fl, int n, Aluno** v);

