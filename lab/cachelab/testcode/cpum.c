#include <stdio.h>

#define NPAD 7

struct l {
  struct l *n;
  long pad[NPAD];
};

int main() {
  printf("%ld\n", sizeof (struct l));
  return 0;
}
