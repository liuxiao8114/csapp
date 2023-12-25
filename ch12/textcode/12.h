#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include <errno.h>
#include <unistd.h>
#include <string.h>

#define RIO_BUFSIZE 1000
#define MAXLINE 1000

typedef struct sockaddr SA;

typedef struct {
  int rio_fd;
  int rio_cnt;
  char *rio_bufptr;
  char rio_buf[RIO_BUFSIZE];
} rio_t;

int open_listenfd(char *port);
int open_clientfd(char *hostname, char *port);

void rio_readinitb(rio_t *, int fd);
size_t rio_readlineb(rio_t *, void *, size_t);
ssize_t rio_readnb(rio_t *, void *, size_t);
ssize_t rio_written(int, void *, size_t);

void echo(int);
