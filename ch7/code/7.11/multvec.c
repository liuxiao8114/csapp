#include <stdio.h>

int multcnt = 0;

void multvec(int *x, int *y, int *z, int n) {
  int i;
  multcnt++;
  printf("multcnt: %d\n", multcnt);

  for(i = 0; i < n; i++)
    z[i] = x[i] * y[i];
}
