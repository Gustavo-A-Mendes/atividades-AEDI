/* TAD: Matriz(lin, col, v) */

/* Tipo exportado */
typedef struct matriz_simples MatrizS;

/* Funções exportadas */

/* Função mat_cria
  cria uma nova matriz, alocando espaço na memória
*/
MatrizS *matS_cria(int m, int n);

/* Função mat_libera
  apaga a matriz selecionada, liberando o espaço na memória alocado
*/
void matS_libera(MatrizS *mat);

/* Função mat_acessa
  busca e retorna um valor dentro da matriz
*/
float matS_acessa(MatrizS *mat, int i, int j);

/* Função mat_atribui
  adiciona um valor novo valor dentro de uma matriz
*/
void matS_atribui(MatrizS *mat, int i, int j, float v);

/* Função mat_linhas
  retorna a quantidade de linhas de uma matriz
*/
int matS_linhas(MatrizS *mat);

/* Função mat_colunas
  retorna a quantidade de colunas de uma matriz
*/
int matS_colunas(MatrizS *mat);