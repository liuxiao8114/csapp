#include <stdio.h>
#define LEN 64

int loopCount;

int ncopy(int *src, int *dst, int len)
{
  int i, val;
  int count = 0;
  int k = 8;
  int subK = 3;
  loopCount = 0;

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
    val = src[i + 4];
    dst[i + 4] = val;
    if(val > 0) count++;
    val = src[i + 5];
    dst[i + 5] = val;
    if(val > 0) count++;
    val = src[i + 6];
    dst[i + 6] = val;
    if(val > 0) count++;
    val = src[i + 7];
    dst[i + 7] = val;
    if(val > 0) count++;
    val = src[i + 8];

    loopCount++;
  }

  for(i = k + i - subK; i >= 0; i -= subK) {
    val = src[i];
    dst[i] = val;
    if(val > 0) count++;

    val = src[i + 1];
    dst[i + 1] = val;
    if(val > 0) count++;
    val = src[i + 2];
    dst[i + 2] = val;
    if(val > 0) count++;

    loopCount++;
  }

  for(subK += i - 1; subK >= 0; subK--) {
    val = src[subK];
    dst[subK] = val;
    if(val > 0) count++;
    loopCount++;
  }

  // printf("K is: %d\n", k + i - 1);
  // printf("K is: %d\n", k + i - subK);
  //
  //
  // for(k += i - 1; k >= 0; k--) {
  //   val = src[k];
  //   dst[k] = val;
  //   if(val > 0) count++;
  //   loopCount++;
  // }

  return count;
}
/* $end ncopy */

int main() {
  int i, count;
  int len;

  for(len = 0; len < LEN; len++) {
    printf("len: %d\n", len);
    int src[len], dst[len];

    for (i = 0; i < len; i++)
       src[i]= i + 1;
    count = ncopy(src, dst, len);
    for (i = 0; i < len; i++)
      printf ("%d ", dst[i]);
    printf ("\t\t\ncount = %d\n", count);
    printf ("\t\tloopCount = %d\n", loopCount);
    printf ("--------------------------------\n");
  }

  return 0;
}
