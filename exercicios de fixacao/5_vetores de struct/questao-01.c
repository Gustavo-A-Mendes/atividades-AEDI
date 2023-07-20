#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  Esse programa cria um tipo estruturado para cadastrar dados de pessoas.
  O programa deve imprimir esses dados, permitir que alteremos algum dado
  e verificar o nome da pessoa de maior idade e menor idade.
*/

// Variáveis para mudar cor dos textos:
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtYellow "\x1b[33m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

#define MAX_TURMAS 10
#define MAX_VAGAS 10

// Tipo estruturado para armazenar os dados da pessoa:
typedef struct aluno {
  int mat;
  char nome[81];
  float notas[3];
  float media;
} Aluno;

typedef struct turma {
 char id; /* caractere que identifica a turma, por exemplo, A ou B */
 int vagas; /* números de vagas disponíveis para fechar a turma */
 Aluno* alunos[MAX_VAGAS];
} Turma;

Turma** turmas;


// protótipo das funções criadas:
void inicializa(void);

void menu(Turma **);
Turma *cria_turma (char);
void matricula_aluno(Turma *, int, char*);
void lanca_notas(Turma *);

int count_turmas = 0;
int i;

int main(void) {
  printf(txtReset);
  
  inicializa();
  

  printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
  printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de todas e listagem de alunos.\n");
  printf("Autor: Gustavo Mendes Versao: 1.0\n");

  menu(turmas);

  return 0;
}

void inicializa(void) {
  turmas = (Turma**)calloc(MAX_TURMAS, sizeof(Turma*));
  if (turmas == NULL) exit(1); // Se não conseguir alocar

  for (i = 0; i < MAX_TURMAS; i++) {
    turmas[i] = (Turma*)calloc(1, sizeof(Turma));
    if (turmas[i] == NULL) exit(1); // Se não conseguir alocar
  }
}

void menu(Turma **turma) {
  int n;
  
  while (n != 6) {
    printf("\nMENU:\n");

    printf("1 - Criar turma\n");
    printf("2 - Listar turma\n");
    printf("3 - Matricular aluno\n");
    printf("4 - Lancar nota\n");
    printf("5 - Listar alunos\n");
    printf("6 - Sair\n");
    printf("\nDigite sua opcao: ");
    scanf("%d", &n);


    int valMAT;
    char chNOME[81];
    char chID[2];
    
    switch (n) {
      case 1:
        printf("\nCriando nova turma...\n");
        printf("Digite um id: ");
        scanf(" %1[^\n]", chID);
        turma[count_turmas] = cria_turma(chID[0]);
        break;
      case 2:
        // imprime_turma();
        break;
      case 3:
        printf("%c", turma[0]->id);
        printf("\nMatriculando aluno...\n");
        printf("Digite um id da turma: ");
        scanf(" %1[^\n]", chID);
        printf("Digite a matricula: ");
        scanf("%d", &valMAT);
        printf("Digite o nome: ");
        scanf(" %80[^\n]", chNOME);

        for (i = 0; i < MAX_TURMAS; i++) {
          if (i < 0 || i > MAX_TURMAS) {
            printf("Indice fora do limite do vetor\n");
            exit(1); // aborta o programa
          }
          
          // if (turmas[i]->id == *chID) {
          //   printf("oi");
          //   matricula_aluno(turmas[i], valMAT, chNOME);
          // }
        }
        
        break;
      case 4:
        /* code */
        break;
      case 5:
        /* code */
        break;
      case 6:
        /* code */
        break;

      default:
        break;
    }
  }
}


Turma *cria_turma (char id) {
  turmas[count_turmas]->id = id;
  
  // for (i = 0; i < MAX_VAGAS; i++) {
  //   turmas[count_turmas]->alunos[i] = NULL;
  // }

  printf("Turma %c criada com sucesso!\n", turmas[count_turmas]->id);
  count_turmas++;
}


void matricula_aluno(Turma *turma, int mat, char *nome) {
  int count_alunos = 0;
  for (i = 0; i < MAX_VAGAS; i++) {
    turma->alunos[i] = (Aluno*)malloc(sizeof(Aluno));
  }

  if (mat - 1 < 0 || mat - 1 >= MAX_VAGAS) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }
  if ((turma->alunos[mat]) == NULL) {
    turma->alunos[mat]->nome;
  }

}


// void lanca_notas(Turma *turmas) {
//   int i;
//   if (i < 0 || i > MAX_TURMAS) {
//     printf("Indice fora do limite do vetor\n");
//     exit(1); // aborta o programa
//   }
//   if ((turmas+i) == NULL) {
//     printf("\n========== CADASTRO %d ==========\n", i+1);

//     printf("Entre com a matricula: ");
//     scanf("%d", &turmas[i]->mat);
//     printf("Entre com o nome: ");
//     scanf(" %80[^\n]", &turmas[i]->nome);
//     printf("Entre com o endereco: ");
//     scanf(" %120[^\n]", &turmas[i]->end);
//     printf("Entre com o telefone: ");
//     scanf(" %20[^\n]", &turmas[i]->tel);
//   }

// }



// /*
//   Função para verificar se o valor de resposta é valido ou não:
// */
// int checaValido(char *ch1) {
//   *ch1 = toupper(*ch1); 
//   if (*ch1 == 'S' || *ch1 == 'N') {
//     return 0;
//   }
//   return 1;
// }