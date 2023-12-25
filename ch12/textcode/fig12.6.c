/* Figure 12.6 An iterative echo server that uses I/O multiplexing */
#include "12.h"

void command();

int main(int argc, char **argv) {
  int connfd, listenfd;
  fd_set read_set, ready_set;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;

  if(argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", *argv);
    exit(0);
  }

  listenfd = open_listenfd(argv[1]);

  FD_ZERO(&read_set);
  FD_SET(STDOUT_FILENO, &read_set);
  FD_SET(listenfd, &read_set);

  while(1) {
    ready_set = read_set;
    select(listenfd + 1, &ready_set, NULL, NULL, NULL);
    if(FD_ISSET(STDIN_FILENO, &ready_set)) {
      command();
    }

    if(FD_ISSET(listenfd, &ready_set)) {
      clientlen = sizeof(struct sockaddr_storage);
      connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
      echo(connfd);
      close(connfd);
    }
  }
}

void command() {
  char buf[MAXLINE];
  if (!fgets(buf, MAXLINE, STDIN_FILENO))
    exit(0); /* EOF */
  printf("read from commandline: %s", buf); /* Process the input command */
}
