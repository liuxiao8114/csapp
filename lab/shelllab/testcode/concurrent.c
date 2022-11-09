#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

volatile static int timer = 1;
static int jobs[100];
volatile int nextjid = 1;

void addjob(int *jobs) {
  jobs[nextjid] = jobs[nextjid - 1] + 1;
  nextjid++;
}

void deletejob(int *jobs) {
  jobs[nextjid--] = 0;
}

void sigchld_handler(int sig) {
  timer++;
  addjob(jobs);
  printf("sigchld handler\n");
}

int main(int argc, char **argv) {
  pid_t pid;

  jobs[0] = 100;
  signal(SIGCHLD, sigchld_handler);

  if((pid = fork()) == 0) {
    printf("child over\n");
    exit(0);
  }

  while(waitpid(-1, NULL, 0) > 0)
    ;

  timer--;
  printf("parent over\n");
  printf("timer: %d\n", timer);
  printf("nextjid: %d, jobs[nextjid - 1]: %d, jobs[nextjid]: %d\n",
    nextjid, jobs[nextjid - 1], jobs[nextjid]);
  fflush(stdout);

  return 0;
}
