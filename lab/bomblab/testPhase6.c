#include <stdio.h>

int   read_six_numbers(char* in, int* rsp);
int   explode_bomb();
int   phase6(char*);
int  _phase6(long*);

void main() {
  phase6("1 2 3 4 5 6");
}

int explode_bomb() {
  printf("DOOM!!!The bomb exploded.\n");
  return 0;
}

int read_six_numbers(char* in, int* rsp) {
  int result = 0;
  result = sscanf(in, "%d %d %d %d %d %d", rsp, rsp + 1, rsp + 2, rsp + 3, rsp + 4, rsp + 5);

  if(result <= 5)
    explode_bomb();

  return result;
}

int phase6(char* in) {
  int rsp[97];
  /*
    0(rsp):   1st,  rsp[0]
    4(rsp):   2nd,  rsp[1]
    8(rsp):   3rd,  rsp[2]
    c(rsp):   4th,  rsp[3]
   10(rsp):   5th,  rsp[4]
   14(rsp):   6th,  rsp[5]
  */
  read_six_numbers(in, rsp);
  // printf("%d %d %d %d %d %d\n", rsp[0], rsp[1], rsp[2], rsp[3], rsp[4], rsp[5]);

  int* r13, rbp;
  int r12d, rbx;

  for(r13 = rsp, r12d = 1; r12d != 6; r13++, r12d++) {
    if(*r13 - 1 > 5)
      return explode_bomb();

    for(rbx = r12d; rbx <= 5; rbx++) {
      printf("%%r13: %d. *(rsp + rbx): %d\n", *r13, *(rsp + rbx));
      if(*(rsp + rbx) == *r13)
        return explode_bomb();
    }
  }

// 0x401153 - 0x40116d
  int* r14;

  for(r14 = rsp; r14 != rsp + 6; r14++)
    *r14 = 7 - *r14;

  long _rsp[97];
  int i;
  for(i = 0; i < 6; i++)
    _rsp[i] = (long)rsp[i];

  return 1;
}

int _phase6(long* rsp) {
/*

                      rsi < 0x18
                /<------------------\       rsi > 0x18
0x40116f - 0x401197 - 0x401183 - 0x401188 - 0x4011ab
                    \          /
                      0x401176
*/

  int rsi;
  long rcx;

  /*
      0: 0x20(%rsp)
      4: 0x28(%rsp)
      8: 0x30(%rsp)
      c: 0x38(%rsp)
     10: 0x40(%rsp)
     14: 0x48(%rsp)
     18: 0x50(%rsp)
  */
  for(rsi = 0; rsi < 6; rsi++) {
    rcx = *(rsp + rsi);
    if(rcx > 1)
      *(rsp + 8 + rsi) = 0x6032d0 + rcx * 8;
    else
      *(rsp + 8 + rsi) = 0x6032d0;
  }

// 0x4011ab -
  long rdx;
  long rbx = *(rsp + 8);
  long* rax;
  rcx = rbx;

  for(rax = rsp + 9; rax < rsp + 20; rax++) {
    rdx = *rax;
    *(rbx + 8) = rdx; 
    rcx = *rax;
  }

  *(rsp + 10) = *rax_p;
  return 1;
}
