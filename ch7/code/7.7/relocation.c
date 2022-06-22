#include <stdio.h>

void main() {
  typedef struct {
    long offset;
    long type:32,
         symbol:32;
    long addend;
  } elf64_rela;
}
