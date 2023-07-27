#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  DIR *streamp;
  struct dirent *dep;

  if(argc == 1) {
    printf("<Usage>\n");
    return -1;
  }

  streamp = opendir(argv[1]);

  if(streamp == NULL) {
    printf("Unknown DIR: %s\n", argv[1]);
    exit(-1);
  }

  errno = 0;
  while((dep = readdir(streamp)) != NULL)
    printf("Found file: %s\n", dep->d_name);

  /*
    the only way to distinguish an error from the end-of-stream condition is
    to check if errno has been modified since the call to readdir
  */
  if(errno != 0)
    perror("readdir error");

  closedir(streamp);
  exit(0);
}
