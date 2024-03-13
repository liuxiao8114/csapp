/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

char transpose_32_desc[] = "Transpose for 32";
void transpose_32(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, k, ii, jj;
  int bsize = 8;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++) {
        k = jj + i%bsize + 1;
        for(j = k; j < jj + bsize; j++)
          B[j][i] = A[i][j];

        for(j = jj; j < k; j++)
          B[j][i] = A[i][j];
      }

  for(i = ii; i < M; i++)
    for(j = jj; j < N; j++)
      B[j][i] = A[i][j];
}

char transpose_64_desc[] = "Transpose for 64";
void transpose_64(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, k, ii, jj;
  int bsize = 4;
  // int bsize = (1<<5) / sizeof(int);
  int en = (M <= N) ? (bsize * (M / bsize)) : (bsize * (N / bsize));

  for(ii = 0; ii < en; ii += bsize)
    for(jj = 0; jj < en; jj += bsize)
      for(i = ii; i < ii + bsize; i++) {
        k = jj + i%bsize + 1;
        for(j = k; j < jj + bsize; j++)
          B[j][i] = A[i][j];

        for(j = jj; j < k; j++)
          B[j][i] = A[i][j];
      }

  for(i = ii; i < M; i++)
    for(j = jj; j < N; j++)
      B[j][i] = A[i][j];
}

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
  // s: 5, E: 1, b: 5
  if(M == N && M == 32)
    transpose_32(M, N, A, B);
  else if(M == N && M == 64)
    transpose_64(M, N, A, B);
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    // registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
