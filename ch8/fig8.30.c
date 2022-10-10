#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
  printf("\nCaught SIGINT!\n");
  exit(0);
}

int main() {
  if(signal(SIGINT, sigint_handler) == SIG_ERR)
    perror("signal error");

  pause();
  return 0;
}
