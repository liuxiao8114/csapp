#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  char c;

  while(read(STDIN_FILENO, &c, 1) != 0)
    write(STDOUT_FILENO, &c, 1);
  exit(0);
}
