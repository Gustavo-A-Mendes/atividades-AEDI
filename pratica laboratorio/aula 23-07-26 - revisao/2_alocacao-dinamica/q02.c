#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_str(char* str1, char* str2) {

  char *str_result = (char*)malloc((strlen(str1) + strlen(str2))*sizeof(char));
  strcpy(str_result, str1);
  strcpy(str_result+strlen(str1), str2);

  return str_result;
}


int main(void) {

  char str1[10] = "ola, ";
  char str2[10] = "mundo!";
  
  char *str3 = concat_str(str1, str2);
  printf("%s\n", str3);  

  return 0;
}