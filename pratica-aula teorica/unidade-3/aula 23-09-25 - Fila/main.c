#include <stdio.h>
#include "fila.h"

int main(void) {

    int ele;
    Fila *Q;

    Q = CriaFila(5);
    printf("\nConsultando o primeiro valor da fila:\n");
    if (ConsultaFila(Q, &ele)) {
        printf("elem = %d\n", ele);
    }

    printf("\nInserindo valores na fila:\n");
    InsereFila(Q, 10);
    InsereFila(Q, 20);
    InsereFila(Q, 30);
    ImprimeFila(Q);

    printf("\nConsultando o primeiro valor da fila:\n");
    if (ConsultaFila(Q, &ele)) {
        printf("elem = %d\n", ele);
    }

    RemoveFila(Q);
    printf("\nFila apos a remocao do valor do inicio.\n");
    ImprimeFila(Q);
    
    InsereFila(Q, 40);
    printf("\nInserindo valor 40 na fila.\n");
    ImprimeFila(Q);

    printf("\nConsultando o primeiro valor da fila:\n");
    if (ConsultaFila(Q, &ele)) {
        printf("elem = %d\n", ele);
    }

    printf("\nAtigindo o limite maximo de valores:\n");
    InsereFila(Q, 50);
    ImprimeFila(Q);
    InsereFila(Q, 60);
    ImprimeFila(Q);
    InsereFila(Q, 70);
    ImprimeFila(Q);

    RemoveFila(Q);
    InsereFila(Q, 80);
    ImprimeFila(Q);

    DestruirFila(&Q);

    return 0;
}