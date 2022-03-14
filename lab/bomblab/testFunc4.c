#include <stdio.h>

//      %rdi,      %rsi,    %rdx
int func4(int p1, int start, int end) {
  int i, j; // i: %rax, j: %rcx
  i = start - end;
  // j = i;
  // j = i >> 31;
  i = (i + (i >> 31)) >> 1;
  j = i + start;

  if(j > p1)
    return func4(p1, start, j - 1) * 2;
  if(j == p1)
    return 0;
  return func4(p1, j + 1, end) * 2 + 1;
}

void main() {
  printf("func4 result: %d\n", func4(9, 0, 14));
  /*
    func4(x, 0, 14)
      i = 7, j = 7
      j > x
        ? func4(x, 0, 7) * 2
        : 8 < x
        ? func4(x, 9, 14) * 2 + 1
        : 0
  */
}
