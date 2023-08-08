#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
  
  char nome[31];
  float nota1, nota2, nota3;

} Aluno;

void preenche_dados(Aluno**, int);
void copia_dados(FILE*, Aluno**, int);

int i;

int main(void) {

  int qtd_alu;
  char nome_arquivo[100];

  printf("\nInforme o nome do arquivo: ");
  scanf(" %[^\n]", nome_arquivo);
  strcat(nome_arquivo, ".txt");

  FILE *saida = fopen(nome_arquivo, "wt");
  if (saida == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  } else {
    printf("\nArquivo aberto com sucesso!\n");
  }

  printf("Informe a quantidade de Alunos: ");
  scanf("%d", &qtd_alu);

  Aluno **var_alu = (Aluno**)malloc(qtd_alu*sizeof(Aluno*));
  if (var_alu == NULL) exit(1);

  preenche_dados(var_alu, qtd_alu);

  copia_dados(saida, var_alu, qtd_alu);

  for (i = 0; i < qtd_alu; i++) {
    free(var_alu[i]);
  }
  free(var_alu);

  fclose(saida);

  saida = fopen(nome_arquivo, "rt");


  // Leitura do arquivo:
  int s;
  while (!feof(saida)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    s = fgetc(saida);       // lê um caracter do arquivo
    printf("%c", s);
  }
  fclose(saida);
  

  return 0;
}


void preenche_dados(Aluno** alu, int num_alu) {

  for (i = 0; i < num_alu; i++) {
    
    alu[i] = (Aluno*)malloc(sizeof(Aluno));

    printf("\n===== Aluno %d =====\n", i+1);

    printf("Insira o nome: ");
    scanf(" %30[^\n]", alu[i]->nome);
    printf("Insira a primeira nota: ");
    scanf("%f", &alu[i]->nota1);
    printf("Insira a segunda nota: ");
    scanf("%f", &alu[i]->nota2);
    printf("Insira a terceira nota: ");
    scanf("%f", &alu[i]->nota3);
    
  }
}

void copia_dados(FILE *fl, Aluno **func, int num_func) {

  fprintf(fl, "%-30s\t%-10s\t%-10s\t%-s\n", "NOME", "NOTA P1", "NOTA P2", "NOTA P3");

  for (i = 0; i < num_func; i++)  {
    fprintf(fl, "%-30s\t%-10.1f\t%-10.1f\t%-.1f\n", func[i]->nome, func[i]->nota1, func[i]->nota2, func[i]->nota3);
  }
}