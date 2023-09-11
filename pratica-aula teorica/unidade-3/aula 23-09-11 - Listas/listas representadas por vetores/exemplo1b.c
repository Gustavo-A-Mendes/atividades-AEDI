#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    char **frutas = (char**)malloc(4*sizeof(char*));
    int count;
    for (count = 0; count < 4; count++) {
        frutas[count] = (char*)malloc(10*sizeof(char));
    }
    
    strcpy(frutas[0], "maca");    
    strcpy(frutas[1], "abacate");    
    strcpy(frutas[2], "uva");    
    strcpy(frutas[3], "laranja");

    for (count = 0; count < 4; count++) {
        printf("%s\n", frutas[count]);
    }   

    return 0;
}