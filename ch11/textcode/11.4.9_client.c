#include <stdio.h>
#include "./11.4.h"

int main(int argc, char **argv) {
  int clientfd;
  char *host, *port, buf[MAXLINE], output[MAXLINE];
  rio_t rio;

  if(argc != 3) {
    printf("ERROR client.\n");
    return -1;
  }

  host = argv[1];
  port = argv[2];

  clientfd = open_clientfd(host, port);
  rio_readinitb(&rio, clientfd);

  while(fgets(buf, MAXLINE, stdin) != NULL) {
    rio_written(clientfd, buf, strlen(buf));
    rio_readlineb(&rio, output, MAXLINE);
    fputs(output, stdout);
  }

  printf("Client side connection will close.");
  close(clientfd);
  exit(0);
}
