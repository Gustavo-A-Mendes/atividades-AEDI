int s;
  while (!feof(saida)) {    // feof(FILE *fp) retorna 0 quanto o cursor chegar no fim do arquivo 
    s = fgetc(saida);       // lê um caracter do arquivo
    printf("%c", s);
  }