#include <stdio.h>
#include <ctype.h>
// #include "disciplina.h"
// #include "disciplina.c"
// #include "aluno.h"
#include "aluno.c"

#define MAX_DISCIPLINA 10
#define MAX_ALUNO 10

// Disciplina *disciplinas[MAX_DISCIPLINA];
// Aluno *alunos[MAX_ALUNO];

int main(void) {
  int count_disc = 0, count_alu = 0;

  do {
    
    char nome_disc[121];
    int codigo_disc;

    printf("\nInforme o nome da disciplina: ");
    scanf(" %120[^\n]", nome_disc);
    printf("Informe o codigo da disciplina: ");
    scanf("%d", &codigo_disc);

    disciplinas[count_disc] = cria_disciplina(nome_disc, codigo_disc);
    count_disc++;
    
    char test[2];
    printf("Deseja criar outra disciplina [S/N]? ");
    scanf(" %1c", test);
    if ((test[0] = toupper(test[0])) == 'N') break;

  } while (count_disc < MAX_DISCIPLINA);

  do {
    char nome_alu[121];
    int mat_alu;
    int cod_disc;

    printf("\nInforme o nome do aluno: ");
    scanf(" %120[^\n]", nome_alu);
    printf("Informe a matricula do aluno: ");
    scanf("%d", &mat_alu);

    alunos[count_alu] = cria_aluno(nome_alu, mat_alu);

    printf("Informe o codigo da disciplina que deseja matricular: ");
    scanf("%d", &cod_disc);
    Disciplina *disc = procura_disciplina(disciplinas, cod_disc);

    if (disc != NULL) {
      matricula_disciplina(alunos[count_alu], disc);
      count_alu++;
    }
    
    char test[2];
    printf("Deseja matricular outro aluno [S/N]? ");
    scanf(" %1c", test);
    if ((test[0] = toupper(test[0])) == 'N') break;
    
  } while (count_alu < MAX_ALUNO);


  

  return 0;
}