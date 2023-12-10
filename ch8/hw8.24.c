#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define N 4

int main() {
  // psignal(SIGINT, "child ");
  int i, wstatus;
  ssize_t nwritten;
  pid_t pid;
  char *s;
  int fd = open("hw8.24.txt", O_RDONLY, 0);
  const char* CONTENT = "write content";

  printf("fd: %d\n", fd);
  if(fd < 0) {
    perror("open() error");
    exit(-1);
  }

  for(i = 0; i < N; i++) {
    if((pid = fork()) == 0) {
      if((nwritten = write(fd, CONTENT, N)) <= 0) {
        perror("write() error");
        if(errno != EINTR)
          exit(-1);
      }
      exit(100+i);
    }
  }

  while((pid = waitpid(-1, &wstatus, 0)) > 0) {
    if (WIFEXITED(wstatus))
      printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(wstatus));
    else {
      sprintf(s, "child %d terminated by signal ", pid);
      fflush(stdout);
      psignal(WTERMSIG(wstatus), s);
    }
  }

  if(errno != ECHILD)
    perror("waitpid error.");

  exit(0);
}
