// 10.6 Reading File Metadata
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
  struct stat filestat;

  if(argc == 1) {
    printf("<Usage>\n");
    return -1;
  }

  stat(argv[1], &filestat);
}
