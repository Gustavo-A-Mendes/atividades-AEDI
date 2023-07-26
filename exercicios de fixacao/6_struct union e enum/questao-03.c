#include <stdio.h>
#include <stdlib.h>

/*
  Esse programa implementa uma struct Data com parâmetros "dia", "mes" e "ano",
  sendo mes armazenado em um enum com valores referentes a cada mês. 
  Com isso, o programa lê a data e imprimir a data no formato dd/mm/aaaa.
*/

// declaração do tipo enumerado para os meses: 
typedef enum mes {
  JANEIRO = 1, FEVEREIRO, MARCO,
  ABRIL, MAIO, JUNHO, JULHO,
  AGOSTO, SETEMBRO, OUTUBRO,
  NOVEMBRO, DEZEMBRO
} Mes;

// declaração do tipo estruturado para a data:
typedef struct data {
  int dia;
  Mes mes;
  int ano;
} Data;

// variáveis globais:
int dia_valido(int, int, int);
int mes_selecionado(int);
Data data;

int main(void) {

  int mes;

  printf("Digite o ano: ");
  scanf("%d", &data.ano);
  fflush(stdin); // limpa o buffer de entrada

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
  scanf("%d", &mes);
  fflush(stdin);

  data.mes = mes_selecionado(mes);
  

  // meses com 31 dias: 01, 03, 05, 07, 08, 10, 12
  // meses com 30 dias: 04, 06, 09, 11
  // meses com 30 dias: 02
  int valido = 0;

  while (!valido) {
    // cria um print personalizado para cada mês:
    int dia_maximo;
    if (data.mes == 2) {
      dia_maximo = 28;
    } else if ((data.mes == 4) || (data.mes == 6) || (data.mes == 9) || (data.mes == 11)) {
      dia_maximo = 30;
    } else {
      dia_maximo = 31;
    }

    printf("Digite o dia [1 - %d]: ", dia_maximo);
    scanf("%d", &data.dia);
    fflush(stdin);

    valido = dia_valido(data.ano, data.mes, data.dia);
  }

  // imprime a data, com a formatação dd/mm/aaaa:
  printf("\nData: %02d/%02d/%04d", data.dia, data.mes, data.ano);

  return 0;
}

// Função que compara a entrada para mês com o enum
int mes_selecionado(int mes) {
  if (mes == JANEIRO) {
    data.mes = JANEIRO;
  } else if (mes == FEVEREIRO) {
    data.mes = FEVEREIRO;
  } else if (mes == MARCO) {
    data.mes = MARCO;
  } else if (mes == ABRIL) {
    data.mes = ABRIL;
  } else if (mes == MAIO) {
    data.mes = MAIO;
  } else if (mes == JUNHO) {
    data.mes = JUNHO;
  } else if (mes == JULHO) {
    data.mes = JULHO;
  } else if (mes == AGOSTO) {
    data.mes = AGOSTO;
  } else if (mes == SETEMBRO) {
    data.mes = SETEMBRO;
  } else if (mes == OUTUBRO) {
    data.mes = OUTUBRO;
  } else if (mes == NOVEMBRO) {
    data.mes = NOVEMBRO;
  } else if (mes == DEZEMBRO) {
    data.mes = DEZEMBRO;
  }
}

// Função para filtrar o dia máximo dependendo do mês
int dia_valido(int ano, int mes, int dia) {
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