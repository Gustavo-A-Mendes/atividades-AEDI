#include <stdio.h>

union tipo { 
    int inteiro; 
    float real; 
    char caractere; 
};

typedef union tipo Tipo;

int main() { 
    Tipo t; 
    t.inteiro = 10; 
    printf("inteiro: %d \t real: %f \t caractere: %c\n", t.inteiro, t.real, t.caractere);
    t.real = 10.5;
    printf("inteiro: %d \t real: %f \t caractere: %c\n", t.inteiro, t.real, t.caractere);
    t.caractere = 'a';
    printf("inteiro: %d \t real: %f \t caractere: %c\n", t.inteiro, t.real, t.caractere);
    return 0;
}