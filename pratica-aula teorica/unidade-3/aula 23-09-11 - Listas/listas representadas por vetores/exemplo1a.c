#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char **frutas = (char**)malloc(4*sizeof(char*));
    int count;
    for (count = 0; count < 4; count++) {
        frutas[count] = (char*)malloc(10*sizeof(char));
        printf("\nInsira o nome de uma fruta: ");
        scanf(" %9[^\n]", frutas[count]);
    }
    
    for (count = 0; count < 4; count++)
    {
        printf("%s\n", frutas[count]);
    }
    

    return 0;
}