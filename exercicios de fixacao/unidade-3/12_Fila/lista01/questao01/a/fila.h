/* TAD: fila.h */

/* Tipo exportado */
typedef struct _fila Fila;

/* Função fila_cria
    cria uma fila, alocando memória dinamicamente
*/
Fila* fila_cria(int MAX_SIZE);

/* Função fila_libera
    libera o espaço da memória alocada
*/
void fila_libera(Fila **Q);

/* Função fila_vazia
    verifica se a fila está vazia
*/
int fila_vazia(Fila *Q);

/* Função fila_cheia
    verifica se a fila está cheia
*/
int fila_cheia(Fila *Q);

/* Função fila_insere
    insere um elemento novo no fim da fila
*/
int fila_insere(Fila *Q, int elem);

/* Função fila_retira
    remove o elemento do início na fila
*/
int fila_retira(Fila *Q);

/* Função fila_consulta
    verifica qual o elemento do início da fila
*/
int fila_consulta(Fila *Q, int *elem);

/* Função fila_imprime
    imprime a fila, do início ao fim
*/
void fila_imprime(Fila *Q);