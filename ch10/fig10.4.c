#include <unistd.h>
#include <errno.h>

/* 10.5.1 RIO Unbuffered Input and Output Functions */
/* Fig10.4 The rio_readn and rio_writen functions */
ssize_t rio_readn(int fd, void *usrbuf, size_t n) {
  size_t nleft = n;
  ssize_t nread;
  char *bufp = usrbuf;

  while(nleft > 0) {
    if((nread = read(fd, bufp, nleft)) < 0) {
      if(errno == EINTR)  /* Interrupted by sig */
        nread = 0;        /* call read() again */
      else
        return -1;        /* errno set by read() */
    } else if(nread == 0) /* meet EOF */
      break;

    nleft -= nread;
    bufp += nread;
  }

  return (n - nleft);
}

ssize_t rio_writen(int fd, void *usrbuf, size_t n) {
  size_t nleft = n;
  ssize_t nwriten;
  char *bufp = usrbuf;

  while(nleft > 0) {
    if((nwriten = writen(fd, bufp, nleft)) <= 0) {
      if(errno == EINTR)
        nwriten = 0;
      else
        return -1;
    }

    nleft -= nwriten;
    bufp += nwriten;
  }

  return n;
}
