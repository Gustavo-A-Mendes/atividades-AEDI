#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void copia_dados(FILE*);

int i;

int main(void) {

  FILE *saida = fopen("frutas.txt", "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

  copia_dados(saida);

  fclose(saida);



  // Leitura do arquivo:
  printf("\n");
  
  saida = fopen("frutas.txt", "rt");
  int s;
  while (!feof(saida)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    s = fgetc(saida);       // lê um caracter do arquivo
    printf("%c", s);
  }
  
  printf("\nTodas as frutas foram cadastradas.\nObrigado por usar nosso programa\n");
  
  fclose(saida);
  

  return 0;
}


void copia_dados(FILE *fl) {
  
  fprintf(fl, "%s,%s\n", "NOME", "PRECO");

  while (1) {
    int count_fruta = 0;
    char nome[21], resp[2];
    float preco;

    printf("\n===== Fruta %d =====\n", i+1);
    printf("Insira o nome: ");
    scanf(" %20[^\n]", nome);
    printf("Insira o preco: ");
    scanf("%f", &preco);

    fprintf(fl, "%s,%-.2f\n", nome, preco);

    printf("\nDeseja continuar? [S / N]\n");
    scanf(" %1[^\n]", resp);
    resp[0] = toupper(resp[0]);

    if (resp[0] == 'S') {
      i++;
    } else break;
  }
}