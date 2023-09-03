#include <stdio.h>
#include <stdlib.h>
#include "matriz_vetores.h"

struct matriz_vetores
{
    int lin;
    int col;
    float **v;
};

MatrizV *matV_cria(int m, int n)
{
    MatrizV *mat = (MatrizV*)malloc(sizeof(MatrizV));
    if (mat == NULL) exit(1);
    mat->lin = m;
    mat->col = n;
    mat->v = (float**)malloc(m*sizeof(float*));
    if (mat->v == NULL) exit(1);
    int i;
    for (i = 0; i < m; i++) {
        mat->v[i] = (float*)malloc(n*sizeof(float));
        if (mat->v[i] == NULL) exit(1);
    }
    
    return mat;
}

void matV_libera(MatrizV *mat)
{
    int i, j;
    for (i = 0; i < mat->lin; i++) {
        free(mat->v[i]);
    }
    free(mat->v);
    free(mat);
}

float matV_acessa(MatrizV *mat, int i, int j)
{
    return mat->v[i][j];

}

void matV_atribui(MatrizV *mat, int i, int j, float v)
{
    mat->v[i][j] = v;
}

int matV_linhas(MatrizV *mat)
{
    return mat->lin;
}

int matV_colunas(MatrizV *mat)
{
    return mat->col;
}
