void doit(int);

int main(int argc, char **argv) {
  char client_host[MAXLINE], client_port[MAXLINE];
  int listenfd, connfd;
  struct sockaddr_storage client_addr;
  socklen_t client_addrlen;

  if(argc != 2) {
    printf("Usage: <port>\n");
    exit(0);
  }

  listenfd = open_listenfd(argv[1]);
  while(1) {
    client_addrlen = sizeof(client_addr);
    connfd = accept(listenfd, (SA *)&client_addr, &client_addrlen);
    getnameinfo(
      (SA *)&client_addr,
      client_addrlen,
      client_host, MAXLINE, client_port, MAXLINE, 0
    );
    printf("Connected to (%s, %s)\n", client_host, client_port);
    doit(connfd);
    close(connfd);
  }

  exit(0);
}

void doit(int fd) {
  rio_t rio;

  rio_readinitb(&rio, fd);
  // first line
  rio_readlineb(&rio, buf, MAXLINE);
  sscanf(buf, "%s %s %s", method, url, version);

  if(strcasecmp(method, "GET")) {
    send_error(fd, method, "501", "short", "long");
    return;
  }

  read_requesthdrs(&rio);
  /* Parse URI from GET request */
  is_static = parse_uri(uri, filename, cgiargs);
  if(is_static) {
    serve_static();
  } else {
    serve_dynamic();
  }
}

void read_requesthdrs(rio_t *rio) {
  char buf[MAXLINE];

  rio_readlineb(rio, buf, MAXLINE);
  while(strcmp(buf, "\r\n")) {
    rio_readlineb(rio, buf, MAXLINE);
    printf("%s\n", buf);
  }
}

char parse_uri(char* uri, char* filename, char* cgiargs) {

}

void serve_static() {

}

void serve_dynamic() {

}
