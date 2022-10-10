// 8.4.3 reaping Child Processes
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N 2

// pid_t waitpid(pid_t pid, int *statusp, int options)
int main() {
  int status, i;
  pid_t pid;

  for(i = 0; i < N; i++)
    if((pid = fork()) == 0)
      exit(100 + i);

  while((pid = waitpid(-1, &status, 0)) > 0) {
    if(WIFEXITED(status))
      printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));
    else
      printf("child %d terminated abnormally\n", pid);
  }

  if(errno != ECHILD)
    perror("waitpid error");

  exit(0);
}
