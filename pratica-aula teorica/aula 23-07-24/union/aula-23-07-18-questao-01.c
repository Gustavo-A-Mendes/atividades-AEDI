#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 10

typedef union indice {
  float IG, IRA, IRT;
} Indices;

// Tipo estruturado para armazenar os dados da aluno:
typedef struct aluno {
  int mat;
  char nome[81];
  float notas[3];
  float media;
  Indices indice;
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
int procura_aluno(Turma *, int);
void lanca_notas(Turma *);
void indice_aluno (Aluno*);
void imprime_alunos(Turma*);
void imprime_turmas(Turma**, int);
Turma *procura_turma(Turma**, int, char);
void exclui_turma(Turma**, int);

int count_turmas = 0;
int i, j;


/*
  Esse programa é destinado a auxiliar o docente. Suas ferramentas permitem
  criar novas turmas ou excluir turmas vazias, matricular alunos e lançar suas
  notas, bem como vizualizar o status das turmas criadas e de seus alunos.
*/
int main(void) {
  
  // Limpa a estrutura Turmas.
  inicializa(turmas);
  
  printf("\n\nBem-vindo ao Programa de Gerenciamento de Turmas!\n");
  printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de todas e listagem de alunos.\n");
  printf("Autor: Gustavo Mendes Versao: 1.0\n");

  // Interface com as ferramentas
  menu();

  // libera a memória.
  for (i = 0; i < MAX_TURMAS; i++) {
    free(turmas[i]);
  }

  return 0;
}

/*
  Função que inicia a estrutura Turmas com valores nulos.
*/
void inicializa(Turma **t) {
  for (i = 0; i < MAX_TURMAS; i++) {
    t[i] = NULL;
  }
}

/*
  Função que cria uma interface, com uma lista de opções 
  para o usuário escolher entre as diversas ferramentas.
*/
void menu(void) {
  int n = 0;
  
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
    fflush(stdin);

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
        fflush(stdin);
        chID[0] = toupper(chID[0]);
        
        if (count_turmas < 1) {
          turmas[count_turmas] = cria_turma(chID[0]);
          count_turmas++;
        } else if (count_turmas < MAX_TURMAS) {
          turma = procura_turma(turmas, count_turmas, chID[0]);
          if (turma == NULL) {
            turmas[count_turmas] = cria_turma(chID[0]);
            count_turmas++;
          } else {
            printf("Turma %s ja existe", chID);
          }
        } else {
          printf("Numero maximo de turmas atingido!\n");
        }
        break;
      
      case 2:
        imprime_turmas(turmas, count_turmas);
        break;
      
      case 3:
        printf("\nMatriculando aluno...\n");
        printf("Digite um id da turma: ");
        scanf(" %1[^\n]", chID);
        fflush(stdin);
        chID[0] = toupper(chID[0]);
        
        turma = procura_turma(turmas, count_turmas, chID[0]);
        
        if (turma != NULL) {
          printf("Digite a matricula: ");
          scanf("%d", &valMAT);
          fflush(stdin);
          
          if (procura_aluno(turma, valMAT)) {
            printf("Aluno ja se encontra matriculado!\n");
          } else {
            printf("Digite o nome: ");
            scanf(" %80[^\n]", chNOME);
            fflush(stdin);
            matricula_aluno(turma, valMAT, chNOME);
          }
        } else {
          printf("Turma %s Inexistente!\n", chID);
        }
        break;
      
      case 4:
        printf("\nLancando notas...\n");
        printf("Digite o id da turma: ");
        scanf(" %1[^\n]", chID);
        fflush(stdin);
        chID[0] = toupper(chID[0]);

        turma = procura_turma(turmas, count_turmas, chID[0]);
        
        if (turma != NULL) lanca_notas(turma);
        else printf("Turma %s Inexistente!\n", chID);
        break;
      
      case 5:
        printf("\nListando alunos...\n");
        printf("Digite o id da turma: ");
        scanf(" %1[^\n]", chID);
        fflush(stdin);
        chID[0] = toupper(chID[0]);

        turma = procura_turma(turmas, count_turmas, chID[0]);

        if (turma != NULL) imprime_alunos(turma);
        else printf("Turma %s Inexistente!\n", chID);
        break;
      
      case 6:
        printf("\nExcluindo turma...\n");
        printf("Digite o id da turma: ");
        scanf(" %1[^\n]", chID);
        fflush(stdin);
        chID[0] = toupper(chID[0]);

        turma = procura_turma(turmas, count_turmas, chID[0]);
        
        for (i = 0; i < count_turmas; i++) {
          if (turmas[i]->id == chID[0]) {
            indice = i;
          }
        }
        
        if (turma != NULL) {
          exclui_turma(turmas, indice);
        }
        else printf("Turma %s Inexistente!\n", chID);
        break;
      
      case 7:
        printf("\nObrigado por usar este programa!\n");
        break;
      
      default:
        printf("Valor Invalido! Tente Novamente.\n");
        break;
    }
  }
}

/*
  Função que cria uma nova turma, alocando memória para a
  struct, caso o limite de turma não for atingido.
*/
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
    
    id = toupper(id);

    turmas[count_turmas]->id = id;
    turmas[count_turmas]->vagas = MAX_VAGAS;
    
    printf("Turma %c criada com sucesso!\n", turmas[count_turmas]->id);
    
    return turmas[count_turmas];
  }
}

/*
  Função que procura um turma entre as turmas criadas
  por meio do seu ID
*/
Turma *procura_turma(Turma** turma, int n, char id) {
  for (i = 0; i < n; i++) {
    if (turma[i]->id == id)  return turma[i];
  }
  return NULL;
}

/*
  Função que imprime todas as turmas criadas
*/
void imprime_turmas(Turma** t, int n) {
  // printf("%d", count_turmas);
  printf("\nListando turmas...\n");
  if(n != 0) {
    for (i = 0; i < n; i++) {
      printf("TURMA %c - %d vagas disponiveis\n", t[i]->id, t[i]->vagas);
    }
  } else {
    printf("Nao ha turmas criadas!\n");
  }
}

/*
  Função que matricula um aluno em uma turma existente,
  caso o limite de vagas não seja excedido.
*/
void matricula_aluno(Turma *turma, int mat, char *nome) {

  int count_alunos = MAX_VAGAS - turma->vagas;

  if (count_alunos < 0) {
    printf("Indice fora do limite do vetor\n");
    exit(1); // aborta o programa
  }
  else if ((turma->alunos[count_alunos] == NULL) && (count_alunos < MAX_VAGAS)) {
    turma->alunos[count_alunos] = (Aluno*)calloc(1, sizeof(Aluno));
    if (turma->alunos[count_alunos] == NULL) exit(1); // Se não conseguir alocar    
    
    turma->alunos[count_alunos]->mat = mat;
    strcpy(turma->alunos[count_alunos]->nome, nome);

    printf("Aluno %s matriculado com sucesso!\n", turma->alunos[count_alunos]->nome);

    turma->vagas--;
  } 
  else {
    printf("Limite maximo de alunos excedido!\n");
  }
}

/*
  Função que verifica se um aluno já está matriculado
  na turma.
*/
int procura_aluno(Turma *turma, int mat) {
  int vagaOcupada = MAX_VAGAS - turma->vagas;

  if (vagaOcupada != 0) {
    for (i = 0; i < vagaOcupada; i++) {
      if (turma->alunos[i]->mat == mat) return 1;
    }
  }
  return 0;
}

/*
  Função usada para registrar as notas dos alunos.
*/
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
        fflush(stdin);
        aluno->media += aluno->notas[j];
      }
      indice_aluno(aluno);
      aluno->media = aluno->media / 3;
    }
  } else {
    printf("Nao ha alunos matriculados na turma %c.\n", turma->id);
  }
}

void indice_aluno (Aluno* aluno) {
  int op;
  printf("\n0 - IG\n1 - IRA\n2 - IRT");
  printf("\nEscolha um dos indices: ");
  scanf("%d", &op);

  switch (op) {
  case 0:
    printf("Digite o IG: \n");
    scanf(" %f", &aluno->indice.IG); break;
  case 1:
    printf("Digite o IRA: \n");
    scanf(" %f", &aluno->indice.IRA); break;
  case 2:
    printf("Digite o IRT: \n");
    scanf(" %f", &aluno->indice.IRT); break;
  default:
    break;
  }
}

/*
  Função que imprime os dados de todos os alunos de uma turma.
*/
void imprime_alunos(Turma *turma) {
  if (turma->vagas < MAX_VAGAS) {
    for (i = 0; i < (MAX_VAGAS - turma->vagas); i++) {
      Aluno *alunos = turma->alunos[i];
      printf("\n========================================\n");
      printf("Matricula: %d\n", alunos->mat);
      printf("Nome: %s\n", alunos->nome);
      printf("Media: %.2f\n", alunos->media);
      printf("Indice Academico: %.2f", alunos->indice.IG);
    }
  } else {
    printf("Nao ha alunos matriculados na turma %c.\n", turma->id);
  }
}

/*
  Função que exclui uma turma, caso ela não tenha nenhum aluno.
*/
void exclui_turma(Turma **t, int indice) {
  if(t[indice]->vagas == MAX_VAGAS) {
    printf("Turma %c excluida!\n", t[indice]->id);
    t[indice] = NULL;
    free(t[indice]);

    for (i = indice; i < count_turmas; i++) {
      if (i < count_turmas - 2) {
        t[i] = t[i+1];
      }
      
      if (i == count_turmas - 2) {
        t[i] = t[i+1];
        t[i+1] = NULL;
        free(t[i+1]); 
      }
    }
    count_turmas--;

  } else {
    printf("Ha alunos matriculados! Nao foi possivel excluir a turma.\n");
  }
}
