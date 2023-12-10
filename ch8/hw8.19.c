#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void foo(int n)
{
  int i;
  for (i = n - 1; i >= 0; i -= 2)
    fork();
  printf("hello\n");
  exit(0);
}

int main() {
  foo(6);
}

/*
main - fork1 - fork11 - fork111
             - fork12
     - fork2 - fork21
     - fork3

each nodes will print once, so 8 times.
*/
