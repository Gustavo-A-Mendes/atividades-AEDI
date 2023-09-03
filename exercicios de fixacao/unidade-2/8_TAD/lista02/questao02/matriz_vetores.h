/* TAD: Matriz(lin, col, v) */

/* Tipo exportado */
typedef struct matriz_vetores MatrizV;

/* Funções exportadas */

/* Função mat_cria
  cria uma nova matriz, alocando espaço na memória
*/
MatrizV *matV_cria(int m, int n);

/* Função mat_libera
  apaga a matriz selecionada, liberando o espaço na memória alocado
*/
void matV_libera(MatrizV *mat);

/* Função mat_acessa
  busca e retorna um valor dentro da matriz
*/
float matV_acessa(MatrizV *mat, int i, int j);

/* Função mat_atribui
  adiciona um valor novo valor dentro de uma matriz
*/
void matV_atribui(MatrizV *mat, int i, int j, float v);

/* Função mat_linhas
  retorna a quantidade de linhas de uma matriz
*/
int matV_linhas(MatrizV *mat);

/* Função mat_colunas
  retorna a quantidade de colunas de uma matriz
*/
int matV_colunas(MatrizV *mat);