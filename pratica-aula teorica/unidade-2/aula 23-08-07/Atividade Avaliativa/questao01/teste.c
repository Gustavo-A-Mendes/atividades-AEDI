#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char funcional[3];
    char nome[20];
    char depto;
    float salario;
}Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal);
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto);

Funcionario *new_funcionario(void){

    Funcionario *new_funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if(new_funcionario == NULL){exit(1);}

    return new_funcionario;
}

int main(void){

    int quant_funcionario;
    FILE *file;
    file = fopen("funcionarios.txt", "r");
    if(file == NULL){
        printf("Deu errado\n");
        exit(1);
    } else printf("deu bom!\n");
    
    fscanf(file, "%d", &quant_funcionario);
    //printf("%d", quant_funcionario);
    Funcionario **funcionario = (Funcionario**) calloc(quant_funcionario+1,sizeof(Funcionario*));

    copia_dados(file, quant_funcionario+1, funcionario);
    imprime_folha_pagamento(quant_funcionario, funcionario, 'A');

    fclose(file);
    free(funcionario);

    return 0;
}

void copia_dados(FILE* fl, int n, Funcionario** pessoal){

    char linha[100];
    int index = 0;
              
    while(fgets(linha,100,fl) != NULL){
        pessoal[index] = new_funcionario();
        sscanf(linha, "%4[^\t]%20[^\t]%c\t%f", pessoal[index]->funcional, pessoal[index]->nome, &pessoal[index]->depto, &pessoal[index]->salario);
        index++;
    }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto){

    int index = 0;
    //printf("%d ", index);
    printf("%c", pessoal[4]->depto);
    printf("%c", depto);
    //for(index; index < n+1; index++){
    //   int result = strcmp(depto, pessoal[index]->depto);
    //   if(result == 0){
    //       printf(",,,,,");
    //    }
    //}
}