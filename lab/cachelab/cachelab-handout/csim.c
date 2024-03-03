#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "cachelab.h"

#define ON  1
#define OFF 0
#define IGNORE -1
#define MAXLINE 1000

struct cline {
  unsigned tag;
  unsigned count;
  unsigned index;
};

static unsigned instruction_index = 0;

int phelp() {
  printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n");
  printf("Options:\n");
  printf("  -h         Print this help message.\n");
  printf("  -v         Optional verbose flag.\n");

  return 0;
}

int atoh(char *buf, char *isM) {
  int num = 0;

  while(*buf == ' ')
    buf++;

  if(*buf == 'I')
    return IGNORE;

  if(*buf++ == 'M')
    *isM = ON;
  else
    *isM = OFF;

  while(*buf == ' ')
    buf++;

  /*
    0:30(48) A:41(65) a:61( 97)
    9:39(57) Z:5A(90) z:7A(122)
  */
  char *p = buf;

  while(*p != ',') {
    if(*p >= 'A' && *p <= 'F') {
      num = num * 16 + (*p - 'A' + 10);
    }
    else if(*p >= 'a' && *p <= 'f') {
      num = num * 16 + (*p - 'a' + 10);
    }
    else if(*p >= '0' && *p <= '9') {
      num = num * 16 + (*p - '0');
    }
    else {
      printf("Invalid line: %s. For %s\n", buf, p);
      return IGNORE;
    }

    p++;
  }

  return num;
}

struct cline newCacheLine(int tag) {
  struct cline line;
  line.tag = tag;
  line.count = 1;
  line.index = instruction_index;

  return line;
}

void cacheSearch(struct cline *cacheline, int tag, int size, int *hcp, int *mcp, int *ecp, char verbose) {
  int l = 0;
  unsigned evictIndex = 0;
  struct cline *clp = cacheline;

  for(; l < size && clp->count > 0; l++, clp++) {
    // hit
    if(clp->tag == tag) {
      clp->count++;
      clp->index = instruction_index;
      *hcp = *hcp + 1;
      printf("hit");
      return;
    }

    if(clp->index < cacheline[evictIndex].index)
      evictIndex = l;
  }

  // miss && has room, init cacheline (miss)
  if(l < size && clp->count == 0) {
    *mcp = *mcp + 1;
    *clp = newCacheLine(tag);
    printf("miss");
  }
  // miss && no room, evict one(miss, evit)
  else if(l == size) {
    *mcp = *mcp + 1;
    *ecp = *ecp + 1;

    cacheline[evictIndex] = newCacheLine(tag);
    printf("miss, evict");
  }
}

int main(int argc, char* argv[]) {
  int hc, mc, ec;
  char c;
  int s, e, b;
  volatile int addr;

  char *buf = malloc(MAXLINE);
  char *filename = NULL;
  char verbose = OFF;
  char isM = OFF;

  if(argc == 1)
    return phelp();

  while((c = getopt(argc, argv, "hvs:E:b:t:")) != EOF) {
    switch (c) {
      case 'h':
        return phelp();
      case 'v':
        verbose = ON;
        break;
      case 'E':
        e = atoi(optarg);
        break;
      case 's':
        s = atoi(optarg);
        break;
      case 'b':
        b = atoi(optarg);
        break;
      case 't':
        filename = optarg;
        break;
      default:
        break;
    }
  }

  if(!s || !e || !b || filename == NULL) {
    printf("Too few arguments");
    return -1;
  }

  printf("s: %d\n", s);
  printf("e: %d\n", e);
  printf("b: %d\n", b);

  FILE *file = fopen(filename, "r");

  if(!file)
    perror(NULL);

  /*
    Cache size = 2 ^ (s + b) * E
    Instructions:
      I: Ignored
      S: Store(write once)
      L: Load(read once)
      M: Update(read once, write once)
  */
  struct cline **cache;

  cache = calloc((1 << (s-1)), sizeof(struct cline *));
  hc = mc = ec = 0;

  while(fgets(buf, MAXLINE, file) != NULL) {
    printf("read: %s", buf);
    addr = atoh(buf, &isM);

    if(addr == IGNORE)
      continue;

    int sno = (addr>>b) % (1<<s) - 1;
    int tag = addr>>(s+b);

    printf("addr:  %d\n", addr);
    printf("tag: 0x%x\n", tag);
    printf("set:   %d\n", sno);

    instruction_index++;

    // if the cacheset is empty, init <miss>
    if(cache[sno] == NULL) {
      cache[sno] = calloc(e, sizeof(struct cline));
      *cache[sno] = newCacheLine(tag);
      mc++;
      printf("miss");
    } else
      cacheSearch(cache[sno], tag, e, &hc, &mc, &ec, verbose);

    if(isM == ON) {
      hc++;
      printf(", hit\n\n");
    } else
      printf("\n\n");
  }

  printf("hc-mc-ec: %d-%d-%d\n", hc, mc, ec);
  // printSummary(hc, mc, ec);
  buf = NULL;
  filename = NULL;

  return 0;
}
