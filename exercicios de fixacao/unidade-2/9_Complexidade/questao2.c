#include <stdio.h>

int linearSearch (int arr [] , int n , int target ) {     // Considerando o pior caso:
  for (int i = 0; i < n ; i ++) {                             // n vezes: C1*n
    if ( arr [ i ] == target ) {                              // n vezes: C2*n
      return i ; // indice do elemento encontrado             // n vezes: C3*n
    }
  }
  
  return -1; // Elemento nao encontrado                       // 1 vez: C4
}

int main () {                                                 
  int arr [] = {3 , 9 , 2 , 7 , 5};                           // 1 vez: C5
  int n = sizeof(arr)/sizeof(arr[0]) ;                        // 1 vez: C6
  int target = 7;                                             // 1 vez: C7
  int result = linearSearch(arr, n, target) ;                 // 1 vez: C8

  if ( result != -1) {                                        // 1 vez: C9
    printf (" Element found at index %d\n", result );         // 1 vez: C10
  } else {                                                    // 1 vez: C11
    printf (" Element not found \n");                         // 1 vez: C12
  }
  
  return 0;                                                   // 1 vez: C13
}

// Complexidad de tempo:
// T(n) = C1*n + C2*n + C3*n + C4 + C5 + C6 + C7 + C8 + C9 + C10 + C11 + C12 + C13
// T(n) = a*n + b

// Notação Big O: O(n)

// Complexidade de espaço:
// S(n) = 8 * 4Bytes = constante 