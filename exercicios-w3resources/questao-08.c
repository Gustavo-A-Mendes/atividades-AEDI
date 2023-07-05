#include <stdio.h>
#include <string.h>
#include <math.h>

// Esse codigo imprimi todas as permutacoes de uma string dada, usando ponteiros
void permutaString(char *, int, int);

int main(void) {
  char string[20]; 

  printf("Escreva um conjunto de caracteres para ser permutado: ");
  scanf("%s", &string);
  int n = strlen(string);
  permutaString(string, 0, n-1);
  printf("\n\n");

  return 0;
}

void mudaPosicao(char *ch1, char *ch2) {
  int temp;

  temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}

void permutaString(char *cht, int ch_inicial, int ch_final) {
  static int count = 0;
  int m = strlen(cht);

  // imprime a permutacao
  if (ch_inicial == ch_final) {
    printf("%s\t", cht);
    
    // Organiza os valores impressos no terminal da melhor forma possivel
    count++; 
    if (m <= 6) {
      if (count == floor(pow(m, 2)/2)) {
        printf("\n\n");
        count = 0;
      }
    } else {
      if (count == 20) {
        printf("\n\n");
        count = 0;
      }
    }

  } else {
    for (int i = ch_inicial; i <= ch_final; i++) {
      mudaPosicao(cht+i, cht+ch_inicial);
      permutaString(cht, ch_inicial + 1, ch_final);
      mudaPosicao(cht+i, cht+ch_inicial);
    }
  }
}
