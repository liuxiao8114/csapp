#include <inttypes.h>
#include <stdio.h>

typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t *dest, uint64_t x, uint64_t y);

int main() {
  uint128_t x[1];
  store_uprod(x, 2, 3);

  printf("%d\n", x[0]);
  return 0;
}

void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
  *dest = x * (uint128_t)y;
}
