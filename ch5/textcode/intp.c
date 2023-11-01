#include <stdlib.h>
#include <stdio.h>

int main() {
  int i = 100;

  *(&i) = 99;
  printf("%d\n", i);
}
