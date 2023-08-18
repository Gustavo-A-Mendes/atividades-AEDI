#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// #include "disciplina.h"
// #include "disciplina.c"
// #include "aluno.h"
#include "aluno.c"

#define MAX_DISCIPLINA 10
#define MAX_ALUNO 10

Disciplina *disciplinas[MAX_DISCIPLINA];
Aluno *alunos[MAX_ALUNO];

int checaResp(char ch, char test) {
  return (toupper(ch) == toupper(test));
}

int main(void) {
  int op = 0;
  while (op != 5) {
    printf("\n1 - Criar Disciplina\n");
    printf("2 - Cadastrar Aluno\n");
    printf("3 - Matricular Aluno\n");
    printf("4 - Listar Alunos\n");
    printf("5 - Sair\n");
    
    printf("\nEscolha um opcao: ");
    scanf_s("%d", &op);
    fflush(stdin);

    char nome_alu[51], nome_disc[121];
    int mat_alu, cod_disc;

    switch (op) {
      case 1:
        printf("\nCriando disciplina...\n");

        printf("Informe o codigo da disciplina: ");
        scanf_s("%d", &cod_disc);
        fflush(stdin);

        if (count_disc > 0) {
          if (procura_disciplina(disciplinas, cod_disc, count_disc) != NULL) {
            printf("\nUma disciplina ja possui esse codigo!\n");
            break;
          }    
        }
        printf("\nInforme o nome da disciplina: ");
        scanf_s(" %120[^\n]", nome_disc);
        disciplinas[count_disc] = cria_disciplina(nome_disc, cod_disc);

        count_disc++;
        break;

      case 2:
        printf("\nCadastrando Aluno...\n");

        printf("Informe a matricula do aluno: ");
        scanf_s("%d", &mat_alu);
        fflush(stdin);

        if (count_alu > 0) {
          if (procura_aluno(alunos, mat_alu, count_alu) != NULL) {
            printf("\nA matricula informada ja esta cadastrado!\n");
            break;
          }
        }
        printf("\nInforme o nome do aluno: ");
        scanf_s(" %50[^\n]", nome_alu);
        fflush(stdin);
        alunos[count_alu] = cria_aluno(nome_alu, mat_alu);

        count_alu++;
        break;

      case 3:
        printf("\nMatriculando aluno...\n");

        printf("Informe a matricula do aluno: ");
        scanf_s("%d", &mat_alu);
        Aluno *alu = procura_aluno(alunos, mat_alu, count_alu);

        if (alu != NULL) {
          printf("Informe o codigo da disciplina que deseja cursar: ");
          scanf_s("%d", &cod_disc);
          Disciplina *disc = procura_disciplina(disciplinas, cod_disc, count_disc);

          if (disc != NULL) {
            matricula_disciplina(alu, disc);
          } else {
            printf("\nDisciplina nao encontrada!\n");
          }

        } else {
          printf("\nAluno nao encontrado!\n");
        }
        break;

      case 4:
        printf("\nListando Alunos...\n");
        lista_alunos(alunos, count_alu);
        break;

      case 5:
        printf("Encerrando programa...\nAte a proxima!");
        break;
      default:
        printf("\nDigite uma opcao valida!\n");
        break;
    }
  }
  
  int i;
  for (i = 0; i < count_alu; i++) {
    exclui_aluno(alunos[i]);
  }
  for (i = 0; i < count_disc; i++) {
    excluir_disciplina(disciplinas[i]);
  }

  return 0;
}