#include <unistd.h>

extern char **environ;      /* defined in libc */

int main(int argc, char **argv) {
  execve("/bin/ls", argv, environ);
}
