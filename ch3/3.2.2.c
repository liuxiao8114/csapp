#include <stdio.h>

long mult2(long a, long b) {
  long s = a * b;
  return s;
}

void multstore(long x, long y, long *dest) {
  long t = mult2(x, y);
  *dest = t;
}

void main() {
  long d;
  multstore(2, 3, &d);
  printf("2 * 3 --> %ld\n", d);
}

/*
multstore:
  push  %rbx
  mov   %rdx, %rbx
  callq <mult2>
  mov   %rax, (%rbx)
  pop   %rbx
  ret

mult2:
  mov   %rdi, %rax
  mul   %rax, %rsi
  ret
*/
