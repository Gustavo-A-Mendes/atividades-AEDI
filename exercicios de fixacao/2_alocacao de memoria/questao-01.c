#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int i, j;
int analisaVotos(int, char**, char**, char*, char*);

int main(void) {
  int n = 0;
  printf("\nInforme o numero de pessoas que vao votar: \n");
  scanf("%d",&n);
  
  char **generos = (char **)malloc(n * sizeof(char *));
  char **opinioes = (char **)malloc(n * sizeof(char *));
  
  for (i = 0; i < n; i++) {
    int charInvalido;
    
    generos[i] = (char *)malloc(2 * sizeof(char));
    do {
      printf("\ngenero [M/F]: ");
      scanf(" %1[^\n]", generos[i]); // guarda apenas o primeiro caracter
      fflush(stdin); // limpa o buffer de saida

      charInvalido = strcmpi(generos[i], "M") && strcmpi(generos[i], "F");
      if (charInvalido) printf("Digite uma opcao valida!\n");
    } while (charInvalido);

    opinioes[i] = (char *)malloc(2 * sizeof(char));
    do {
      printf("Voce gostou do produto? [S/N]: ");
      scanf(" %1[^\n]", opinioes[i]);
      fflush(stdin);
      charInvalido = strcmpi(opinioes[i], "S") && strcmpi(opinioes[i], "N");
      if (charInvalido) printf("Digite uma opcao valida!\n");
    } while (charInvalido); 
  }

  int F_Sim = analisaVotos(n, generos, opinioes, "F", "S");
  int M_Nao = analisaVotos(n, generos, opinioes, "M", "N");
  printf("%d%% das mulheres gostaram\n", F_Sim);
  printf("%d%% dos homens nao gostaram\n", M_Nao);

  return 0;
}

int analisaVotos(int qnt, char **genero, char **opiniao, char *ch1, char *ch2) {
  float count = 0, percentual;
  for (i=0; i < qnt; i++) {
    for (j = 0; genero[i][j] != '\0' < count; j++) {
      // printf("%s\t%s\n", &genero[i][j], &opiniao[i][j]);
      if (!(strcmpi(&genero[i][j], ch1) || strcmpi(&opiniao[i][j], ch2))) {
        count++;
      };
    }
  }
  percentual = 100 * (count/qnt);
  return percentual;
}
