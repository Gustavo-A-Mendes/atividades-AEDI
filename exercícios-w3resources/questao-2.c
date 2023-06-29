#include <stdio.h>

int main(void) {
  int m = 29;
  printf("\nAddress of m : %p\n", &m);
  printf("Value of m : %i\n\n", m);
  
  int *ab = &m;
  printf("Address of pointer ab : %p\n", &ab);
  printf("Value of pointer ab : %i\n\n", *ab);
  
  m = 34;
  printf("Address of pointer ab : %p\n", &ab);
  printf("Value of pointer ab : %i\n\n", *ab);

  *ab = 7;
  printf("Address of pointer m : %p\n", &m);
  printf("Value of pointer m : %i\n\n", m);   

  return 0;
}
