#include <stdio.h>

#define N 4
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val) {
  long i;
  for(i = 0; i < N; i++)
    A[i][i] = val;
}

/*
  movq  $0,   %rax
  movl  %esi, (%rdi, %rax)
  addq  $68,  %rax    // 4 * 16 + 4
  cmpq  $1088,%rax    // 16 * 16 * 4 + 16 * 4
*/
void fix_set_diag_ele(fix_matrix A, int val) {
  int *astart = &A[0][0];
  int *aend = &A[N][N];

  do {
    *astart = val;
    astart += N + 1;
  } while(astart < aend);
}

void main() {
  fix_matrix x = {
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 },
    { 0, 1, 2, 3 }
  };

  // fix_set_diag(x, 9);
  // printf("%d\n", x[0][0]);
  // printf("%d\n", x[1][1]);
  // printf("%d\n", x[2][2]);
  // printf("%d\n", x[3][3]);

  fix_set_diag_ele(x, 9);
  printf("%d\n", x[0][0]);
  printf("%d\n", x[1][1]);
  printf("%d\n", x[2][2]);
  printf("%d\n", x[3][3]);
}
