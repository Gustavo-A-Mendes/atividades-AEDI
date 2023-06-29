#include <stdio.h>

int main(void) {
  int m = 10, n, o;
  int *z = &m;
  
  printf("\nPointer : Show the basic declaration of pointer :\n");
  printf("-------------------------------------------------\n");
  printf("Here is m=10, n and o are two integer variable and *z is an integer\n\n");
  printf("z stores the address of m  = %p\n\n", z); // z is a pointer so %p would print the address
  printf("*z stores the value of m = %d\n\n", *z);
  printf("&m is the address of m = %p\n\n", &m);  // &m gives the address of the integer variable m 
                             // so %p is the specifier for that address
  printf("&n stores the address of n = %p\n\n", &n);
  printf("&o  stores the address of o = %p\n\n", &o);                                                           
  printf("&z stores the address of z = %p\n\n", &z);  // &z gives the address, where the pointer z is 
                             // stored -> still an address -> %p is the right
                             // specifier        
  return 0;
}