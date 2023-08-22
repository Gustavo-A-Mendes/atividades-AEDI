#include <stdio.h>

unsigned long long factorial (int n) {        //  Considerado o pior caso:
  if ( n == 0 || n == 1) {                            // 1 vez: C1
    return 1;                                         // 0 vez: 
  }

  unsigned long long result = 1;                      // 1 vez: C2
  for (int i = 2; i <= n ; i ++) {                    // (n-1) vez: C3*(n-1)
    result *= i;                                      // (n-1) vez: C4*(n-1)
  }
  return result;                                      // 1 vez: C5
}

int main () {
  int n = 10;                                         // 1 vez: C6
  unsigned long long result = factorial(n);           // 1 vez: C7
  
  printf ("Factorial of %d is %f\n", n, result);      // 1 vez: C8

  return 0;                                           // 1 vez: C9
}

// Complexidade de Tempo:
// T(n) = C1 + C2 + C3*(n-1) + C4*(n-1) + C5 + C6 + C7 + C8 + C9
// T(n) = a*(n-1) + b

// Notação Big O: O(n)
