/* TAD: fila.h */

/* Tipo exportado */
typedef struct _fila Fila;

/* Função CriaFila

*/
Fila* CriaFila(int MAX_SIZE);

/* Função DestruirFila

*/
void DestruirFila(Fila **Q);

/* Função FilaVazia

*/
int FilaVazia(Fila *Q);

/* Função FilaCheia

*/
int FilaCheia(Fila *Q);

/* Função InsereFila

*/
int InsereFila(Fila *Q, int elem);

/* Função RemoveFila

*/
int RemoveFila(Fila *Q);

/* Função ConsultaFila

*/
int ConsultaFila(Fila *Q, int *elem);

/* Função ImprimeFila

*/
void ImprimeFila(Fila *Q);
