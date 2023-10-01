#include "../questao01/a/pilha.h"
#include <stdio.h>
#include <stdlib.h>

/* ========== PROTÓTIPO DAS FUNÇÕES ========== */
float topo(Pilha* p);
void concatena_pilhas(Pilha *p1, Pilha *p2);

/* ========== MAIN ========== */
int main(void) {
    
    system("cls");

    Pilha *pilha1, *pilha2;

    pilha1 = pilha_cria();
    pilha2 = pilha_cria();

    pilha_push(pilha1, 1.0);
    pilha_push(pilha1, 4.5);
    pilha_push(pilha1, 2.1);

    pilha_push(pilha2, 9.8);
    pilha_push(pilha2, 3.1);
    pilha_push(pilha2, 9.8);

    // imprimindo os valores da 
    printf("Valores do topo da pilha 1\n");
    if (!pilha_vazia(pilha1))
        printf("%.2f\n", topo(pilha1));
    else printf("\nPilha esta vazia\n");

    printf("Valores do topo da pilha 2\n");
    if (!pilha_vazia(pilha2))
        printf("%.2f\n", topo(pilha2));
    else printf("\nPilha esta vazia\n");
    
    // concatenando pilhas:
    concatena_pilhas(pilha1, pilha2);

    printf("Valores da pilha 1\n");
    if (!pilha_vazia(pilha1))
        pilha_imprime(pilha1);
    else printf("\nPilha esta vazia\n");
    printf("\nValores da pilha 2\n");
    if (!pilha_vazia(pilha2))
        pilha_imprime(pilha2);
    else printf("\nPilha esta vazia\n");

    return 0;
}


/* ========== DECLARAÇÃO DAS FUNÇÕES ========== */
float topo(Pilha* p) {
    float v = pilha_pop(p);
    pilha_push(p, v);
    
    return v;
}

void concatena_pilhas(Pilha *p1, Pilha *p2) {
    float v;
    while (pilha_vazia(p2) == 0) {
        v = pilha_pop(p2);
        pilha_push(p1, v);
    }
}