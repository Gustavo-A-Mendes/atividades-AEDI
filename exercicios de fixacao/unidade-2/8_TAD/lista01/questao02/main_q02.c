#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "disciplina.h"
#include "aluno.h"

#define MAX_DISCIPLINA 3
#define MAX_ALUNO 3

Aluno *alunos[MAX_ALUNO];
Disciplina *disciplinas[MAX_DISCIPLINA];

int checaResp(char ch, char test) {
    return (toupper(ch) == toupper(test));
}

int main(void) {
    int count_alu = 0;
    int count_disc = 0;

    int op = 0;

    while (op != 6) {
        printf("\n1 - Criar Disciplina\n");
        printf("2 - Cadastrar Aluno\n");
        printf("3 - Matricular Aluno\n");
        printf("4 - Listar Disciplinas\n");
        printf("5 - Listar Alunos\n");
        printf("6 - Sair\n");

        printf("\nEscolha um opcao: ");
        scanf_s("%d", &op);
        fflush(stdin);

        char nome_alu[51], nome_disc[121];
        int mat_alu, cod_disc;

        switch (op) {
        case 1:
            if (count_disc >= MAX_DISCIPLINA) {
                printf("\nNumero maximo de disciplina no sistema.\n");
                break;
            }

            printf("\nCriando disciplina...\n");
            
            printf("Informe o codigo da disciplina: ");
            scanf_s("%d", &cod_disc);
            fflush(stdin);

            if (count_disc > 0) {
                if (disc_procura(disciplinas, cod_disc, count_disc) != NULL) {
                    printf("\nUma disciplina ja possui esse codigo!\n");
                    break;
                }
            }
            printf("Informe o nome da disciplina: ");
            scanf_s(" %120[^\n]", nome_disc);
            fflush(stdin);
            disciplinas[count_disc] = disc_cria(nome_disc, cod_disc);

            count_disc++;
            break;

        case 2:
            if (count_alu >= MAX_ALUNO) {
                printf("\nNumero maximo de alunos no sistema.\n");
                break;
            }

            printf("\nCadastrando Aluno...\n");

            printf("Informe a matricula do aluno: ");
            scanf_s("%d", &mat_alu);
            fflush(stdin);

            if (count_alu > 0) {
                if (alu_procura(alunos, mat_alu, count_alu) != NULL) {
                    printf("\nA matricula informada ja esta cadastrado!\n");
                    break;
                }
            }
            printf("\nInforme o nome do aluno: ");
            scanf_s(" %50[^\n]", nome_alu);
            fflush(stdin);
            alunos[count_alu] = alu_cria(nome_alu, mat_alu);

            count_alu++;
            break;

        case 3:
            printf("\nMatriculando aluno...\n");

            printf("Informe a matricula do aluno: ");
            scanf_s("%d", &mat_alu);
            fflush(stdin);
            Aluno *alu = alu_procura(alunos, mat_alu, count_alu);

            if (alu != NULL) {
                printf("Informe o codigo da disciplina que deseja cursar: ");
                scanf_s("%d", &cod_disc);
                fflush(stdin);
                Disciplina *disc = disc_procura(disciplinas, cod_disc, count_disc);

                if (disc != NULL) {
                    alu_matricula(alu, disc);
                }
                else {
                    printf("\nDisciplina nao encontrada!\n");
                }
            } else {
                printf("\nAluno nao encontrado!\n");
            }
            break;
        
        case 4:
            printf("\nListando Disciplinas...\n");
            if (count_disc > 0)
                disc_lista(disciplinas, count_disc);
            else
                printf("\nNao ha disciplinas cadastradas.\n");
            break;

        case 5:
            printf("\nListando Alunos...\n");
            if (count_alu > 0)
                alu_lista(alunos, count_alu);
            else 
                printf("\nNao ha alunos matriculados.\n");
            break;

        case 6:
            printf("Encerrando programa...\nAte a proxima!");
            break;
        default:
            printf("\nDigite uma opcao valida!\n");
            break;
        }
    }

    int i;
    for (i = 0; i < count_alu; i++) {
        alu_exclui(alunos[i]);
    }
    for (i = 0; i < count_disc; i++) {
        disc_exclui(disciplinas[i]);
    }

    return 0;
}