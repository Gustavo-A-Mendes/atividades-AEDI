#include <stdio.h>

int main(void) {
  int m = 300, *pm = &m;
  float fx = 300.600006, *pf = &fx;
  char cht = 'z', *pc = &cht;

  printf("\nPointer : Demonstrate the use of & and * operator : \n");   
  printf("--------------------------------------------------------\n");
  printf("m = %d\n", m);
  printf("fx = %f\n", fx);
  printf("cht = %c\n\n", cht);
  
  printf("Using & operator :\n");
  printf("-----------------------\n");
  printf("address of m = %p\n", &m);
  printf("address of fx = %p\n", &fx);
  printf("address of cht = %p\n\n", &cht);
  
  printf("Using & and * operator :\n");
  printf("-----------------------------\n");
  printf("value at address of m = %d\n", *(&m));
  printf("value at address of fx = %f\n", *(&fx));
  printf("value at address of cht = %c\n\n", *(&cht));

  printf("Using only pointer variable :\n");
  printf("----------------------------------\n");
  printf("address of m = %p\n", pm);
  printf("address of fx = %p\n", pf);
  printf("address of cht = %p\n\n", pc);

  printf("Using only pointer operator :\n");
  printf("----------------------------------\n");
  printf("address of m = %p\n", *pm);
  printf("address of fx = %p\n", *pf);
  printf("address of cht = %p\n\n", *pc);
  return 0;
}
