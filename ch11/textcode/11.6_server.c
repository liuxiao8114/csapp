#include <fcntl.h>
#include <sys/stat.h>

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
  struct stat sbuf;

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
  if(stat(filename, &sbuf) < 0) {
    cilenterror();
    return;
  }

  if(is_static) {
    serve_static(fd, filename, sbuf.st_size);
  } else {
    serve_dynamic(filename, sbuf.st_size, cgiargs);
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
  char *ptr;

  if (!strstr(uri, "cgi-bin")) { /* Static content */
    strcpy(cgiargs, "");
    strcpy(filename, ".");
    strcat(filename, uri);

    if (uri[strlen(uri)-1] == '/')
      strcat(filename, "home.html");

    return 1;
  }
  else { /* Dynamic content */
    ptr = index(uri, '?');
    if (ptr) {
      strcpy(cgiargs, ptr + 1);
      *ptr = '\0';
    } else
      strcpy(cgiargs, "");

    strcpy(filename, ".");
    strcat(filename, uri);

    return 0;
  }
}

void serve_static(int fd, char *filename, int filesize) {
  int srcfd;
  char *srcp, filetype[MAXLINE];

  /* Send response headers to client */
  get_filetype(filename, filetype);
  srcfd = open(filename, O_RDONLY, 0);
  srcp = mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
  close(srcfd);
  rio_writen(fd, srcp, filesize);
  munmap(srcp, filesize);
}

void serve_dynamic(int fd, char *filename, char *cgiargs) {
  char buf[MAXLINE], *emptylist[] = { NULL };

  /* Return first part of HTTP response */
  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  rio_written(fd, buf, strlen(buf));
  sprintf(buf, "Server: Tiny Web Server\r\n");
  rio_written(fd, buf, strlen(buf));

  if (Fork() == 0) { /* Child */
    /* Real server would set all CGI vars here */
    setenv("QUERY_STRING", cgiargs, 1);
    dup2(fd, STDOUT_FILENO); /* Redirect stdout to client */
    execve(filename, emptylist, environ); /* Run CGI program */
  }

  wait(NULL); /* Parent waits for and reaps child */
}

/*
 * get_filetype - derive file type from file name
 */
void get_filetype(char *filename, char *filetype) {


}
