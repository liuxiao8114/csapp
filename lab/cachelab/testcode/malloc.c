#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LINE 4

int ifArrToP(char *buf) {
  printf("%s\n", ++buf);
  printf("%s\n", ++buf);
}

int main() {
  char **cachep;
  char (*cachea)[LINE];

  cachep = calloc(2, LINE);
  cachea = calloc(2, LINE);

  *cachea[0] = 63;
  *cachea[1] = 65;
  *cachea[2] = 67;
  *cachea[3] = 69;

  printf("%d\n", **cachea);
  printf("%d\n", *(*cachea+1));
  printf("%d\n", *cachea[1]);
  printf("%d\n", *cachea[2]);
  printf("--------------\n");

  char buf[LINE];
  buf[0] = 'a';
  buf[1] = 'c';
  buf[2] = 'e';
  buf[3] = 'g';
  ifArrToP(buf);
  printf("--------------\n");

  char **pp =  calloc(8, 1);
  printf("0x%x\n", pp);
  printf("0x%x\n", pp + 1);
  printf("0x%x\n", pp + 2);
  printf("0x%x\n", pp + 3);
  printf("0x%x\n", pp[0]);
  printf("0x%x\n", pp[1]);
  printf("0x%x\n", pp[2]);
  printf("0x%x\n", pp[3]);
}
