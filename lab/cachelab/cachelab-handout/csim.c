#include <stdio.h>
#include <stdlib.h>
#include "cachelab.h"

#define I 'I'
#define L 'L'
#define M 'M'
#define S 'S'
#define ADDR_LEN 8

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

int main(int argc, char* argv[]) {
  int c;
  int s, e, b;
  char* filename;
  FILE* fp;
  int hit, miss, evict;
  char memory[ADDR_LEN];

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
  // char (*cache)[b] = malloc((1 << s) * e);
  char **cache = malloc(1 << s);

  fp = fopen(filename, "r");
  hit = miss = evict = 0;

  while((c = fgetc(fp)) != EOF) {
    if(c == I)
      while((c = fgetc(fp)) != '\n' || c != EOF)
        ;
    else if(c == S || c == M || c == L) {
      int i, memoryHex;
      fgetc(fp); // skip the space

      for(i = 0, c = fgetc(fp); c != EOF && c != ','; c = fgetc(fp))
        memory[i++] = c;

      memory[i] = '\0';
      memoryHex = atoh(memory);

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

      // convert to two-direction array.
      int tagIndex = memoryHex >> (s + b);
      int setIndex = (~(~0 << (s + b)) & memoryHex) >> b;
      int index = tagIndex * setIndex + setIndex;
      */

      int tagIndex = memoryHex >> (s + b);
      int setIndex = ((~(~0 << (s + b)) & memoryHex) >> b);

      // if(setIndex >= (1 << s))
      //   setIndex /= 1 << s;

      int index = tagIndex * setIndex + setIndex;

      if(cache[setIndex])
        hit++;
      else {
        miss++;
      }

      printf("memory: %s, memoryHex: %d\n", memory, memoryHex);
      printf("memoryHex: %d, tag: %d, set: %d, cache: %s\n",
        memoryHex, tagIndex, setIndex, cache[tagIndex * setIndex]);

    }
  }

  printSummary(hit, miss, evict);
  return 0;
}
