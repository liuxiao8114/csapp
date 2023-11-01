/* Figure 12.6 An iterative echo server that uses I/O multiplexing */
int main(int argc, char **argv) {
  int connfd, listenfd;
  fd_set read_set, ready_set;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;

  if(argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", *argv);
  }

  listenfd = open_listenfd(argv[1]);
  FD_ZERO(&read_set);
  FD_SET(STDOUT_FILENO, &read_set);
  FD_SET(listenfd, &read_set);

  while(1) {
    ready_set = read_set;
    select(listenfd + 1, &read_set, NULL, NULL, NULL);
    if(FD_ISSET(STDOUT_FILENO, &ready_set))
      command();
    if(FD_ISSET(listenfd, &ready_set)) {
      clientlen = sizeof(clientaddr);
      connfd = accept(listenfd, (SA *)client_addr, client_addrlen);
      echo(connfd);
      close(connfd);
    }
  }
}

void command() {
  char buf[MAXLINE];
  if (!fgets(buf, MAXLINE, stdin))
    exit(0); /* EOF */
  printf("%s", buf); /* Process the input command */
}
