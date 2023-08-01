#include <stdio.h>

int main() {

    FILE *arquivo;
    char str[100];
    int c;

    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int nlinhas = 1;
    
    // int fgetc(FILE *fp) é usado para ler um caracter de um arquivo formatado:

    // por meio dessa declaração, podemos ler todos os caracteres de um arquivo:
    while ((c = fgetc(arquivo)) != EOF) {   // EOF - End Of File, é uma constante invisível presente em todos os arquivos
      printf("%c", c); // Imprime a string lida
      if (c == '\n') nlinhas++;   // está contando o total de linhas
    }
    printf("\n\nNumero de linhas: %d\n", nlinhas);
    fclose(arquivo);
    

    return 0;
}