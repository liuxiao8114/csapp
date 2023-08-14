#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

long strtolre(char *s, char **err, int base);

int main(int argc, char **argv) {
  char *err;
  printf("atoi results %ld\n", strtolre(argv[1], &err, 16));
  printf("isError: %s\n", err);
}

long strtolre(char *s, char **err, int base) {
  long l = 0;
  char *p;

  for(p = s; p != NULL; p++) {
    if(*p > 0x2f && *p < 0x3a)
      l = l * 10 + (*p - 48);
    else if (!*p)
      break;
    else {
      *err = p;
      return 0;
    }
  }

  return l;
}
