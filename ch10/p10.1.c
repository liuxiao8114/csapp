#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd1, fd2;

  fd1 = open("p10.1foo", O_RDONLY, 0);
  close(fd1);
  fd2 = open("p10.1baz", O_RDONLY, 0);
  printf("fd2 = %d\n", fd2);
}
