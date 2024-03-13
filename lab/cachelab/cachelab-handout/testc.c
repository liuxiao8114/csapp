#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int atoh(char *s) {
  int ret = 0;

  for(; *s != '\0'; s++) {
    if(*s >= '0' && *s <= '9')
      ret = ret * 16 + *s - '0';
    else if((*s >= 'a' && *s <= 'f'))
      ret = ret * 16 + *s - 'a' + 10;
    else if((*s >= 'A' && *s <= 'F'))
      ret = ret * 16 + *s - 'A' + 10;
    else {
      printf("error s: %s\n", s);
      return -1;
    }
  }

  return ret;
}

void testMalloc(char *s) {
  if(s != NULL)
    printf("s is not NULL\n");
  else {
    s = malloc(20);
    strcpy(s, "01234567890123456789");
  }
}

int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                printf("A[%d][%d]=%d not equals B[%d][%d]=%d\n", i, j, A[i][j], j, i, B[j][i]);
                return 0;
            }
        }
    }

    return 1;
}

void trans(int M, int N, int A[N][M], int B[M][N]) {
  int i, j;

  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      B[j][i] = A[i][j];
}

/* 61 * 67 */
void trans_v1(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, k;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      B[j][i] = A[i][j];

    }
  }

}

// void bijk(array A, array B, array C, int n, int bsize)
// {
//   int i, j, k, kk, jj;
//   double sum;
//   int en = bsize * (n/bsize); /* Amount that fits evenly into blocks */
//
//   for (i = 0; i < n; i++)
//     for (j = 0; j < n; j++)
//       C[i][j] = 0.0;
//
//   for (kk = 0; kk < en; kk += bsize) {
//     for (jj = 0; jj < en; jj += bsize) {
//       for (i = 0; i < n; i++) {
//         for (j = jj; j < jj + bsize; j++) {
//           sum = C[i][j];
//
//           for (k = kk; k < kk + bsize; k++)
//             sum += A[i][k]*B[k][j];
//
//           C[i][j] = sum;
//         }
//       }
//     }
//   }
// }

void transpose_61(int M, int N, int A[N][M], int B[M][N]) {

}

/*
  5-1-5
  2^10 = 1024B L1-d
  int bsize = (1<<b) / sizeof(int)
  i = 0
    b[0,0] a[0,0] m, m  y-s00b0,x-s00b0
    b[1,0] a[0,1] m, h  y-s08b0,x-s00b1
    b[2,0] a[0,2] m, h  y-s16b0,x-s00b2
    b[3,0] a[0,3] m, h  y-s24b0,x-s00b3
  i = 1
    b[0,1] a[1,0] h, m  y-s00b1,x-s08b0
    b[1,1] a[1,1] h, h  y-s08b1,x-s08b1
    b[2,1] a[1,2] h, h  y-s16b1,x-s08b2
    b[3,1] a[1,3] h, h  y-s24b1,x-s08b3
  i = 2
    b[0,2] a[2,0] h, m  y-s00b2,x-s16b0
    b[1,2] a[2,1] h, h  y-s08b2,x-s16b1
    b[2,2] a[2,2] h, h  y-s16b2,x-s16b2
    b[3,2] a[2,3] h, h  y-s24b2,x-s16b3
  i = 3
    b[0,3] a[3,0] h, m  y-s00b1,x-s16b0
    b[1,3] a[3,1] h, h  y-s00b1,x-s16b1
    b[2,3] a[3,2] h, h  y-s00b1,x-s16b2
    b[3,3] a[3,3] h, h  y-s00b1,x-s16b3

  i = 0
    b[4,0] a[0,4] m, m  y-s00b0,x-s01b0
    b[5,0] a[0,5] m, h  y-s08b0,x-s01b1
    b[6,0] a[0,6] m, h  y-s16b0,x-s01b2
    b[7,0] a[0,7] m, h  y-s24b0,x-s01b3
  i = 1
    b[4,1] a[1,4] h, m
    b[5,1] a[1,5] h, h
    b[6,1] a[1,6] h, h
    b[7,1] a[1,7] h, h
  i = 2
    b[4,2] a[2,4] h, m
    b[5,2] a[2,5] h, h
    b[6,2] a[2,6] h, h
    b[7,2] a[2,7] h, h
  i = 3
    b[4,3] a[3,4] h, m
    b[5,3] a[3,5] h, h
    b[6,3] a[3,6] h, h
    b[7,3] a[3,7] h, h

    60 * 60
*/

void transpose_32_64(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, ii, jj;
  int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++)
        for(j = jj; j < jj + bsize; j++) {
          printf("b[%d][%d]=a[%d][%d]=%d\n", j, i, i, j, A[i][j]);
          B[j][i] = A[i][j];
        }

  printf("--------------------\n");
  for(i = ii; i < M; i++)
    for(j = jj; j < N; j++) {
      printf("b[%d][%d]=a[%d][%d]=%d\n", j, i, i, j, A[i][j]);
      B[j][i] = A[i][j];
    }
}

int main() {
  int m = 23;
  int n = 29;
  int a[n][m], b[m][n];

  int i, j;
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      a[i][j] = i * n + j;

  transpose_32_64(m, n, a, b);
  // trans(m, n, a, b);

  // for(j = 0; j < m; j++)
  //   for(i = 0; i < n; i++)
  //     printf("b[%d][%d]=%d\n", j, i, b[j][i]);
  /*
  // array and pointer set value.
  char c[10];
  char *s = c;
  *s++ = '1';
  *s++ = '1';
  *s = '\0';
  printf("%s\n", s);
  printf("%s\n", c);
  */

  /*
  // atoh
  printf("ff: 0x%d\n", atoh("ff"));
  printf("01: 0x%d\n", atoh("01"));
  printf("100: 0x%d\n", atoh("100"));
  */

  /* malloc
  // buffer overflow
  char **s = malloc(32);
  testMalloc(*s++);
  testMalloc(*s);

  printf("s0: %s, s1: %s\n", *s, *(s+1));
  return 1;

  // printf("%d\n", ~(-1 << 1));
  // printf("%d\n", ~(-1 << 3));
  // printf("%d\n", ~(-1 << 5));

  /*
  // sizeof struct
  struct char2 { char id; char counter; };
  struct charShort { char id; short counter; };
  struct charInt { char id; int counter; };
  struct charLong { char id; long counter; };
  struct charDouble { char id; double counter; };
  struct shortInt { short id; int counter; };
  struct int2 { int id; int counter; };
  struct intLong { int id; long counter; };

  printf("char2: %ld\n", sizeof(struct char2));
  printf("charShort: %ld\n", sizeof(struct charShort));
  printf("charInt: %ld\n", sizeof(struct charInt));
  printf("charLong: %ld\n", sizeof(struct charLong));
  printf("charDouble: %ld\n", sizeof(struct charDouble));
  printf("shortInt: %ld\n", sizeof(struct shortInt));
  printf("int2: %ld\n", sizeof(struct int2));
  printf("intLong: %ld\n", sizeof(struct intLong));

  */

  /* struct
  struct line {
    int id;
    int counter;
  } l1, l2, *ls;

  ls = (struct line *)malloc(1);

  l1.counter = 1;
  l2.counter = 2;
  *ls = l1;
  *(ls + 1) = l2;

  printf("%d\n", l1.counter);
  printf("%d\n", l2.counter);
  printf("%d\n", ls->counter);
  printf("%d\n", (ls+1)->counter);
  */
  /*

  */

  /*
  ttt   ss
  000   00
  000   01
  000   10
  000   11
  001   00
  ... 32 counts

  ttt   ss
        00  01  10  11
  000
  001
  010
  */

}
