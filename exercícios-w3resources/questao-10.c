#include <stdio.h>
#include <stdlib.h>

int stringLen(char *);

int main(void) {

  char texto[25] = ""; // estabelece um tamanho maximo
  
  printf("Test Data: ");
  scanf("%[^\n]", texto);//le o resto da linha sem incluir \n

  int len = stringLen(texto);
  printf("O tamanho da string %s dada e: %d", texto, len);

  return 0;
}

int stringLen(char *str) { // str = endereço do primeiro elemento do vetor texto ( &texto[0])

   int tamanho = 0;
   while (*str != '\0') {
      tamanho++;
      str++;
   }
   return tamanho; 
}
