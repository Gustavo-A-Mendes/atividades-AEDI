#include <stdio.h>
#include "str.c"

int main () {
  char str[101], str1[51], str2[51];

  printf("Digite uma sequencia de caracteres: ");
  scanf(" %50[^\n]", str1);
  printf("Digite outra sequencia de caracteres: ");
  scanf(" %50[^\n]", str2);

  copia(str, str1);
  concatena(str, str2);

  printf("Comprimento da concatenacao: %d\n", comprimento(str));

  return 0;
}