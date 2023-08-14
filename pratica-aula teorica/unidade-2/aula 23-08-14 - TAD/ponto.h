/* TAD: Ponto(x, y) */

/* Tipo exportado */
typedef struct ponto Ponto;

/* Funções exportadas */

/* Função pto_cria
  recebe valores para os parâmetros x e y e retorna a struct Ponto
*/
Ponto* pto_cria (float x, float y);

/* Função pto_libera
  libera o espaço da memória alocado
*/
void pto_libera (Ponto* p);

/* Função pto_acessa
  acessa um conjunto de valores armazenados dentro de uma struct
*/
void pto_acessa (Ponto* p, float* x, float* y);

/* Função pto_atribui
  atribui novos valores aos campos da estrutura
*/
void pto_atribui (Ponto* p, float x, float y);

/* Função pto_distancia
  calcula a distância entre dois pontos
*/
float pto_distancia (Ponto* p1, Ponto* p2);