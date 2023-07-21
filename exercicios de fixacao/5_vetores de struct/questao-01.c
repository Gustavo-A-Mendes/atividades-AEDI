#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 10

// Tipo estruturado para armazenar os dados da aluno:
typedef struct aluno {
  int mat;
  // char *nome;
  char nome[81];
  float notas[3];
  float media;
} Aluno;

// Tipo estruturado para armazenar os dados das turmas:
typedef struct turma {
 int id; /* caractere que identifica a turma, por exemplo, A ou B */
 int vagas; /* números de vagas disponíveis para fechar a turma */
 Aluno* alunos[MAX_VAGAS];
} Turma;

Turma *turmas[MAX_TURMAS];


// protótipo das funções criadas:
void inicializa(Turma **);
void menu(void);
Turma *cria_turma (char);
void matricula_aluno(Turma *, int, char*);
void lanca_notas(Turma *);
void imprime_alunos(Turma*);
void imprime_turmas(Turma**, int);
Turma *procura_turma(Turma**, int, char);
void exclui_turma(Turma**, int);
void copia_valores(Turma*, Turma*);



int count_turmas = 0;
int i, j;

int main(void) {
  
  inicializa(turmas);
  

  printf("\n\nBem-vindo ao Programa de Gerenciamento de Turmas!\n");
  printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de todas e listagem de alunos.\n");
  printf("Autor: Gustavo Mendes Versao: 1.0\n");

  menu();

  for (i = 0; i < MAX_TURMAS; i++) {
    for (j = 0; j < MAX_VAGAS; j++) {
      free(turmas[i]->alunos[j]);
    }
    free(turmas[i]);
  }
  
  return 0;
}


void inicializa(Turma **t) {
  for (i = 0; i < MAX_TURMAS; i++) {
    t[i] = NULL;
  }
}


void menu(void) {
  int n;
  
  while (n != 7) {
    printf("\nMENU:\n");

    printf("1 - Criar turma\n");
    printf("2 - Listar turma\n");
    printf("3 - Matricular aluno\n");
    printf("4 - Lancar notas\n");
    printf("5 - Listar alunos\n");
    printf("6 - Excluir turma\n");
    printf("7 - Sair\n");
    printf("\nDigite sua opcao: ");
    scanf("%d", &n);
    

    int valMAT;
    int indice;
    char chNOME[81];
    char chID[2];
    Turma *turma;
    
    switch (n) {
      case 1:
        printf("\nCriando nova turma...\n");
        printf("Digite um id: ");
        scanf(" %1[^\n]", chID);
        chID[0] = toupper(chID[0]);
        
        if (count_turmas >= 1) {
          turma = procura_turma(turmas, count_turmas, chID[0]);
          if (turma == NULL) {
            turmas[count_turmas++] = cria_turma(chID[0]);
          } else {
            printf("Turma %s ja existe", chID);
          }
        } else {
          turmas[count_turmas++] = cria_turma(chID[0]);
        }

        break;
      case 2:
        imprime_turmas(turmas, count_turmas);
        break;
      case 3:
        printf("\nMatriculando aluno...\n");
        printf("Digite um id da turma: ");
        scanf(" %1[^\n]", chID);
        chID[0] = toupper(chID[0]);
        
        turma = procura_turma(turmas, count_turmas, chID[0]);
        
        if (turma != NULL) {
          printf("Digite a matricula: ");
          scanf("%d", &valMAT);
          printf("Digite o nome: ");
          scanf(" %80[^\n]", chNOME);
          matricula_aluno(turma, valMAT, chNOME);
          turma->vagas--;
        } else {
          printf("Turma %s Inexistente!\n", chID);

        }
        break;
      case 4:
        printf("\nLancando notas...\n");
        printf("Digite o id da turma: ");
        scanf(" %1[^\n]", chID);
        chID[0] = toupper(chID[0]);

        turma = procura_turma(turmas, count_turmas, chID[0]);
        
        if (turma != NULL) lanca_notas(turma);
        else printf("Turma %s Inexistente!\n", chID);
        break;
      case 5:
        printf("\nListando alunos...\n");
        printf("Digite o id da turma: ");
        scanf(" %1[^\n]", chID);
        chID[0] = toupper(chID[0]);

        turma = procura_turma(turmas, count_turmas, chID[0]);

        if (turma != NULL) imprime_alunos(turma);
        else printf("Turma %s Inexistente!\n", chID);
        break;
      case 6:
        printf("\nExcluindo turma...\n");
        printf("Digite o id da turma: ");
        scanf(" %1[^\n]", chID);
        chID[0] = toupper(chID[0]);

        turma = procura_turma(turmas, count_turmas, chID[0]);
        
        for (i = 0; i < count_turmas; i++) {
          if (turmas[i]->id == chID[0]) {
            indice = i;
          }
        }
        
        if (turma != NULL) exclui_turma(turmas, indice);
        else printf("Turma %s Inexistente!\n", chID);

        count_turmas--;
        break;
      case 7:
        printf("\nObrigado por usar este programa!");
        break;

      default:
        printf("Valor Invalido! Tente Novamente.\n");
        break;
    }
  }
}


Turma *cria_turma (char id) {
  if (count_turmas < 0 || count_turmas >= MAX_TURMAS) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }
  
  if (turmas[count_turmas] == NULL) {
    turmas[count_turmas] = (Turma*)malloc(sizeof(Turma));
    if (turmas[count_turmas] == NULL) exit(1); // Se não conseguir alocar
    
    for (i = 0; i < MAX_VAGAS; i++) {
      turmas[count_turmas]->alunos[i] = NULL;
    }
  }

  id = toupper(id);

  turmas[count_turmas]->id = id;
  turmas[count_turmas]->vagas = MAX_VAGAS;
  
  printf("Turma %c criada com sucesso!\n", turmas[count_turmas]->id);
  return turmas[count_turmas];
}


Turma *procura_turma(Turma** turma, int n, char id) {
  for (i = 0; i < n; i++) {
    if (turma[i]->id == id) {
      return turma[i];
    }
  }
  return NULL;
}


void imprime_turmas(Turma** t, int n) {
  int vagasCount = 0;
  printf("\nListando turmas...\n");
  if(n != 0) {
  for (i = 0; i < n; i++) {
      printf("TURMA %c - %d vagas disponiveis\n", t[i]->id, t[i]->vagas);
  }
  } else {
    printf("Nao ha turmas criadas!\n");
  }
}


void matricula_aluno(Turma *turma, int mat, char *nome) {

  int count_alunos = MAX_VAGAS - turma->vagas;

  if (count_alunos < 0 || count_alunos >= MAX_VAGAS) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }

  if (turma->alunos[count_alunos] == NULL) {
    turma->alunos[count_alunos] = (Aluno*)calloc(1, sizeof(Aluno));
    if (turma->alunos[count_alunos] == NULL) exit(1); // Se não conseguir alocar    
  } else {
    printf("Matrícula já existente!");
  }
  turma->alunos[count_alunos]->mat = mat;
  strcpy(turma->alunos[count_alunos]->nome, nome);


  printf("Aluno %s matriculado com sucesso!\n", turma->alunos[count_alunos]->nome);
  
}


void lanca_notas(Turma *turma) {
  if (turma->vagas < MAX_VAGAS) {
    for (i = 0; i < (MAX_VAGAS - turma->vagas); i++) {
      Aluno *aluno = turma->alunos[i];
      aluno->media = 0;
      printf("Matricula: %d\tAluno: %s\n", aluno->mat, aluno->nome);
      for (j = 0; j < 3; j++) {
        aluno->notas[j] = 0;
        printf("Digite a nota %d: ", j+1);
        scanf("%f", &(aluno->notas[j]));
        aluno->media += aluno->notas[j];
      }
      
      aluno->media = aluno->media / 3;
    }
  } else {
    printf("Nao ha alunos matriculados na turma %c.\n", turma->id);
  }
}


void imprime_alunos(Turma *turma) {
  if (turma->vagas < MAX_VAGAS) {
    for (i = 0; i < (MAX_VAGAS - turma->vagas); i++) {
      Aluno *aluno = turma->alunos[i];
      printf("Matricula: %d\n", aluno->mat);
      printf("Nome: %s\n", aluno->nome);
      printf("Media: %.1f\n", aluno->media);
    }
  } else {
    printf("Nao ha alunos matriculados na turma %c.\n", turma->id);
  }
}


void exclui_turma(Turma **t, int indice) {
  if(t[indice]->vagas == MAX_VAGAS) {
    printf("Turma %c excluida!\n", t[indice]->id);
    free(t[indice]);

    for (i = indice; i < count_turmas; i++) {
      copia_valores(t[i], t[i+1]);
      // t[i] = t[i+1];
      // if (i == indice - 2) {
      //   t[i+1] = NULL;
      //   free(t[i+1]);   
      // }
    }
  } else {
    printf("Ha alunos matriculados! Nao foi possivel excluir a turma.");
  }
}

void copia_valores(Turma *turma_dst, Turma *turma_src) {
  
  memcpy(turma_dst->alunos, turma_src->alunos, sizeof(Aluno));
  memcpy(&turma_dst->id, &turma_src->id, sizeof(turma_dst->id));
  memcpy(&turma_dst->vagas, &turma_src->vagas, sizeof(turma_dst->vagas));

  
}