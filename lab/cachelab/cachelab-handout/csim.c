#include <stdio.h>
#include <stdlib.h>
#include "cachelab.h"

#define I 'I'
#define L 'L'
#define M 'M'
#define S 'S'
#define ADDR_LEN 8

int main(int argc, char* argv[]) {
  int c;
  int s, e, b;
  char* filename;
  FILE* fp;
  int hit, miss, evict;
  char addr[ADDR_LEN];

  if(argc <= 1) {
    printf("no trace.\n");
    return 0;
  }

  s = e = b = 1;

  for(++argv, --argc; argc > 0 && **argv == '-'; argc -= 2, argv += 2)
    while((c = *++*argv))
      switch (c) {
        case 's':
          s = atoi(*(argv + 1));
          break;
        case 'E':
          e = atoi(*(argv + 1));
          break;
        case 'b':
          b = atoi(*(argv + 1));
          break;
        case 't':
          filename = *(argv + 1);
          break;
        default:
          printf("fuck this: %c\n", c);
          return 0;
      }

  printf("S: %d, E: %d, B: %d\n", 1 << s, e, 1 << b);
  char cache[s][e][b];

  fp = fopen(filename, "r");
  hit = miss = evict = 0;

  while((c = fgetc(fp)) != EOF) {
    if(c == I)
      while((c = fgetc(fp)) != '\n' || c != EOF)
        ;
    else if(c == S || c == M || c == L) {
      int i = 0;
      for(fgetc(fp); c != EOF && c != ','; c = fgetc(fp))
        addr[i++] = c;
      addr[i] = '\0';
    }
  }

  printSummary(hit, miss, evict);
  return 0;
}
