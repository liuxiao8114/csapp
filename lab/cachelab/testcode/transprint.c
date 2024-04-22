#include <stdio.h>

int M = 61;
int N = 67;

void transpa(int A[N][M], int B[M][N], int si, int sj, int ti, int tj) {
  printf("B[%2d][%2d]=A[%2d][%2d](%d)\n", tj,ti,si,sj,A[si][sj]);
  B[tj][ti] = A[si][sj];
}

void transpb(int B[M][N], int si, int sj, int ti, int tj) {
  printf("B[%2d][%2d]=B[%2d][%2d](%d)\n", tj,ti,si,sj,B[si][sj]);
  B[tj][ti] = B[si][sj];
}

void transp(int A[N][M], int B[M][N], int i, int j) {
  transpa(A,B,i,j,i,j);
}

int is_transpose(int A[N][M], int B[M][N])
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                printf("A[%2d][%2d]=%d, B[%2d][%2d]=%d\n", i, j, A[i][j], j, i, B[j][i]);
                return 0;
            }
        }
    }
    return 1;
}

// 1255 misses(64 * 64)
void trans_v2(int A[N][M], int B[M][N]) {
  int i, j, k, ii, jj, kk;
  int bsize = 8;
  int subsize = 4;
  int setcounts = 32;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  int offset;
  int aset, bset;

  for(jj = 0; jj < 32; jj += bsize) {
    kk= jj + subsize;

    for(ii = 0; ii < 32; ii += bsize) {
      for(i = ii; i < ii + bsize; i++) {
        k = jj + i%subsize + 1;

        for(j = kk; j < jj + bsize; j++) {
          offset = i + bsize*(j - kk + 1);
          while(offset < jj + bsize*(j - kk + 1))
            offset += bsize;

          transpa(A, B, i, j, offset%64, 32+offset/64);
        }

        for(j = k; j < jj + subsize; j++)
          transp(A, B, i, j);

        for(j = jj; j < k; j++)
          transp(A, B, i, j);
      }

      for(j = jj + subsize; j < jj + bsize; j++)
        for(i = ii; i < ii + bsize; i++) {
          offset = (i + bsize*(j - kk + 1));
          while(offset < jj + bsize*(j - kk + 1))
            offset += bsize;

          transpb(B, 32+offset/64, offset%64, i, j);
        }
    }

    for(ii = 32; ii < 64; ii += bsize) {
      for(i = ii; i < ii + bsize; i++) {
        for(j = jj; j < jj + subsize; j++)
          transp(A, B, i, j);

        aset = (i*8)%32 + jj/8;
        bset = 4;

        if(aset >= bset && aset < bset + 4) {
          for(j = kk + aset - bset + 1; j < jj + bsize; j++) {
            offset = i%8 + bsize*(j - kk + 4);
            transpa(A, B, i, j, offset%64, 32);
          }
          for(j = kk; j <= kk + aset - bset; j++) {
            offset = i%8 + bsize*(j - kk + 4);
            transpa(A, B, i, j, offset%64, 32);
          }
        }
        else {
          for(j = kk; j < jj + bsize; j++) {
            offset = i%8 + bsize*(j - kk + 4);
            transpa(A, B, i, j, offset%64, 32);
          }
        }
      }

      for(j = jj + subsize; j < jj + bsize; j++)
        for(i = ii; i < ii + bsize; i++) {
          offset = i%8 + bsize*(j - kk + 4);
          transpb(B, 32, offset%64, i, j);
        }
    }
  }

  for(jj = 32; jj < 64; jj += bsize) {
    kk = jj + subsize;

    for(ii = 0; ii < 32; ii += bsize) {
      for(i = ii; i < ii + bsize; i++) {
        for(j = jj; j < jj + subsize; j++)
          transp(A, B, i, j);

        aset = (i*8)%32 + jj/8;
        bset = 4;

        if(aset >= bset && aset < bset + 4) {
          for(j = kk + aset - bset + 1; j < jj + bsize; j++) {
            offset = i%8 + bsize*(j - kk + 4);
            transpa(A, B, i, j, offset%64, 32);
          }
          for(j = kk; j <= kk + aset - bset; j++) {
            offset = i%8 + bsize*(j - kk + 4);
            transpa(A, B, i, j, offset%64, 32);
          }
        }
        else {
          for(j = kk; j < jj + bsize; j++) {
            offset = i%8 + bsize*(j - kk + 4);
            transpa(A, B, i, j, offset%64, 32);
          }
        }
      }

      for(j = jj + subsize; j < jj + bsize; j++)
        for(i = ii; i < ii + bsize; i++) {
          offset = i%8 + bsize*(j - kk + 4);
          transpb(B, 32, offset%64, i, j);
        }
    }
  }

  for(jj = 32; jj < 48; jj += bsize) {
    kk = jj + subsize;

    for(ii = 32; ii < 64; ii += bsize) {
      for(i = ii; i < ii + bsize; i++) {
        for(j = kk; j < jj + bsize; j++)
          transpa(A, B, i, j, 40 + i - ii, 56 + j - kk);

        for(j = k = jj + i%subsize + 1; j < jj + subsize; j++)
          transp(A, B, i, j);

        for(j = jj; j < k; j++)
          transp(A, B, i, j);
      }

      for(j = kk; j < jj + bsize; j++)
        for(i = ii; i < ii + bsize; i++)
          transpb(B, 56 + j - kk, 40 + i - ii, i, j);
    }
  }

  for(jj = 32; jj < 48; jj += subsize) {
    for(ii = 56; ii < 64; ii += subsize) {
      for(i = ii; i < ii + subsize; i++) {
        k = jj + i%subsize + 1;
        for(j = k; j < jj + subsize; j++)
          transp(A, B, i, j);

        for(j = jj; j < k; j++)
          transp(A, B, i, j);
      }
    }
  }

  for(jj = 48; jj < 64; jj += subsize)
    for(ii = 32; ii < 64; ii += subsize) {
      for(i = ii; i < ii + subsize; i++) {
        k = jj + i%subsize + 1;
        for(j = k; j < jj + subsize; j++)
          transp(A, B, i, j);

        for(j = jj; j < k; j++)
          transp(A, B, i, j);
      }
    }

  for(i = ii; i < M; i++)
    for(j = jj; j < N; j++)
      transp(A, B, i, j);
}

// 287 misses (32*32)
void trans_v1(int A[N][M], int B[M][N]) {
  int i, j, ii, jj;
  int bsize = 8;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++) {
        for(j = jj + i%bsize + 1; j < jj + bsize; j++)
          transp(A, B, i, j);

        for(j = jj; j < jj + i%bsize + 1; j++)
          transp(A, B, i, j);
      }
}

// M = 61, N = 67
void trans_v0(int A[N][M], int B[M][N]) {
  int i, j, ii, jj;
  int bsize = 8;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < 64; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++)
        for(j = jj; j < jj + bsize; j++)
          transp(A, B, i, j);

  for(i = 0; i < 64; i++)
    for(j = en; j < M; j++)
      transp(A, B, i, j);

  for(i = 64; i < N; i++)
    for(j = 0; j < M; j++)
      transp(A, B, i, j);
}

void trans(int A[N][M], int B[M][N]) {
  int i, j, ii, jj;
  int bsize = 8;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  int aset, bset;
  int tj1 = -1, tj2 = -1;
  int k;

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++) {
        for(j = jj; j < jj + bsize; j++) {
          aset = ((i*M + j)/8)%32;
          bset = ((j*N + i)/8)%32;
          if(bset == aset) {
            if(tj1 == -1)
              tj1 = j;
            else
              tj2 = j;
          } else
            transp(A, B, i, j);
        }

        if(tj1 != -1) {
          transp(A, B, i, tj1);
          tj1 = -1;
        }
        if(tj2 != -1) {
          transp(A, B, i, tj2);
          tj2 = -1;
        }
      }

  for(i = 0; i < M; i++)
    for(j = en; j < M; j++)
      transp(A, B, i, j);

  for(i = en; i < N; i++)
    for(j = 0; j < M; j++)
      transp(A, B, i, j);
}

int main() {
  int a[N][M], b[M][N];  int i, j;
  for(i = 0; i < N; i++)
    for(j = 0; j < M; j++)
      a[i][j] = i * N + j;  trans(a, b);
  printf("is_transposed: %d\n", is_transpose(a, b));
}