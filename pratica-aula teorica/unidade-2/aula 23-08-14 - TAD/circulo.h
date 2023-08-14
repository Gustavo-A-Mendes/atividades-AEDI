/* TAD: Círculo(x, y) */

/* Dependência de módulos */
#include "ponto.h"

/* Tipo exportado */
typedef struct circulo Circulo;

/* Funções exportadas */

/* Função circ_cria
  recebe valores para os parâmetros x, y e r e retorna a struct Circulo
*/
Circulo* circ_cria (float x, float y, float r);

/* Função circ_libera
  libera o espaço da memória alocado
*/
void circ_libera (Circulo* c);

/* Função circ_area
  calcula a área do circulo
*/
float circ_area (Circulo* c);

/* Função circ_interior

*/
int circ_interior (Circulo* c, Ponto* p);