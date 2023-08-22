/* TAD: Matriz(lin, col, v) */

/* Tipo exportado */
typedef struct matriz Matriz;

/* Funções exportadas */

/* Função mat_cria
  cria uma nova matriz, alocando espaço na memória
*/
Matriz* mat_cria(int m, int n);

/* Função mat_libera
  apaga a matriz selecionada, liberando o espaço na memória alocado
*/
void mat_libera(Matriz* mat);

/* Função mat_acessa
  busca e retorna um valor dentro da matriz
*/
float mat_acessa(Matriz* mat, int i, int j);

/* Função mat_atribui
  adiciona um valor novo valor dentro de uma matriz
*/
void mat_atribui(Matriz* mat, int i, int j, float v);

/* Função mat_linhas
  retorna a quantidade de linhas de uma matriz
*/
int mat_linhas(Matriz* mat);

/* Função mat_colunas
  retorna a quantidade de colunas de uma matriz
*/
int mat_colunas(Matriz* mat);