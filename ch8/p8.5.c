#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int wakeup(unsigned int secs);

int main(int argc, char *argv[]) {
  int sec = 5;

  if(argc == 2 && strlen(*++argv) == 1) {
    char c = **argv;
    if(c >= '0' && c <= '9')
      sec = c - 48;
  }

  sleep(sec);
  printf("Woke up at %d secs.\n", sec);
}
