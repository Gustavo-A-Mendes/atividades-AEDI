int sum (int n) {
  int soma = 0;     // 1 vez: C1
  int i = 1;        // 1 vez: C2

  while (i <= n) {  // n vezes: C3 * n
    soma += i;      // n vezes: C4 * n
  }

  return soma;      // 1 vez: C5
}


// T(n) = C1 + C2 + C3*n + C4*n + C5;
// T(n) = (C3 + C4)*n + (C1 + C2 + C5)
// T(n) = a*n + b

// Notação Big O -> complexidade do elemento de maior grau:
// O(n) = n