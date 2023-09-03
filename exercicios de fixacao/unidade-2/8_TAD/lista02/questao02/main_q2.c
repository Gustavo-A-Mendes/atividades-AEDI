#include <stdio.h>
#include <stdlib.h>
#include "matriz_simples.h"
#include "matriz_vetores.h"


int main(void) {
    
    // criação da matriz a partir de ponteiros simples:
    MatrizS *mat1 = matS_cria(5, 4);    // alocando memória
    matS_atribui(mat1, 3, 2, 5.2);      // atribui valor
    printf("\nMatriz com ponteiros simples\n");
    printf(" - Numero de linhas: %d\n", matS_linhas(mat1));
    printf(" - Numero de colunas: %d\n", matS_colunas(mat1));
    printf(" - Valor em (3,2): %.2f\n", matS_acessa(mat1, 3, 2));
    
    // criação da matriz a partir de vetor de ponteiros:
    MatrizV *mat2 = matV_cria(5, 4);    // alocando memória
    matV_atribui(mat2, 3, 2, 5.2);      // atribui valor
    printf("\nMatriz com vetor de ponteiros\n");
    printf(" - Numero de linhas: %d\n", matV_linhas(mat2));
    printf(" - Numero de colunas: %d\n", matV_colunas(mat2));
    printf(" - Valor em (3,2): %.2f\n", matV_acessa(mat2, 3, 2));

    // liberando memória
    free(mat1);
    free(mat2);

    return 0;
}