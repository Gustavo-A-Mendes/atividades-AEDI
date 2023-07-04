#include <stdio.h>

int main (void) {
  int x, y, *p;
  y = 0;
  p = &y;
  x = *p;
  x = 4;
  (*p)++;
  --x;
  (*p) += x;

  printf("\n%d\t%d\t%d", x, y, *p);
}