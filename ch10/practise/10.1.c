#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int fd1, fd2, fd3;

  fd1 = open("foo.txt", O_RDONLY, 0);
  printf("fd1 = %d\n", fd1);
  close(fd1);

  fd2 = open("bar.txt", O_RDONLY, 0);
  printf("fd2 = %d\n", fd2);

  fd3 = open("foo.txt", O_RDONLY, 0);
  printf("fd3 = %d\n", fd3);

  exit(0);
}
