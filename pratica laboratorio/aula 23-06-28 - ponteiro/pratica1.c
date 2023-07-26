#include <stdio.h>

int main(void) {

    int x = 2;      // inicializa variável "x" com valor 2
    int *p = &x;    // ponteiro aponta para x
    printf("%d \n", *p);

    return 0;
}