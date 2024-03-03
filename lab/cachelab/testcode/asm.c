#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

void do_simple() {
  int src = 100;
  int dst;

  asm("mov %1, %0\n\t"
    "add $1, %0"
    : "=r" (dst)
    : "r" (src)
  );

  printf("dst = %d\n", dst);
}

void do_check(int32_t dwSomeValue) {
  int32_t dwRes;

  /*
    bsf scans the source bits starting at bit 0.
    If the bits are all zero, ZF is cleared.
    Otherwise, ZF is set and the bit index of the first set bit,
    and set the index into the dest register
  */
  asm("bsfl %1, %0"
    : "=r" (dwRes)
    : "r" (dwSomeValue)
    : "cc"
  );

  printf("dwRes: %d\n", dwRes);
  assert(dwRes > 3);
}

void do_rdtsc() {
  uint64_t msr;

  asm volatile("rdtsc\n\t"
    "shl $32, %%rdx\n\t"
    "or %%rdx, %0"
    : "=a" (msr)
    :
    : "rdx"
  );

  printf("msr: %lx\n", msr);
}

int main() {
  do_rdtsc();
}
