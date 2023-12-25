#include "12.h"

#define LISTENQ 1024

static ssize_t rio_read(rio_t *, void *, size_t);

static ssize_t rio_read(rio_t *rp, void *usrbuf, size_t n) {
  ssize_t cnt = n;

  while(rp->rio_cnt <= 0) {
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));

    if(rp->rio_cnt < 0) {
      if(errno != EINTR)
        return -1;
    }
    else if(rp->rio_cnt == 0) {
      return 0;
    }
    else {
      rp->rio_bufptr = rp->rio_buf;
    }
  }

  if(rp->rio_cnt < n)
    cnt = rp->rio_cnt;

  memcpy(usrbuf, rp->rio_bufptr, cnt);
  rp->rio_bufptr += cnt;
  rp->rio_cnt -= cnt;

  return cnt;
}

void rio_readinitb(rio_t *rio, int fd) {
  rio->rio_fd = fd;
  rio->rio_cnt = 0;
  rio->rio_bufptr = rio->rio_buf;
}

size_t rio_readlineb(rio_t *rio, void *buf, size_t maxlen) {
  size_t n, rc;
  char c, *bufp = buf;

  for(n = 1; n < maxlen; n++) {
    if((rc = rio_read(rio, &c, 1)) == 1) {
      *bufp++ = c;
      if(c == '\n') {
        n++;
        break;
      }
    }
    else if(rc == 0) {
      if(n == 1)
        return 0;
      break;
    }
    else
      return -1;
  }

  *bufp = 0;
  return n - 1;
}

ssize_t rio_readnb(rio_t *rio, void *buf, size_t n) {
  size_t nleft = n;
  ssize_t nread;
  char *bufp = buf;

  while(nleft > 0) {
    if((nread = rio_read(rio, bufp, nleft)) < 0)
      return -1;
    if(nread == 0)
      return 0;

    bufp += nread;
    nleft -= nread;
  }

  return n - nleft;
}

ssize_t rio_written(int fd, void *buf, size_t n) {
  size_t nleft = n;
  char *bufp = buf;
  ssize_t rc;

  while(nleft > 0) {
    rc = write(fd, bufp, nleft);
    if(rc < 0) {
      return -1;
    }

    bufp += rc;
    nleft -= rc;
  }

  return n - nleft;
}

int open_clientfd(char *hostname, char *port) {
  int clientfd;
  struct addrinfo hints, *listp, *p;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_ADDRCONFIG;
  hints.ai_flags |= AI_NUMERICSERV;
  getaddrinfo(hostname, port, &hints, &listp);

  for(p = listp; p; p = p->ai_next) {
    if((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
      continue;
    if(connect(clientfd, p->ai_addr, p->ai_addrlen) == 0)
      break;
    close(clientfd);
  }

  freeaddrinfo(listp);
  if(!p)
    return -1;
  return clientfd;
}

int open_listenfd(char *port) {
  int listenfd;
  struct addrinfo hints, *listp, *p;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
  hints.ai_flags |= AI_NUMERICSERV;
  getaddrinfo(NULL, port, &hints, &listp);

  for(p = listp; p; p = p->ai_next) {
    if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
      continue;
    if(bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
      break;
    close(listenfd);
  }

  freeaddrinfo(listp);
  if(!p)
    return -1;
  if(listen(listenfd, LISTENQ) < 0) {
    close(listenfd);
    return -1;
  }

  return listenfd;
}

void echo(int connfd) {
  size_t n;
  char buf[MAXLINE];
  rio_t rio;

  rio_readinitb(&rio, connfd);
  while((n = rio_readlineb(&rio, buf, MAXLINE)) > 0) {
    printf("server received: %s", buf);
    rio_written(connfd, buf, n);
  }
}
