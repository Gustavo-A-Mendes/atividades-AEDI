#include <stdio.h>
#include <stdlib.h>
#include "matriz_simples.h"

struct matriz_simples
{
    int lin;
    int col;
    float *v;
};

MatrizS *matS_cria(int m, int n)
{
    MatrizS *mat = (MatrizS*)malloc(sizeof(MatrizS));
    if (mat == NULL) exit(1);
    mat->lin = m;
    mat->col = n;
    mat->v = (float*)malloc((m*n)*sizeof(float));
    if (mat->v == NULL) exit(1);
    
    return mat;
}

void matS_libera(MatrizS *mat)
{
    free(mat->v);
    free(mat);
}

float matS_acessa(MatrizS *mat, int i, int j)
{   
    int lin = mat->lin;
    return mat->v[i*lin + j];
}

void matS_atribui(MatrizS *mat, int i, int j, float v)
{   
    int lin = mat->lin;
    mat->v[i*lin + j] = v;
}

int matS_linhas(MatrizS *mat)
{
    return mat->lin;
}

int matS_colunas(MatrizS *mat)
{
    return mat->col;
}
