#include <stdio.h>

/* Fig 7.9 ELF relocation entry */
typedef struct {
  long offset;
  long type:32,
       symbol:32;
  long addend;
} elf64_rela;

void main() {
  elf64_rela a;
}
