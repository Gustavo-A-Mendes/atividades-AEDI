#include <stdio.h>

int main() {

    FILE *arquivo;
    char str[100];

    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // int fscanf(FILE *fp, char *formato, ...) é usada para ler uma string de um arquivo formatado:
    
    fscanf(arquivo, "%[^\\]", str); // Lê uma string formatada do arquivo fp e armazena na string str
    printf("%s", str); // Imprime a string lida
    fclose(arquivo);

    return 0;
}