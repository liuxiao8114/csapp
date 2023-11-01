#include <stdio.h>
#include <stdlib.h>
#define MAXN 8

int *array;

int main() {
  int i, n;
  scanf("%d\n", &n);

  array = malloc(MAXN);

  for(i = 0; i < n; i++)
    array[i] = n;

  for(i = 0; i < n; i++)
    printf("array: %d\n", array[i]);
}
