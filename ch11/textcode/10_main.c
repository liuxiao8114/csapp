#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./10.h"
#define MAXLINE 1000

int main() {
  int n;
  char buf[MAXLINE] = "xxoo";
  char *output = malloc(MAXLINE);
  // rio_t rio;
  // size_t status;

  int clientfd = open("test", O_RDWR | O_APPEND, 0);

  if(clientfd < 0) {
    printf("ERROR: %s\n", strerror(errno));
    return -1;
  }

  int writeStatus = write(clientfd, buf, strlen(buf));
  lseek(clientfd, 0, SEEK_SET); // Seek to end
  int readStatus = read(clientfd, output, sizeof(output));
  while(*output) {
    if(*output == '\n')
      printf("\n");
    else
      printf("%x ", (unsigned int)*output);
    output++;
  }

  printf("\n");

  // rio_readinitb(&rio, clientfd);
  // rio_readinitb(&rio, STDIN_FILENO);
  // while((n = rio_readlineb(&rio, buf, MAXLINE)) > 0)
  //   rio_written(STDOUT_FILENO, buf, n);



  // while(fgets(buf, MAXLINE, stdin) != NULL) {
  //   // rio_written(clientfd, buf, strlen(buf));
  //
  // }

  // printf("output: %s\n", output);

  // while(fgets(buf, MAXLINE, stdin) != NULL) {
  //   rio_written(clientfd, buf, strlen(buf));
  //   read(clientfd, output, sizeof(output));
  //   // status = rio_readlineb(&rio, output, MAXLINE);
  //   //
  //   // if(status < 0) {
  //   //   printf("ERROR: %s\n", strerror(errno));
  //   //   return -1;
  //   // }
  //   //
  //   while(*output) {
  //     printf("%02x ", (unsigned int)*output);
  //     output++;
  //   }
  // }
}
