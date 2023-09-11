#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frutas {
    char nome[10];      // Nome da fruta
    float preco;        // Preço da fruta
    struct frutas *proxima;     // Endereço da próx. fruta
} Frutas;

Frutas *insere_fruta(Frutas *fruta, char* nome, float preco) {
    // printf("\n%p\n", fruta_atual);

    Frutas *nova_fruta = (Frutas*)malloc(sizeof(Frutas));
    // printf("%p\n", nova_fruta);

    strcpy(nova_fruta->nome, nome);
    nova_fruta->preco = preco;
    nova_fruta->proxima = fruta;
    
    return nova_fruta;
    
    // static Frutas *fruta_atual;
    // strcpy(nova_fruta->nome, nome);
    // nova_fruta->proxima = NULL;
    
    // if (fruta == NULL) {
    //     fruta = nova_fruta;
    //     fruta_atual = nova_fruta;
        
    // } else {
    //     fruta_atual->proxima = nova_fruta;
    // }
    
    // fruta_atual = nova_fruta;
    // return fruta;
}

void imprime_frutas(Frutas *fruta) {
    struct frutas* p;
    for (p = fruta; p != NULL; p = p->proxima) {
        printf("%s\t%.2f\n", p->nome, p->preco);
    }
}


int main(void) {    

    Frutas *lista = NULL;

    lista = insere_fruta(lista, "maca", 2.50);
    lista = insere_fruta(lista, "abacate", 3.50);
    lista = insere_fruta(lista, "uva", 1.50);
    lista = insere_fruta(lista, "pera", 1.50);

    imprime_frutas(lista);

    free(lista);
    return 0;
}