#include <stdio.h>

#define COUNT 10

/* Bubble sort: Array version */
void bubble_a(long *data, long count) {
  long i, last;
  for (last = count - 1; last > 0; last--) {
    for (i = 0; i < last; i++) 
      if (data[i + 1] < data[i]) {
      /* Swap adjacent elements */
        long t = data[i + 1];
        data[i + 1] = data[i];
        data[i] = t;
      }
  }
}

/* A. References the array elements with pointers, rather than using array indexing */
void bubble_b(long *data, long count) {
  long *start, *end;

  for(end = data + count - 1; end > data; end--) {
    for (start = data; start < end; start++)
      if (*(start + 1) < *start) {
        long t = *start;
        *start = *(start + 1);
        *(start + 1) = t;
      }
  }
}

/* B. Write and test a Y86-64 program consisting of the function and test code */
int main() {
  long a[COUNT] = { 9, 3, 8, 2, 7, 5, 6, 0, 4, 1 };
  printf("before: ");
  for(long *i = a; i != a + COUNT; i++)
    printf("%ld, ", *i);

  bubble_b(a, COUNT);
  
  printf("\n after: ");
  for (long *i = a; i != a + COUNT; i++)
    printf("%ld, ", *i);

  printf("\n");
  return 0;
}