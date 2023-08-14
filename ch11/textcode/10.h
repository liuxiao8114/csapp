#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define RIO_BUFSIZE 8192

typedef struct {
  int rio_fd;
  int rio_cnt;
  char *rio_bufptr;
  char rio_buf[RIO_BUFSIZE];
} rio_t;

void rio_readinitb(rio_t *, int fd);
size_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *, void *, size_t);
ssize_t rio_written(int fd, void *, size_t);
