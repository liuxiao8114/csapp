#include <stdlib.h>
#include <stdio.h>

void f(void) {
  int* x = malloc(40);    // problem 1: heap block overrun
  // x[10] = 0;           // problem 2: memory leak -- x not freed
  x[9] = 0;
}

int main(void) {
  printf("%ld\n", sizeof(int));
  f();
  return 0;
}
