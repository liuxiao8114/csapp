/*
  Suppose we wanted to write a program
  that counts the number of lines in a text file.
*/
#include "./10.5.h"

int main(int argc, char **argv) {
  int n;
  rio_t rio;
  char buf[MAXLINE];

  rio_readinitb(&rio, STDIN_FILENO);
  while((n = rio_readlineb(&rio, buf, MAXLINE)) != 0)
    rio_written(STDOUT_FILENO, buf, n);
}

void rio_readinitb(rio_t *rp, int fd) {
  rp->rio_fd = fd;
  rp->rio_cnt = 0;
  rp->rio_bufptr = rp->rio_buf;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
  int cnt;

  while(rp->rio_cnt <= 0) {
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
    
    if(rp->rio_cnt == 0)
      return 0;
    else if(rp->rio_cnt < 0)
      if(errno != EINTR)
        return -1;
    else
      rp->rio_bufptr = rp->rio_buf;
  }

  cnt = n;
  if(rp->rio_cnt < n) {
    cnt = rp->rio_cnt;
  }

  memcpy(usrbuf, rp->bufptr, cnt);
  rp->rio_cnt -= cnt;
  rp->rio_bufptr += cnt;

  return cnt;
}

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen) {
  int n, rc;
  char c, *bufp = usrbuf;

  for(n = 1; n < maxlen; n++) {
    // read one
    if((rc = rio_read(rp, &c, 1)) == 1) {
      *bufp++ = c;
      if(c == '\n') {
        n++;
        break;
      }
    }
    else if(rc == 0) {
      // // empty file
      // if(n == 1) return 0;
      // // EOF
      // else break;
      break;
    }
    // error?
    else
      return -1;
  }

  *bufp = 0;
  return n - 1;
}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) {
  ssize_t nread;
  char *bufp = usrbuf;
  size_t nleft = n;

  while(nleft > 0) {
    if((nread = rio_read(rp, bufp, nleft)) < 0)
      return -1;
    else if(nread == 0)
      break;
    bufp += nread;
    nleft -= nread;
  }

  return (n - nleft);
}

ssize_t rio_written(int fd, void *usrbuf, size_t n) {

}
