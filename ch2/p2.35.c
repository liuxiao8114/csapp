#include <stdio.h>

int tmult_ok(int x, int y) {
  int p = x * y;
  return !x || p/x == y;
}

int main() {
  printf("%d", tmult_ok(0, 1));
  printf("%d", tmult_ok(0, 1));
  printf("%d", tmult_ok(0, 1));
  printf("%d", tmult_ok(0, 1));
}
