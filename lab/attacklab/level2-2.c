#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 8
#define LIMIT 100

unsigned getbuf();
int get(char *, int);

int main(int argc, char *argv[]) {
  getbuf();
  return 0;
}

unsigned getbuf() {
  char buf[BUFFER_SIZE];
  int len = get(buf, LIMIT);
  printf("%3d: %s\n", len, buf);
  return 1;
}

int get(char *s, int len) {
  int c, i = 0;

  while(i < len - 1 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
    i++;
  }

  if(c == '\n') {
    *s++ = '\n';
    i++;
  }
  *s = '\0';

  return i;
}


// ./ ctarget
