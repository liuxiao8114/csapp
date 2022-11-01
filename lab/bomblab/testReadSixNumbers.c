#include <stdio.h>

int read_six_numbers(char* in, int* rsp);
int explode_bomb();

void main() {
  int rsp[10];
  int r;

  r = read_six_numbers("1 2 4 8 16 32", rsp);
  printf("%d, %d. result: %d\n", rsp[0], rsp[1], r);

  r = read_six_numbers("12481632", rsp);
}

int explode_bomb() {
  printf("DOOM!!!The bomb exploded.\n");
  return 0;
}

int read_six_numbers(char* in, int* rsp) {
  int result = 0;
  result = sscanf(in, "%d %d %d %d %d %d", rsp, rsp + 1, rsp + 2, rsp + 3, rsp + 4, rsp + 5);

  if(result <= 5)
    return explode_bomb();

  return result;
}
