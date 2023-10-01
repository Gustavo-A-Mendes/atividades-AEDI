/* TAD calc() */
/* Arquivo que define a interface da calculadora */

/* Tipo exportado */
typedef struct calc Calc;

/* Funções exportadas */

/* Função calc_cria

*/
Calc *calc_cria(char *formato);

/* Função calc_operando

*/
void calc_operando(Calc *c, float v);

/* Função calc_operador

*/
void calc_operador(Calc *c, char op);

/* Função calc_libera

*/
void calc_libera(Calc *c);