/* 8.5.7 - Fig8.41 Waiting for a signal with a spin loop */
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t pid;

void sigchld_handler(int s) {
  int olderrno = errno;
  pid = waitpid(-1, NULL, 0);
  errno = olderrno;
}

void sigint_handler(int s) {
  exit(0);
}

int main(int argc, char **argv) {
  sigset_t mask, prev;

  signal(SIGCHLD, sigchld_handler);
  signal(SIGINT, sigint_handler);
  sigemptyset(&mask);
  sigaddset(&mask, SIGCHLD);

  while(1) {
    sigprocmask(SIG_BLOCK, &mask, &prev);   /* block SIGCHLD */
    if(fork() == 0)
      exit(0);

    pid = 0;
    sigprocmask(SIG_SETMASK, &prev, NULL);  /* unblock SIGCHLD */

    /* while-loop wait for SIGCHLD to be received which is wasteful */
    while(!pid)
      ;
    /*
    while(!pid)
      pause();

    while(!pid)
      sleep(1);
    */

    /* Do some work after receiving SIGCHLD */
    printf("done.\n");
  }

  exit(0);
}
