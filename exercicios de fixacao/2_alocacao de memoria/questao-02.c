#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int checaOpcoesValidas(char *, char *);

int main(void) {
  int n = 0;
  printf("Quantas questoes? ");
  scanf("%d", &n);

  char **gabarito = (char **)malloc(n * sizeof(char *));
  
  for (i = 0; i < n; i++) {
    gabarito[i] = (char *)malloc(2 * sizeof(char));

    int charInvalido;
    do {
      printf("Insira o gabarito da questao %d: ", i+1);
      scanf(" %1[abcde]", gabarito[i]);
      fflush(stdin);
      charInvalido = checaOpcoesValidas("abcde", gabarito[i]);
      if (charInvalido) printf("Digite uma opcao valida!\n");
    } while (charInvalido);
    printf("deu certoo");
  
  }
  return 0;
}

int checaOpcoesValidas(char *ch1, char *ch2) {
  // char chTeste = "ABCDE";
  for (i = 0; ch1[i] != '\0'; i++) {
    if (!strcmpi(&ch1[i], ch2)) {
      return 0;
    }
  }
  return 1;
}