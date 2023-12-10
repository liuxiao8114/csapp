#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#define N 4

int main() {
  int i, wstatus;
  pid_t pid;

  for(i = 0; i < N; i++)
    if((pid = fork()) == 0)
      exit(100+i);

  while((pid = waitpid(-1, &wstatus, 0)) > 0) {
    if (WIFEXITED(wstatus))
      printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(wstatus));
    else
      printf("child %d terminated abnormally\n", pid);
  }

  if(errno != ECHILD)
    perror("waitpid error.");

  exit(0);
}
