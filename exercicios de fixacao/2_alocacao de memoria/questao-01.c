#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mudar cor dos textos
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtReset "\x1b[0m"

int i, j;
float analisaVotos(char*, char*, char*, char*);

int main(void) {
  printf(txtReset); // reseta cor

  int n = 0;
  float F_Sim = 0, M_Nao = 0;
  printf("\nInforme o numero de pessoas entrevistadas: \n");
  scanf("%d",&n);
  
  // aloca memória para os vetores
  char *sexos = (char *)malloc(n * sizeof(char));
  if (sexos == NULL) exit(1);
  char *opinioes = (char *)malloc(n * sizeof(char));
  if (opinioes == NULL) exit(1);
  
  for (i = 0; i < n; i++) {
    printf(txtGreen "\n===== ENTREVISTADO %d =====\n" txtReset, i+1);
    
    int charInvalido;
    do {
      printf("\nSexo do entrevistado: \nM - Masculino\nF - Feminino\n");
      scanf(" %1[^\n]", sexos+i); // guarda apenas o primeiro caracter
      fflush(stdin); // limpa o buffer de saida
      // checa se o valor de entrada é um valor válido
      charInvalido = strcmpi(sexos+i, "M") && strcmpi(sexos+i, "F");
      if (charInvalido) printf(txtRed "Valor Invalido!\n" txtReset);
    } while (charInvalido);

    do {
      printf("\nVoce gostou do produto?\nS - Sim\nN - Nao\n");
      scanf(" %1[^\n]", opinioes+i);
      fflush(stdin);

      charInvalido = strcmpi(opinioes+i, "S") && strcmpi(opinioes+i, "N");
      if (charInvalido) printf(txtRed "Valor Invalido!\n" txtReset );
    } while (charInvalido);
    
    // incrementa as estatísticas desejadas
    F_Sim += analisaVotos(sexos+i, opinioes+i, "F", "S");
    M_Nao += analisaVotos(sexos+i, opinioes+i, "M", "N");

  }
  // converte para percentual
  F_Sim = (F_Sim/n)*100.0;
  M_Nao = (M_Nao/n)*100.0;

  printf("%.2f%% das mulheres gostaram do produto.\n", F_Sim);
  printf("%.2f%% dos homens nao gostaram do produto.\n", M_Nao);

  free(sexos);
  free(opinioes);

  return 0;
}

float analisaVotos(char *genero, char *opiniao, char *ch1, char *ch2) {
  float count = 0, percentual;
  if (!(strcmpi(genero, ch1) || strcmpi(opiniao, ch2))) {
    return 1;
  }
  return 0;
}
