// Fig8.36 signal1.
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAXBUF 100

ssize_t sio_puts(char s[]) {
  return write(STDOUT_FILENO, s, strlen(s));
}

void handler1(int sig) {
  int olderrno = errno;

  if(waitpid(-1, NULL, 0) < 0)
    perror("waitpid error");
  sio_puts("Handler reaped child\n");
  sleep(1);
  errno = olderrno;
}

void handler2(int sig) {
  int olderrno = errno;

  while(waitpid(-1, NULL, 0) > 0)
    sio_puts("Handler reaped child\n");

  if(errno != ECHILD)
    perror("waitpid error");
  sleep(1);
  errno = olderrno;
}

int main() {
  int i, n;
  char buf[MAXBUF];

  if(signal(SIGCHLD, handler1) == SIG_ERR)
    perror("signal error");

  for(i = 0; i < 3; i++)
    if(fork() == 0) {
      printf("Hello from child %d\n", (int)getpid());
      exit(0);
    }

  if((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
    perror("read");

  printf("Parent processing input\n");
  while(1)
    ;
  exit(0);
}
