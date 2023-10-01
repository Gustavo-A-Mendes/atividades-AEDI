#include <stdio.h>
#include "./b/fila.c"

int main(void) {

    int ele;
    Fila *Q;

    Q = fila_cria();
    printf("\nConsultando o primeiro valor da fila:\n");
    if (fila_consulta(Q, &ele)) {
        printf("elem = %d\n", ele);
    }

    printf("\nInserindo valores na fila:\n");
    fila_insere(Q, 10);
    fila_insere(Q, 20);
    fila_insere(Q, 30);
    fila_imprime(Q);

    printf("\nConsultando o primeiro valor da fila:\n");
    if (fila_consulta(Q, &ele)) {
        printf("elem = %d\n", ele);
    }

    fila_retira(Q);
    printf("\nFila apos a remocao do valor do inicio.\n");
    fila_imprime(Q);
    
    printf("\nConsultando o primeiro valor da fila:\n");
    if (fila_consulta(Q, &ele)) {
        printf("elem = %d\n", ele);
    }
    
    fila_insere(Q, 40);
    printf("\nInserindo valor 40 na fila.\n");
    fila_imprime(Q);

    printf("\nConsultando o primeiro valor da fila:\n");
    if (fila_consulta(Q, &ele)) {
        printf("elem = %d\n", ele);
    }

    printf("\nAtigindo o limite maximo de valores:\n");
    fila_insere(Q, 50);
    fila_imprime(Q);
    fila_insere(Q, 60);
    fila_imprime(Q);
    fila_insere(Q, 70);
    fila_imprime(Q);

    fila_retira(Q);
    fila_insere(Q, 80);
    fila_imprime(Q);

    fila_libera(&Q);

    return 0;
}