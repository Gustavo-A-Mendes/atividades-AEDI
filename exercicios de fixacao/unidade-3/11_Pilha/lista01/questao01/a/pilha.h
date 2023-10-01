/* TAD pilha (n, vet[]) */

/* Tipo exportado */
typedef struct pilha Pilha;

/* Funções Expotadas */

/* Função pilha_cria
    Inicia uma nova pilha, atribuindo 0 ao seu índice
*/
Pilha *pilha_cria(void);

/* Função pilha_push
    Adiciona um valor novo ao topo da lista
*/
void pilha_push(Pilha *p, float v);

/* Função pilha_pop
    Retorna o valor do topo da lista, e o remove
*/
float pilha_pop(Pilha *p);

/* Funçao pilha_vazia
    Verifica se a pilha está vazia
*/
int pilha_vazia(Pilha *p);

/* Função pilha_libera
    Libera o espaço de memória alocado para a pilha
*/
void pilha_libera(Pilha *p);

/* Função pilha_imprime
    Imprime os valores presentes na pilha
*/
void pilha_imprime(Pilha *p);
