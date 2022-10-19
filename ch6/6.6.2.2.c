#include <stdio.h>
#define M 4
#define N 15
#define P 4

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

void bijk(double c[N][N], double a[N][N], double b[N][N], int n, int bsize) {
  int i, j, k, kk, jj;
  double sum;
  int en = bsize * (n / bsize);

  for(kk = 0; kk < en; kk += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = 0; i < n; i++)
        for(j = jj; j < jj + bsize; j++) {
          sum = c[i][j];
          for(k = kk; k < kk + bsize; k++) {
            // printf("c[%d][%d] += a[%d][%d] * b[%d][%d]\n", i, j, i, k, k, j);
            sum += a[i][k] * b[k][j];
          }
          c[i][j] = sum;
        }

  // printf("en -----> n\n");

  for(i = 0; i < n; i++) {
    for(j = 0; j < en; j++) {
      sum = c[i][j];

      for(k = en; k < n; k++) {
        // printf("c[%d][%d] += a[%d][%d] * b[%d][%d]\n", i, j, i, k, k, j);
        sum += a[i][k] * b[k][j];
      }

      c[i][j] = sum;
    }

    for(j = en; j < n; j++) {
      sum = c[i][j];

      for(k = 0; k < n; k++) {
        // printf("c[%d][%d] += a[%d][%d] * b[%d][%d]\n", i, j, i, k, k, j);
        sum += a[i][k] * b[k][j];
      }

      c[i][j] = sum;
    }
  }

  /*
  kk=0
    jj=0
      i=0
        j=jj(0)
          sum=c[i][j](c[0][0])
          k=kk(0)
            sum+=a[0][0]*b[0][0]
            sum+=a[0][1]*b[1][0]
            sum+=a[0][2]*b[2][0]
            ......
            sum+=a[0][kk+bsize-1]*b[kk+bsize-1][0]
          c[0][0]=sum

        j++(1)
          sum=c[i][j](c[0][1])
          k=kk(0)
            sum+=a[0][0]*b[0][1]
            sum+=a[0][1]*b[1][1]
            sum+=a[0][2]*b[2][1]
            ......
            sum+=a[0][kk+bsize-1]*b[kk+bsize-1][1]
          c[0][1]=sum

        j++(2)
          sum=c[0][2]
          k=0
            sum+=a[0][0]*b[0][2]
            sum+=a[0][1]*b[1][2]
            sum+=a[0][2]*b[2][2]
            ......
            sum+=a[0][kk+bsize-1]*b[kk+bsize-1][2]
          c[0][2]=sum

        ......
        j++(jj+bsize-1)
          sum=c[0][jj+bsize-1]
          k=0
            sum+=a[0][0]*b[0][jj+bsize-1]
            sum+=a[0][1]*b[1][jj+bsize-1]
            sum+=a[0][2]*b[2][jj+bsize-1]
            ......
            sum+=a[0][kk+bsize-1]*b[kk+bsize-1][jj+bsize-1]
          c[0][jj+bsize-1]=sum

      i++(1)
        j=jj(0)
          sum=c[i][j](c[1][0])
          k=kk(0)
          <......>
        c[1][0]
        c[1][1]
        c[1][2]
        ...
        c[1][jj+bsize-1]
      i(n-1)
        c[n-1][0]
        c[n-1][1]
        c[n-1][2]
        ...
        c[n-1][jj+bsize-1]
    jj+=bsize
      c[0][bsize]
      c[0][bsize+1]
      ...
      c[0][bsize+bsize-1]
      c[1][bsize]
      c[1][bsize+1]
      ...
      c[1][bsize+bsize-1]
      ...
      c[2][bsize]
      ...
      c[n-1][bsize+bsize-1]
  kk+=bsize
  */
}


void init(double a[][N], int n, double val, double step) {
  int i, j;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      a[i][j] = val;
      val += step;
    }
}

int isIdentity(double c[][N], double ct[][N], int n) {
  int i, j;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      if(c[i][j] != ct[i][j]) {
        printf("Unmatch i:%d, j:%d, c1:%f, c2: %f\n", i, j, c[i][j], ct[i][j]);
        return 0;
      }

  return 1;
}

int main(int argc, char *argv[]) {
  double a[N][N], b[N][N];
  double ca[N][N], cb[N][N], cc[N][N], cd[N][N], ce[N][N], cf[N][N], cbijk[N][N];

  init(a, N, 0.0, 1.0);
  init(b, N, 0.0, 1.0);

  init(ca, N, 0.0, 0.0);
  init(cb, N, 0.0, 0.0);
  init(cc, N, 0.0, 0.0);
  init(cd, N, 0.0, 0.0);
  init(ce, N, 0.0, 0.0);
  init(cf, N, 0.0, 0.0);
  init(cbijk, N, 0.0, 0.0);

  loop_a(ca, a, b);
  loop_b(cb, a, b);
  loop_c(cc, a, b);
  loop_d(cd, a, b);
  loop_e(ce, a, b);
  loop_f(cf, a, b);
  bijk(cbijk, a, b, N, 4);

  // printf("is ca and cc identity: %d\n", isIdentity(ca, cc, N));
  printf("is ca and cbijk identity: %d\n", isIdentity(ca, cbijk, N));
  // printf("is cb and cbijk identity: %d\n", isIdentity(cb, cbijk, N));
  // printf("is cc and cbijk identity: %d\n", isIdentity(cc, cbijk, N));
  // printf("is cd and cbijk identity: %d\n", isIdentity(cd, cbijk, N));
  // printf("is ce and cbijk identity: %d\n", isIdentity(ce, cbijk, N));
  // printf("is cf and cbijk identity: %d\n", isIdentity(cf, cbijk, N));
}
