#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

/*
  Esse programa simula uma correção de provas de 10 alunos matriculados.
  O usuário informará o número total de questões da prova e seu gabarito,
  e então é gerado automaticamente as respostas dos alunos, que são
  comparadas ao gabarito e verificado se foram aprovados ou reprovados.
  Ao final da execução, o programa exibe quantidade de alunos que passaram.
*/

// mudar cor dos textos, somente para estética:
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

// protótipo da função utilizada:
void addRespostas (char *);
void geraRespostaAluno (char *);
int checaOpcoesValidas(char *);

// variáveis globais:
int numQuestoes = 0;
int aprovados = 0;
int i, j;

int main(void) {
  printf(txtReset); //reseta para a cor padrão de texto
  
  printf("Quantas questoes? ");
  scanf("%d", &numQuestoes);

  // aloca memória para os vetores
  char *gabarito = (char *)malloc(numQuestoes * sizeof(char));
  if (gabarito == NULL) exit(1);
  char *respostasAlunos = (char *)malloc(numQuestoes * sizeof(char));
  if (respostasAlunos == NULL) exit(1);

  // solicita as respostas do gabarito
  printf(txtGreen"\n========== GABARITO ==========\n"txtReset);
  addRespostas(gabarito);
  
  for (i = 0; i < 10; i++) {
    int numAcertos = 0;

    // gera um conjunto de respostas aleatórias para cada aluno
    printf(txtGreen"\n========== RESPOSTAS ALUNO %d ==========\n"txtReset, i+1);
    geraRespostaAluno(respostasAlunos);
    
    for (j = 0; j < numQuestoes; j++) {
      printf("%c", gabarito[j]);
    }
    printf("\n");
    for (j = 0; j < numQuestoes; j++) {
      printf("%c", respostasAlunos[j]);
      if (gabarito[j] == respostasAlunos[j]) {
          numAcertos++;
      }
    }
    printf("\n");

    // calcula nota
    float nota = 10.0 * ((float)numAcertos/numQuestoes);
    printf("aluno %d tirou %.1f [acertou %d/%d]\n", i+1, nota, numAcertos, numQuestoes);

    // status de aprovação de cada aluno    
    if (nota >= 6.0) {
      printf(txtCyan"- Aprovado -"txtReset);
      aprovados++;
    } else {
      printf(txtRed"- Reprovado -"txtReset);
    }
    printf("\n");
  }
  
  printf("\n\nForam aprovados um total de %d aluno(s).", aprovados);
  
  // limpa memória
  free(gabarito);
  return 0;
}

// Função que solicita ao usuário o gabarito da prova:
void addRespostas (char *arr) {
  int count;
  for (count = 0; count < numQuestoes; count++) {
    
    int charInvalido;
    while (1) {
      printf("Insira a respota da questao %d [A-E]: ", count+1);
      scanf(" %1[A-Ea-e]", arr+count);  // recebe somente os valores filtrados
      fflush(stdin);
      
      charInvalido = checaOpcoesValidas(arr+count);
      if (charInvalido) printf(txtRed"Valor invalido!\n"txtReset);
      else break;
    }
  }
}

// Função que gera aleatóriamente caracteres de A a E:
void geraRespostaAluno(char *aluno) {
  srand(time(0)); // muda a seed da geração aleatória a cada execução
  
  int count;
  for (count = 0; count < numQuestoes; count++) {
    aluno[count] = 'A' + (rand() % ('E' - 'A' + 1));
  }
}

// Função auxiliar que filtra a entrada, para apenas valores válidos: 
int checaOpcoesValidas(char *ch1) {
  *ch1 = toupper(*ch1); 
  if (*ch1 >= 'A' && *ch1 <= 'E') {
    return 0;
  }
  return 1;
}