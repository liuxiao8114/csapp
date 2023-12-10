#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void end() {
  printf("2"); fflush(stdout);
}

int main() {
  if(fork() == 0)
    atexit(end);
  if(fork() == 0) {
    printf("0"); fflush(stdout);
  } else {
    printf("1"); fflush(stdout);
  }

  exit(0);
}

/*
        |
o ---- fork()
*/
