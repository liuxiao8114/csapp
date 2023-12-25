#include "12.h"

int main(int argc, char *argv[]) {
  char *hostname, *port, buf[MAXLINE];
  rio_t rio;
  int clientfd;

  if(argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(0);
  }

  hostname = argv[1];
  port = argv[2];

  clientfd = open_clientfd(hostname, port);
  rio_readinitb(&rio, clientfd);

  while(fgets(buf, MAXLINE, stdin) != NULL) {
    rio_written(clientfd, buf, strlen(buf));
    rio_readlineb(&rio, buf, MAXLINE);
    fputs(buf, stdout);
    // fflush(stdout);
  }
}
