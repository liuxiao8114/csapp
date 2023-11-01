#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define MAXJOBS 100
#define MAXLINE 1000

struct job_t {
  int pid;
  int jid;
  int state;
  char cmdname[MAXLINE];
} *jobs;

void initjobs() {
  jobs = (struct job_t *) malloc(sizeof(struct job_t) * MAXJOBS);
}

void addjob(int pid) {
  struct job_t j = malloc(sizeof(job_t));
}

void deletejob() {

}

void handler(int sig) {
  int olderrno = errno;
  sigset_t mask_all, prev_all;
  pid_t pid;

  sigfillset(&mask_all);
  while((pid = waitpid(-1, NULL, 0)) > 0) {
    sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
    deletejob(pid);
    sigprocmask(SIG_SETMASK, &prev_all, NULL);
  }

  if(errno != ECHILD)
    perror("waitpid error");
  errno = olderrno;
}

int main(int argc, char **argv) {
  int pid;
  sigset_t mask_all, prev_all;

  sigfillset(&mask_all);
  signal(SIGCHLD, handler);
  initjobs();

  while(1) {
    if((pid = fork()) == 0)
      execve("/bin/date", argv, NULL);
    sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
    addjob(pid);
    sigprocmask(SIG_SETMASK, &prev_all, NULL);
  }

  exit(0);
}
