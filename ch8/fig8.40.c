/* 8.5.6 - Fig8.40 Using sigprocmask to synchronize processes */
void handler(int sig) {
  sigset_t mask_all, prev_all;
}

int main() {
  int pid;
  sigset_t mask_all, mask_one, prev_one;

  sigfillset(&mask_all);
  sigemptyset(&mask_one);
  sigaddset(&mask_one, SIGCHLD);
  signal(SIGCHLD, handler);
  initjobs();

  while(1) {
    sigprocmask(SIG_BLOCK, &mask_one, &prev_one);
    if((pid = fork()) == 0) {
      sigprocmask(SIG_SETMASK, &prev_one, NULL);
      execve("", argv, NULL);
    }
    addjob(pid);
    sigprocmask(SIG_SETMASK, &prev_one, NULL);
  }

  exit(0);
}
