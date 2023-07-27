#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RIO_BUFSIZE 8192
#define MAXLINE 1000

typedef struct {
  int rio_fd; /* Descriptor for this internal buf */
  int rio_cnt; /* Unread bytes in internal buf */
  char *rio_bufptr; /* Next unread byte in internal buf */
  char rio_buf[RIO_BUFSIZE]; /* Internal buffer */
} rio_t;

// 10.5.1 Rio Unbuffered Input and Output Functions
ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_written(int fd, void *usrbuf, size_t n);

// 10.5.2 Rio Buffered Input Functions
void rio_readinitb(rio_t *rp, int fd);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);
