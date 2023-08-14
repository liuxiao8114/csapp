#include "./10.h"

static ssize_t rio_read(rio_t *rp, void *usrbuf, size_t n);

static ssize_t rio_read(rio_t *rp, void *usrbuf, size_t n) {
  int cnt = n;

  while(rp->rio_cnt <= 0) {
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));

    if(rp->rio_cnt < 0) {
      if(errno != EINTR)
        return -1;
    }
    else if(rp->rio_cnt == 0)
      return 0;
    else
      rp->rio_bufptr = rp->rio_buf;
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

size_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen) {
  size_t n, rc;
  char c, *bufp = usrbuf;
  for(n = 1; n < maxlen; n++) {
    if((rc = rio_read(rp, &c, 1)) == 1) {
      *bufp++ = c;
      if(c == '\n') {
        n++;
        break;
      }
    } else if(rc == 0) {
      if(n == 1)
        return 0;
      break;
    } else
      return -1;
  }

  *bufp = 0;
  return n - 1;
}

ssize_t rio_written(int fd, void *usrbuf, size_t n) {
  size_t nleft = n;
  ssize_t nwritten;
  char *bufp = usrbuf;

  while(nleft > 0) {
    if((nwritten = write(fd, bufp, nleft)) < 0) {
      if(errno == EINTR)
        nwritten = 0;
      else
        return -1;
    }
    nleft -= nwritten;
    bufp += nwritten;
  }

  return n;
}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) {
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while(nleft > 0) {
    if((nread = rio_read(rp, bufp, nleft)) < 0)
      return -1;
    if(nread == 0)
      return 0;
    bufp += nread;
    nleft -= nread;
  }

  return n - nleft;
}
