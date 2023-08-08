#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
  
  int id;
  char nome[31];
  float salario;

} Funcionario;

void preenche_dados(Funcionario**, int);
void copia_dados(FILE*, Funcionario**, int);

int i;

int main(void) {

  int qtd_func;
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

  printf("Informe a quantidade de funcionarios: ");
  scanf("%d", &qtd_func);

  Funcionario **var_func = (Funcionario**)malloc(qtd_func*sizeof(Funcionario*));
  if (var_func == NULL) exit(1);

  preenche_dados(var_func, qtd_func);

  copia_dados(saida, var_func, qtd_func);

  for (i = 0; i < qtd_func; i++) {
    free(var_func[i]);
  }
  free(var_func);

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


void preenche_dados(Funcionario** func, int num_func) {

  for (i = 0; i < num_func; i++) {
    
    func[i] = (Funcionario*)malloc(sizeof(Funcionario));

    printf("\n===== FUNCIONARIO %d =====\n", i+1);

    printf("Insira o ID: ");
    scanf("%d", &func[i]->id);
    printf("Insira o nome: ");
    scanf(" %30[^\n]", func[i]->nome);
    printf("Insira o salario do funcionario: ");
    scanf("%f", &func[i]->salario);
    
  }
}

void copia_dados(FILE *fl, Funcionario **func, int num_func) {

  fprintf(fl, "%-5s\t%-35s\t%-s\n", "ID", "NOME", "SALARIO");

  for (i = 0; i < num_func; i++)  {
    fprintf(fl, "%-5d\t%-30s\t%-.2f\n", func[i]->id, func[i]->nome, func[i]->salario);
  }
}