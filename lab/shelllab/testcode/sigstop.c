#include <stdio.h>
#include <sys/wait.h>


void sigchld_handler(int sig) {
  printf("child sig stop or terminated.\n");
}

int main() {
  pid_t pid;

  if((pid = fork()) == 0) {
    printf("child\n");
    kill(-pid, SIGSTOP);
    exit(0);
  }

  waitpid(-pid, NULL, 0);
  printf("main\n");
  exit(0);
}
