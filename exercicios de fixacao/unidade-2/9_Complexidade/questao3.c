void insertionSort(int arr[], int n) {
  int i, key, j;                        // 1 vez: C1
  for (i = 1; i < n; i++) {             // (n-1) vezes: C2*(n-1)
    key = arr[i];                       // (n-1) vezes: C3*(n-1)
    j = i - 1;                          // (n-1) vezes: C4*(n-1)

    while (j >= 0 && arr[j] > key) {    // (n²-n)/2 vezes: C5*(n²-n)/2
        arr[j+1] = arr[j];              // (n²-n)/2 vezes: C6*(n²-n)/2
        j -= 1;                         // (n²-n)/2 vezes: C7*(n²-n)/2
    }
    arr[j+1] = key;                     // (n-1) vezes: C8*(n-1)
  }
}


// Complexidad de tempo:
// T(n) = C1 + C2*(n-1) + C3*(n-1) + C4*(n-1) + C5*(n²-n)/2 + C6*(n²-n)/2 + C7*(n²-n)/2 + C8*(n-1)
// T(n) = a*(n²-n)/2 + b*n + c

// Notação Big O: O(n²)
