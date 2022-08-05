#include <stdio.h>
#define LEN 8

int src[LEN], dst[LEN];

int loopCount = 0;

int ncopy(int *src, int *dst, int len)
{
  int i, val;
  int count = 0;
  int k = 4;

  // for(i = len - k; i >= 0; i -= k) {
  //   val = src[i];
  //   dst[i] = val;
  //   if(val > 0)
  //     count++;
  //   loopCount++;
  // }

  for(i = len - k; i >= 0; i -= k) {
    val = src[i];
    dst[i] = val;
    if(val > 0) count++;

    val = src[i + 1];
    dst[i + 1] = val;
    if(val > 0) count++;
    val = src[i + 2];
    dst[i + 2] = val;
    if(val > 0) count++;
    val = src[i + 3];
    dst[i + 3] = val;
    if(val > 0) count++;
    // val = src[i + 4];
    // dst[i + 4] = val;
    // if(val > 0) count++;
    // val = src[i + 5];
    // dst[i + 5] = val;
    // if(val > 0) count++;

    loopCount++;
  }

  for(k += i - 1; k >= 0; k--) {
    val = src[k];
    dst[k] = val;
    if(val > 0) count++;
    loopCount++;
  }

  return count;
}
/* $end ncopy */

int main() {
  int i, count;

  for (i = 0; i < LEN; i++)
     src[i]= i + 1;
  count = ncopy(src, dst, LEN);
  for (i = 0; i < LEN; i++)
    printf ("%d ", dst[i]);
  printf ("\ncount = %d\n", count);
  printf ("loopCount = %d\n", loopCount);

  return 0;
}
