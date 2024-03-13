#include <stdio.h>

void trans_v1(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, ii, jj;
  int bsize = 8;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize) {
      printf("jj=%d\n", jj);
      for(i = ii; i < ii + bsize; i++) {
          printf("-----------------------\n");
        for(j = jj + i%bsize + 1; j < jj + bsize; j++) {
          printf("B[%2d][%2d]=A[%2d][%2d]\n", j,i,i,j);
          B[j][i] = A[i][j];
        }

        for(j = jj; j < jj + i%bsize + 1; j++) {
          printf("B[%2d][%2d]=A[%2d][%2d]\n", j,i,i,j);
          B[j][i] = A[i][j];
        }
      }
    }
}

void trans_v0(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, ii, jj;
  int bsize = 8;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++) {
          printf("-----------------------\n");
        for(j = jj; j < jj + bsize; j++) {
          printf("B[%2d][%2d]=A[%2d][%2d]\n", j,i,i,j);
          B[j][i] = A[i][j];
        }
      }
}

int main() {
  int m = 16;
  int n = 16;
  int a[n][m], b[m][n];

  int i, j;
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      a[i][j] = i * n + j;

  trans_v1(m, n, a, b);
}
