/* Arquivo aluno.h */

/* Dependência de módulos */
#include <stdio.h>

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função aluno_cria
*/
Aluno *aluno_cria(char *nome, float nota);

/* Função aluno_libera
*/
void aluno_libera(Aluno* a);

/* Função aluno_imprime
*/
void aluno_imprime(Aluno* a);

/* Função aluno_ordena
*/
void aluno_ordena(int n, Aluno** v);

/* Função aluno_salva
*/
void aluno_salva(FILE* fl, int n, Aluno** v);

/* Função confere_ordem
*/
int confere_ordem(char* nome1, char* nome2);
