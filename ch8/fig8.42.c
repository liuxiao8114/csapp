/* 8.5.7 - Fig8.41 Waiting for a signal with a spin loop */
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t pid;

void *Signal(int signum, void *handler)
{
  struct sigaction action, old_action;
  action.sa_handler = handler;
  action.sa_flags = SA_RESTART; /* Restart syscalls if possible */
  sigemptyset(&action.sa_mask); /* Block sigs of type being handled */

  if (sigaction(signum, &action, &old_action) < 0)
    perror("Signal error");
  return (old_action.sa_handler);
}

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

  Signal(SIGCHLD, sigchld_handler);
  Signal(SIGINT, sigint_handler);
  sigemptyset(&mask);
  sigaddset(&mask, SIGCHLD);

  while(1) {
    sigprocmask(SIG_BLOCK, &mask, &prev);    /* block SIGCHLD */
    if(fork() == 0) {
      sleep(1);
      printf("sleep end.\n");
      exit(0);
    }

    pid = 0;
    /* while-loop wait for SIGCHLD to be received which is wasteful*/
    while(!pid)
      sigsuspend(&prev);

    sigprocmask(SIG_SETMASK, &prev, NULL);  /* unblock SIGCHLD */
    /* Do some work after receiving SIGCHLD */
    printf("done.\n");
  }

  exit(0);
}
