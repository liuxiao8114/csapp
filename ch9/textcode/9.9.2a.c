#include <stdio.h>
#include <stdlib.h>
#define MAXN 8

int array[MAXN];

int main() {
  int i, n;
  scanf("%d\n", &n);

  // if(n > MAXN)
  //   error("Input file too big");

  for(i = 0; i < n; i++)
    array[i] = n;

  for(i = 0; i < n; i++)
    printf("array: %d\n", array[i]);
}
