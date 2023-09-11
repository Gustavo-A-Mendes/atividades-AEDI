#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frutas {
    char nome[10];      // Nome da fruta
    struct frutas *proxima;     // Endereço da próx. fruta
};

int main(void) {

    struct frutas *fruta1 = (struct frutas *)malloc(sizeof(struct frutas));
    struct frutas *fruta2 = (struct frutas *)malloc(sizeof(struct frutas));
    struct frutas *fruta3 = (struct frutas *)malloc(sizeof(struct frutas));
    if (fruta1 == NULL || fruta2 == NULL || fruta3 == NULL) exit(1);

    // Inicializa os nomes das frutas:
    strcpy(fruta1->nome, "maca");
    strcpy(fruta2->nome, "abacate");
    strcpy(fruta3->nome, "uva");
    // Faz o encadeamento dos espaços:
    fruta1->proxima = fruta2;
    fruta2->proxima = fruta3;
    fruta3->proxima = NULL;

    struct frutas* p;
    for (p = fruta1; p != NULL; p = p->proxima) {
        printf("%s\n", p->nome);
    }
    
    // printf("%s\t%s\t%s\t%s", fruta1->nome, fruta1->proxima->nome, fruta1->proxima->proxima->nome, fruta1->proxima->proxima->proxima->nome);

    free(fruta1);
    free(fruta2);
    free(fruta3);
    return 0;
}