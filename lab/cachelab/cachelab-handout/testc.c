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

void transpose_32_64(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, k, ii, jj;
  int bsize = 5;
  int en = bsize * (M / bsize); // assume M == N

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++)
        for(j = jj; j < jj + bsize; j++) {
          printf("b[%d][%d]=a[%d][%d]=%d\n", j, i, i, j, A[i][j]);
          B[j][i] = A[i][j];
        }

  for(i = ii - bsize; i < M; i++)
    for(j = jj - bsize; j < N; j++) {
      printf("b[%d][%d]=a[%d][%d]=%d\n", j, i, i, j, A[i][j]);
      B[j][i] = A[i][j];
    }
}

int main() {
  int m = 8;
  int n = 8;
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

  // calloc and malloc
  int *sc = calloc(4, sizeof(int));
  int *sm = malloc(4* sizeof(int));
  if(sc)
    printf("sc: %d\n", *sc); // print 0
  if(sm)
    printf("sm: %d\n", *sm); // print 0

  if(sc + 1)
    printf("sc: %d\n", *(sc+1)); // print 0
  if(sm + 1)
    printf("sm: %d\n", *(sm+1)); // print 0
  */
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
