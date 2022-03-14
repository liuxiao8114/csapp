#include <stdio.h>

void main() {

  int i1 = 1;
  int i2 = 2;
  char c1 = 'a';
  char c2  = 'b';

  int scanfResult = sscanf("9,8,j,k", "%d, %d, %c, %c", &i1, &i2, &c1, &c2);
  printf("we got %d, %d, %c, %c in printf. And scanf result %d\n", i1, i2, c1, c2, scanfResult);
}
