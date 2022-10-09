#include <stdio.h>
#include <stdlib.h>
#include "cachelab.h"

#define I 'I'
#define L 'L'
#define M 'M'
#define S 'S'
#define ADDR_LEN 16

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
  char isDebug = 0;
  int step = 2;

  if(argc <= 1) {
    printf("no trace.\n");
    return 0;
  }

  s = e = b = 1;
  hit = miss = evict = 0;

  for(++argv, --argc; argc > 0 && **argv == '-'; argc -= step, argv += step)
    while((c = *++*argv))
      switch (c) {
        case 's':
          s = atoi(*(argv + 1));
          step = 2;
          break;
        case 'E':
          e = atoi(*(argv + 1));
          step = 2;
          break;
        case 'b':
          b = atoi(*(argv + 1));
          step = 2;
          break;
        case 't':
          filename = *(argv + 1);
          step = 2;
          break;
        case 'v':
          isDebug = 1;
          step = 1;
          break;
        default:
          printf("[Error]: Unknown option: -%c\n", c);
          return -1;
      }

  // printf("S: %d, E: %d, B: %d\n", 1 << s, e, 1 << b);
  fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("[Error]: File not found: %s\n", filename);
    return -1;
  }

  int i, op, opIndex, memoryHex;
  struct line {
    int tag;
    int visitCounter;
    int lastVisit;
    // set blocks here if necessary.
  } *lines, *firstline, **cache;

  cache = calloc(1 << s, e * sizeof(struct line));
  opIndex = 0;

  while((c = fgetc(fp)) != EOF) {
    if(c == I)
      while((c = fgetc(fp)) != '\n' && c != EOF)
        ;
    else if(c == S || c == M || c == L) {
      fgetc(fp);  // skip the space
      op = c;     // save operation

      for(i = 0, c = fgetc(fp); c != EOF && c != ','; c = fgetc(fp))
        memory[i++] = c;

      memory[i] = '\0';
      memoryHex = atoh(memory);

      int tag = memoryHex >> (s + b);
      int setIndex = (~(-1 << (s + b)) & memoryHex) >> b;
      // int offset = memoryHex & ~(-1 << b);

      if((firstline = lines = cache[setIndex])) {
        for(; lines->visitCounter && lines-firstline < e; lines++) {
          if(lines->tag == tag) {
            if(isDebug) printf("hit");

            hit++;
            if(op == M) {
              hit++;
              if(isDebug) printf(" hit");
            }

            if(isDebug) printf("\n");
            lines->visitCounter++;
            lines->lastVisit = opIndex++;
            break;
          }
        }

        // Line Replacement on Misses in Set Associative Caches
        if(!lines->visitCounter) {
          if(isDebug) printf("miss");
          miss++;

          struct line l;
          l.tag = tag;
          l.visitCounter = 1;
          l.lastVisit = opIndex++;

          // if there is an empty line, then it would be a good candidate
          if(lines - firstline < e)
            *lines = l;
          // otherwise, evict with LRU(Least Recently Used)
          else {
            struct line *candicate = --lines;
            for(; lines >= firstline; lines--)
              if(lines->lastVisit < candicate->lastVisit)
                candicate = lines;
            /*
            // LFU(Least Frequently Used) version:
            for(; lines != firstline; lines--)
              if(lines->visitCounter < candicate->visitCounter)
                candicate = lines;
            */

            *candicate = l;
            evict++;

            if(isDebug) printf(" eviction(set%d line%ld)", setIndex, candicate-firstline);
          }

          if(op == M) {
            hit++;
            if(isDebug) printf(" hit");
          }

          if(isDebug) printf("\n");
        }
      }
      // Not Init Set(cold miss)
      else {
        if(isDebug) printf("miss(init set%d)", setIndex);
        miss++;

        if(op == M) {
          hit++;
          if(isDebug) printf(" hit");
        }

        lines = malloc(e * sizeof(struct line));
        struct line l;
        l.tag = tag;
        l.visitCounter = 1;
        l.lastVisit = opIndex++;
        *lines = l;
        cache[setIndex] = lines;

        if(isDebug) printf("\n");
      }
    }
  }

  printSummary(hit, miss, evict);
  return 0;
}
