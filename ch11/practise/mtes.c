#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {

  char* data = "Hello World";

  int fd = open("file.txt", O_RDWR | O_CREAT, 0644);

  write(fd, data, strlen(data));

  lseek(fd, 0, SEEK_SET); // Seek to end to position for read

  char buf[20];
  read(fd, buf, sizeof(buf));

  printf("Read: %s\n", buf);

  close(fd);

  return 0;
}
