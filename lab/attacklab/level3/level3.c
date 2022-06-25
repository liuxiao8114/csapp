#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main() {
  printf("%.8x\n", 1);
  printf("%8x\n", 1);
  printf("%.8x\n", 234);
  printf("%8x\n", 234);
  printf("%8x\n", 0x59b997fa);
  printf("%s\n", "\\001");

  char *s = "59b997fa";
  printf("%d\n", strncmp(s, "1", 9));
}
