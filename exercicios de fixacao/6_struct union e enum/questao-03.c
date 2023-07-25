#include <stdio.h>
#include <stdlib.h>


typedef enum mes {
  JANEIRO = 1, FEVEREIRO, MARCO,
  ABRIL, MAIO, JUNHO, JULHO,
  AGOSTO, SETEMBRO, OUTUBRO,
  NOVEMBRO, DEZEMBRO
} Mes;

typedef struct data {
  int dia;
  Mes mes;
  int ano;
} Data;

int diaValido(int, int, int);


int main(void) {

  Data data;

  printf("Digite o ano: ");
  scanf("%d", &data.ano);
  fflush(stdin);

  printf("\n1 - JANEIRO\t");
  printf("2 - FEVEREIRO\t");
  printf("3 - MARCO\t");
  printf("4 - ABRIL\n");
  printf("5 - MAIO\t");
  printf("6 - JUNHO\t");
  printf("7 - JULHO\t");
  printf("8 - AGOSTO\n");
  printf("9 - SETEMBRO\t");
  printf("10 - OUTUBRO\t");
  printf("11 - NOVEMBRO\t");
  printf("12 - DEZEMBRO\n\n");
  printf("Digite o mes [1 - 12]: ");
  scanf("%d", &data.mes);
  fflush(stdin);
  
  // meses com 31 dias: 01, 03, 05, 07, 08, 10, 12
  // meses com 30 dias: 04, 06, 09, 11
  // meses com 30 dias: 02
  
  int valido = 0;
  while (!valido) {
  if (data.mes == 2) {
    printf("Digite o dia [1 - 28]: ");
  } else if ((data.mes == 4) || (data.mes == 6) || (data.mes == 9) || (data.mes == 11)) {
    printf("Digite o dia [1 - 30]: ");
  } else {
    printf("Digite o dia [1 - 31]: ");
  }
    scanf("%d", &data.dia);
    fflush(stdin);

    valido = diaValido(data.ano, data.mes, data.dia);
  }

  printf("\nData: %d/%d/%d", data.dia, data.mes+1, data.ano);

  return 0;
}

// Função para filtrar o dia máximo dependendo do mês
int diaValido(int ano, int mes, int dia) {
  if ((mes == 2) && (dia > 28)) {
    return 0;
  } else if (((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) && (dia > 30)) {
    return 0;
  } else if (dia > 31) {
    return 0;
  } else {
    return 1;
  }
}