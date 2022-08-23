#include <stdio.h>
#define N 4

/*
C = AB
n = 2
  c11 c12       a11 a12       b11 b12
            =             *
  c21 c22       a21 a22       b21 b22

  c11 = a11 * b11 + a12 * b21
  c12 = a11 * b12 + a12 * b22
  c21 = a21 * b11 + a22 * b21
  c22 = a21 * b12 + a22 * b22

n = 3
  c11 = a11 * b11 + a12 * b21 + a13 * b31
  c12 = a11 * b12 + a12 * b22 + a13 * b32
  c13 = a11 * b13 + a12 * b23 + a13 * b33
  c21 = a21 * b11 + a22 * b21 + a23 * b31
  c22 = a21 * b12 + a22 * b22 + a23 * b32
  c23 = a21 * b13 + a22 * b23 + a23 * b33
  c31 = a31 * b11 + a32 * b21 + a33 * b31
  c32 = a31 * b12 + a32 * b22 + a33 * b32
  c33 = a31 * b13 + a32 * b23 + a33 * b33
*/

// Version ijk
void loop_a(double c[N][N], double a[N][N], double b[N][N]) {
  int i, j, k;

  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++) {
      double sum = 0.0;

      for(k = 0; k < N; k++)
        sum += a[i][k] * b[k][j];
      c[i][j] = sum;
    }
}

// Version jik
void loop_b(double c[N][N], double a[N][N], double b[N][N]) {
  int i, j, k;

  for(j = 0; j < N; j++)
    for(i = 0; i < N; i++) {
      double sum = 0.0;

      for(k = 0; k < N; k++)
        sum += a[i][k] * b[k][j];
      c[i][j] = sum;
    }
}

// Version jki
void loop_c(double c[N][N], double a[N][N], double b[N][N]) {
  int i, j, k;
  double r = 0.0;

  for(j = 0; j < N; j++)
    for (k = 0; k < N; k++) {
      r = b[k][j];

      for(i = 0; i < N; i++)
        c[i][j] += a[i][k] * r;
    }
}

// Version kji
void loop_d(double c[N][N], double a[N][N], double b[N][N]) {
  int i, j, k;
  double r = 0.0;

  for(k = 0; k < N; k++)
    for (j = 0; j < N; j++) {
      r = b[k][j];

      for(i = 0; i < N; i++)
        c[i][j] += a[i][k] * r;
    }
}

// Version ikj
void loop_e(double c[N][N], double a[N][N], double b[N][N]) {
  int i, j, k;
  double r = 0.0;

  for(i = 0; i < N; i++)
    for(k = 0; k < N; k++) {
      r = a[i][k];

      for(j = 0; j < N; j++)
        c[i][j] += r * b[k][j];
    }
}

// Version kij
void loop_f(double c[N][N], double a[N][N], double b[N][N]) {
  int i, j, k;
  double r = 0.0;

  for(k = 0; k < N; k++)
    for(i = 0; i < N; i++) {
      r = a[i][k];

      for(j = 0; j < N; j++)
        c[i][j] += r * b[k][j];
    }
}


void init(double a[N][N], int n, double val, double step) {
  int i, j;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      a[i][j] = val;
      val += step;
    }
}

int main(int argc, char *argv[]) {
  double a[N][N], b[N][N];
  double ca[N][N], cb[N][N], cc[N][N], cd[N][N], ce[N][N], cf[N][N];

  init(a, N, 1.0, 1.0);
  init(b, N, 10.0, 10.0);
  loop_a(ca, a, b);
  loop_b(cb, a, b);
  loop_c(cc, a, b);
  loop_d(cd, a, b);
  loop_e(ce, a, b);
  loop_f(cf, a, b);

  int i, j;
  printf("ca:\t");
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      printf("[%d%d]%.0lf ", i, j, ca[i][j]);
  printf("\n");

  printf("cb:\t");
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      printf("[%d%d]%.0lf ", i, j, cb[i][j]);
  printf("\n");

  printf("cc:\t");
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      printf("[%d%d]%.0lf ", i, j, cc[i][j]);
  printf("\n");

  printf("cd:\t");
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      printf("[%d%d]%.0lf ", i, j, cd[i][j]);
  printf("\n");

  printf("ce:\t");
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      printf("[%d%d]%.0lf ", i, j, ce[i][j]);
  printf("\n");

  printf("cf:\t");
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      printf("[%d%d]%.0lf ", i, j, cf[i][j]);
  printf("\n");
}
