#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define DEL_TIMER 5

static int timer = DEL_TIMER;
static int slept = 0;

void sigint_handler(int sig) {
  return;
}

int main(int argc, char *argv[]) {
  if(argv[1] != NULL)
    timer = atoi(argv[1]);

  if(signal(SIGINT, sigint_handler) == SIG_ERR)
    perror("signal error");

  slept = sleep(timer);
  printf("slept for %d of %d secs.\n", timer-slept, timer);
  return 0;
}
