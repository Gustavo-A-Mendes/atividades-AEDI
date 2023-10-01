#include <stdio.h>
#include "calc.c"

int main(void) {
    char c;
    float v;
    Calc *calc;

    /* cria calculadora com formato de duas casas decimais */
    calc = calc_cria("%.2f\n");

    do {
        /* lê próximo caracter não branco */
        scanf(" %c", &c);
        /* verifica se é operador válido */
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            calc_operador(calc, c);
        }
        /* devolve caracter lido e tenta ler número */
        else {
            ungetc(c, stdin);
            if (scanf("%f", &v) == 1)
                calc_operando(calc, v);
        }

    } while (c != 'q');
    calc_libera(calc);
    
    return 0;
}