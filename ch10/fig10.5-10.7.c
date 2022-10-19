#include <unistd.h>
#include <errno.h>

#define RIO_BUFSIZE 8192

typedef struct {
  int rio_fd;
  int rio_cnt;
  char *rio_bufptr;
  char rio_buf[RIO_BUFSIZE];
} rio_t;

void rio_readinitb(rio_t *rp, int fd) {
  rp->rio_fd = fd;
  rp->rio_cnt = 0;
  rp->rio_bufptr = rp->rio_buf;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
  int cnt;

  while(rp->cnt <= 0) {
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));

    if(rp->rio_cnt < 0)
      if(errno != EINTR)
        return -1;
    else if(rp->rio_cnt == 0)
      return 0;
    else
      rp->rio_bufptr = rp->rio_buf;
  }

  cnt = n;
  if(rp->rio_cnt <= n)
    cnt = rp->rio_cnt;

  memcpy(usrbuf, rp->rio_bufptr, cnt);

  rp->rio_bufptr += cnt;
  rp->rio_cnt -= cnt;

  return cnt;
}

/*
  rio_readlineb:
  rio_readnb:
    can be interleaved on the same descriptor
    should not be interleaved with calls to the unbuffered rio_readn function

    rio_readnb has the same
*/
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxline) {
  int n;
  char c;

  while() {
    rio_read(rp, usrbuf, )
  }

}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) {
  size_t nleft = n;
  char *bufp = usrbuf;

  while(nleft > 0) {
    nleft = rio_read(rp->fd, bufp, n);

    if(nleft < 0)
      if(errno == EINTR)
        nleft = 0;
      else
        return -1;
    else if(nleft == 0)

  }

  return;
}

int main(int argc, char **argv) {
  int n;
  rio_t rio;
  char buf[MAXLINE];

  rio_readlineb();

}
