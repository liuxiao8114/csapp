#include <stdio.h>

int trans(int M, int N, int A[M][N], int B[N][M]) {
  int i, j;

  for(i = 0; i < N; i++)
    for(j = 0; j < M; j++)
      B[i][j] = A[j][i];
}

int main(int argc, char **argv) {
  int m = 23;
  int n = 29;
  int a[n][m], b[m][n];

  int i, j;
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      a[i][j] = i * n + j;

  trans(m, n, a, b);
}
