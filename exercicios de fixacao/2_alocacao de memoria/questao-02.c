#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// mudar cor dos textos
#define txtRed "\x1b[31m"
#define txtGreen "\x1b[32m"
#define txtCyan "\x1b[36m"
#define txtReset "\x1b[0m"

int numQuestoes = 0;
int aprovados = 0;

void addRespostas (char *);
void geraRespostaAluno (char *);
int checaOpcoesValidas(char *);

int main(void) {
  printf(txtReset); //reseta cor
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
  
  int i, j;
  for (i = 0; i < 10; i++) {
    int numAcertos = 0;

    // gera um conjunto de respostas aleatórias para cada aluno
    printf(txtGreen"\n========== RESPOSTAS ALUNO %d ==========\n"txtReset, i+1);
    geraRespostaAluno(respostasAlunos);
    
    for (j = 0; j < numQuestoes; j++) {
      // printf("%c", respostasAlunos[j]);
      if (gabarito[j] == respostasAlunos[j]) {
          numAcertos++;
      }
    }

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

void addRespostas (char *arr) {
  int count;
  for (count = 0; count < numQuestoes; count++) {
    
    int charInvalido;
    do {
      printf("Insira a respota da questao %d [A-E]: ", count+1);
      scanf(" %1[A-Ea-e]", arr+count);
      fflush(stdin);
      
      charInvalido = checaOpcoesValidas(arr+count);
      if (charInvalido) printf(txtRed"Valor invalido!\n"txtReset);
    } while (charInvalido);
  }
}

void geraRespostaAluno(char *aluno) {
  int count;
  for (count = 0; count < numQuestoes; count++) {
    aluno[count] = 'A' + (rand() % ('E' - 'A' + 1));
  }
}

int checaOpcoesValidas(char *ch1) {
  *ch1 = toupper(*ch1); 
  if (*ch1 >= 'A' && *ch1 <= 'E') {
    return 0;
  }
  return 1;
}